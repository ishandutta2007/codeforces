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
        int mx = -1e9 - 1, ans = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                cin >> a[i][j];
                if (a[i][j] >= mx) {
                    mx = a[i][j];
                    ans = max(i, n-i+1) * max(j, m-j+1);
                }
            }
        }
        cout << ans << "\n";
    }
}