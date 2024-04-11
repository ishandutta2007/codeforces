//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
int32_t dst[501][501];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edg;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dst[i][j] = 505;
            if (i == j)
                dst[i][j] = 0;
        }
    }
    long long ans = 1e14;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        edg.push_back({a, b, c});
        dst[a][b] = 1;
        dst[b][a] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                dst[j][k] = min(dst[j][i] + dst[i][k], dst[j][k]);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        auto [a, b, cc] = edg[i];
        long long c = cc;
        int vlc = n * 4;
        for (int j = 0; j < n; ++j) {
            vlc = min(vlc, min(dst[a][j], dst[b][j]) + 1 + dst[0][j] + dst[j][n-1] + 1);
        }
        //cout << a << ' ' << b << ' ' << dst[0][a] << ' ' << dst[b][n-1] + 1 << '\n';
        ans = min(ans, (dst[0][a] + dst[b][n-1] + 1) * c);
        swap(a, b);
        //cout << a << ' ' << b << ' ' << dst[0][a] + dst[b][n-1] + 1 << '\n';
        ans = min(ans, (dst[0][a] + dst[b][n-1] + 1) * c);
        //cout << a << ' ' << b << ' ' << dst[0][a] + dst[b][n-1] + 1 << '\n';
        ans = min(vlc * c, ans);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
/*
1
4 3
2 3 10000000000
1 2 1111
2 4 1111
 */