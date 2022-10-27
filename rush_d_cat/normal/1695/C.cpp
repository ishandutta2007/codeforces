#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 10000 + 10;
int a[42][42];
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > a(n + 1, vector<int>(m + 1, 0));
        vector<vector<int> > mx(n + 1, vector<int>(m + 1, -1e9));
        vector<vector<int> > mn(n + 1, vector<int>(m + 1, 1e9));
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                cin >> a[i][j];
            }
        }
        mx[1][1] = mn[1][1] = a[1][1];
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (i == 1 && j == 1) continue;
                if (i > 1) {
                    mx[i][j] = max(mx[i-1][j] + a[i][j], mx[i][j]);
                    mn[i][j] = min(mn[i-1][j] + a[i][j], mn[i][j]);
                }
                if (j > 1) {
                    mx[i][j] = max(mx[i][j-1] + a[i][j], mx[i][j]);
                    mn[i][j] = min(mn[i][j-1] + a[i][j], mn[i][j]);
                }
            }
        }
        cout << ((mx[n][m]>=0 && mn[n][m]<=0 and abs(mx[n][m]) % 2 == 0) ? "YES" : "NO") << "\n";
    }
}