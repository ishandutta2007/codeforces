#include <iostream>
#define mod 1000000007
using namespace std;
long long t, n, m, f[1005][1005], res;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        res = 0;
        cin >> n >> m;
        f[1][1] = 1;
        for(int i=1; i<=m; ++i) {
            if (i != 1) f[i][1] = 0;
            for(int j=2; j<=n+1; ++j) {
                f[i][j] = (f[i][j-1] + f[i-1][j-1]) % mod;
            }
            res = (res + f[i][n+1]) % mod;
            if (++i <= m) {
                f[i][n] = 0;
                for(int j=n-1; j>=0; j--) {
                    f[i][j] = (f[i][j+1] + f[i-1][j+1]) % mod;
                }
                res = (res + f[i][0]) % mod;
            }
        }
        cout << res << '\n';
    }
}