#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 50, mod = (int)1e9 + 7;
typedef long long ll;

int n, k;
ll l;
int num[N], a[N];
ll dp[2][N], pdp[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> k;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        a[i] = num[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) num[i] = (int)(lower_bound(a, a + n, num[i]) - a);

    ll res = l % mod;
    int la = 1, nw = 0;
    for(int i = 0; i < n; i++) dp[nw][num[i]] ++;
    for(int i = 0; i < n; i++) pdp[nw][i] = (i == 0 ? 0 : pdp[nw][i-1]) + dp[nw][i];
    for(ll len = 2; len <= k; len++) {
        swap(nw, la);
        fill(dp[nw], dp[nw] + n, 0);
        fill(pdp[nw], pdp[nw] + n, 0);

        if(l % n != 0 && len <= l / n + 1) {
            ll rem = l % n;
            for(int i = 0; i < rem; i++) res += pdp[la][num[i]], res %= mod;
        }
        if(len <= l / n) {
            for(int i = 0; i < n; i++) {
                ll add = pdp[la][num[i]];
                res += add * ((l / n - len + 1) % mod) % mod; res %= mod;
                dp[nw][num[i]] += add;
                dp[nw][num[i]] %= mod;
            }
            for(int i = 0; i < n; i++) {
                pdp[nw][i] = (i == 0 ? 0 : pdp[nw][i-1]) + dp[nw][i];
                pdp[nw][i] %= mod;
            }
        }
    }
    cout << (res % mod + mod) % mod << endl;
}