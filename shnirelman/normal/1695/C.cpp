#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int M = 1e9 + 7;
const int N = 1000 + 13;
const int LOGN = 30;

int a[N][N], mn[N][N], mx[N][N];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if((n + m - 1) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    mn[0][0] = mx[0][0] = a[0][0];
    for(int i = 1; i < n; i++) {
        mn[i][0] = mx[i][0] = mn[i - 1][0] + a[i][0];
    }

    for(int j = 1; j < m; j++) {
        mn[0][j] = mx[0][j] = mn[0][j - 1] + a[0][j];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            mn[i][j] = INF;
            mx[i][j] = -INF;

//            if(j > 0) {
                mn[i][j] = min(mn[i][j], mn[i][j - 1] + a[i][j]);
                mx[i][j] = max(mx[i][j], mx[i][j - 1] + a[i][j]);
//            }

//            if(i > 0) {
                mn[i][j] = min(mn[i][j], mn[i - 1][j] + a[i][j]);
                mx[i][j] = max(mx[i][j], mx[i - 1][j] + a[i][j]);
//            }
        }
    }

//    cout << "----------- " << mn[n - 1][m - 1] << ' ' << mx[n - 1][m - 1] << endl;

    cout << (mn[n - 1][m - 1] <= 0 && 0 <= mx[n - 1][m - 1] ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}