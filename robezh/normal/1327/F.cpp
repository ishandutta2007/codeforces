#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 50, mod = 998244353, INF = (int)1e9 + 50;
typedef long long ll;

int n, k, m;
ll dp[N], psum[N];
int l[N], r[N], x[N];
int add[N];
int lb[N];
ll res = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> m;
    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> x[i];
    }
    for(int b = 0; b < k; b++) {
        memset(add, 0, sizeof(add));
        fill(lb, lb + N, -1);
        for(int i = 0; i < m; i++) {
            if((x[i] >> b) & 1) {
                add[l[i]]++;
                add[r[i] + 1]--;
            }
            else {
                lb[r[i]] = max(lb[r[i]], l[i]);
            }
        }
        fill(dp, dp + N, 0);
        dp[0] = psum[0] = 1;
        int lp = 0;
        int cur_seg = 0;
        for(int i = 1; i <= n; i++) {
            cur_seg += add[i];
            if(cur_seg == 0) dp[i] = (psum[i - 1] - (lp == 0 ? 0 : psum[lp - 1])) % mod;
            else dp[i] = 0;
            psum[i] = (psum[i-1] + dp[i]) % mod;
            lp = max(lp, lb[i]);
        }

        res *= (psum[n] - (lp == 0 ? 0 : psum[lp - 1])) % mod;
        res %= mod;
    }
    cout << (res + mod) % mod << '\n';
}