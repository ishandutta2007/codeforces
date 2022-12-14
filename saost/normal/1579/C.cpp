#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, m, n, k, f[N][N][2], ok[N][N];
char s[N][N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> m >> n >> k;
        for(int i=1; i<=m; ++i) cin >> s[i] + 1;
        for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) {
            f[i][j][0] = (s[i][j] == '*' ? f[i-1][j-1][0] + 1 : 0);
            f[i][j][1] = (s[i][j] == '*' ? f[i-1][j+1][1] + 1 : 0);
            int w = min(f[i][j][0], f[i][j][1]);
            if (w > k) {
                for(int z=0; z<w; ++z) ok[i - z][j - z] = ok[i - z][j + z] = 1;
            }
        }
        bool ans = true;
        for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) {
            if (s[i][j] == '*' && ok[i][j] == 0) ans = false;
            f[i][j][0] = f[i][j][1] = ok[i][j] = 0;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}