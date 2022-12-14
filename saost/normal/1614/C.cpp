#include <bits/stdc++.h>
using namespace std;
const int N = 200005, MOD = 1e9 + 7;
int t, n, m, ans[N], dp[N][30], c[N], c2[30][2];
long long res;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for(int i=1; i<=m; ++i) {
            int u, v, x;
            cin >> u >> v >> x;
            ++c[u]; --c[v + 1];
            for(int j=0; j<30; ++j) {
                if ((x>>j)&1) ++dp[u][j], --dp[v+1][j];
            }
        }
        for(int i=1; i<=n; ++i) {
            c[i] += c[i - 1];
            for(int j=0; j<30; ++j) {
                dp[i][j] += dp[i - 1][j];
                if (c[i] && dp[i][j] == c[i]) ans[i] |= (1<<j);
            }
        }
        for(int i=0; i<30; ++i) c2[i][0] = 1;
        for(int i=1; i<=n; ++i) {
            for(int j=0; j<30; ++j) {
                if ((ans[i]>>j)&1) {
                    c2[j][0] = c2[j][1] = (c2[j][0] + c2[j][1]) % MOD;
                }
                else {
                    (c2[j][0] *= 2) %= MOD;
                    (c2[j][1] *= 2) %= MOD;
                }
            }
        }
        for(int i=0; i<30; ++i) res += (1LL << i) * c2[i][1];
        cout << res % MOD << '\n';

        res = 0;
        for(int i=1; i<=n+1; ++i) {
            c[i] = 0;
            ans[i] = 0;
            for(int j=0; j<30; ++j) dp[i][j] = 0;
        }
        for(int i=0; i<30; ++i) c2[i][0] = c2[i][1] = 0;
    }
}