#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005, mod = 998244353, M = (int)1e5 + 50;

int n, k;
int a[N];
int dp[N][N], psum[N][N];
int pv[N];
int res[M];

void add(int &to, int x) {
    to += x;
    if(to >= mod) to -= mod;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    ll fres = 0;
    for(int gap = (int)1e5 / (k - 1); gap >= 0; gap--) {
        int l = -1;
        for(int i = 0; i < n; i++) {
            while(l + 1 < i && a[l + 1] + gap <= a[i]) l++;
            pv[i] = l;
        }
        for(int i = 0; i <= k; i++) {
            memset(dp[i], 0, sizeof(dp[i]));
            memset(psum[i], 0, sizeof(psum[i]));
        }
        dp[0][0] = 1;
        psum[0][0] = 1;
        for(int tk = 1; tk <= k; tk++) {
            if (tk == 1) {
                fill(dp[tk], dp[tk] + n, 1);
            } else {
                for (int j = 0; j < n; j++) if (pv[j] != -1) add(dp[tk][j], psum[tk - 1][pv[j]]);
            }
            psum[tk][0] = dp[tk][0];
            for (int j = 1; j < n; j++) psum[tk][j] = (psum[tk][j-1] + dp[tk][j]) % mod;
        }
        res[gap] = psum[k][n-1];
        fres += 1LL * (res[gap] - res[gap+1]) * gap;
        fres %= mod;
    }
    cout << (fres % mod + mod) % mod << endl;
}