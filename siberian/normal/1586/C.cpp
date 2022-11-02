#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

int n, m;
vector<vector<char>> a;
vector<vector<int>> pref;

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    for (auto& i : a) 
        for (auto& j : i) 
            cin >> j;
    pref.assign(n, vector<int>(m, 0));
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (x > 0 && y > 0 && a[x - 1][y] == 'X' && a[x][y - 1] == 'X') {
                pref[x][y] = 1;
            }
            if (x > 0) pref[x][y] += pref[x - 1][y];
            if (y > 0) pref[x][y] += pref[x][y - 1];
            if (x > 0 && y > 0) pref[x][y] -= pref[x - 1][y - 1];
        }
    }
    auto getPref = [&] (int lx, int rx, int ly, int ry) -> bool {
        if (lx > rx || ly > ry) return true;
        // cerr << "lx = " << lx << " rx = " << rx << "ly = " << ly << " ry = " << ry << endl;
        int fans = pref[rx][ry];
        if (lx > 0) fans -= pref[lx - 1][ry];
        if (ly > 0) fans -= pref[rx][ly - 1];
        if (lx > 0 && ly > 0) fans += pref[lx - 1][ly - 1];
        return fans == 0; 
    };
    int q;
    cin >> q;
    while (q--) {
        int ly, ry;
        cin >> ly >> ry;
        --ly;
        --ry;
        if (getPref(0 + 1, n - 1, ly + 1, ry)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        // cout.flush();
    }
    return 0;
}