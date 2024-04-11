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

const int N = 51;
int n;
string a[N];
int pref[N][N];

void build() {
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            pref[x][y] = a[x][y] == '#' ? 1 : 0;
            if (x > 0) pref[x][y] += pref[x - 1][y];
            if (y > 0) pref[x][y] += pref[x][y - 1];
            if (x > 0 && y > 0) pref[x][y] -= pref[x - 1][y - 1];
        }
    }
}

bool checkZero(int lx, int rx, int ly, int ry) {
    int ans = pref[rx][ry];
    if (lx > 0) ans -= pref[lx - 1][ry];
    if (ly > 0) ans -= pref[rx][ly - 1];
    if (lx > 0 && ly > 0) ans += pref[lx - 1][ly - 1];
    return ans == 0;
}

int dp[N][N][N][N];

void calcDp() {
    for (int rx = 0; rx < n; ++rx) {
        for (int lx = rx; lx >= 0; --lx) {
            for (int ry = 0; ry < n; ++ry) {
                for (int ly = ry; ly >= 0; --ly) {
                    int& val = dp[lx][rx][ly][ry];
                    val = max(rx - lx + 1, ry - ly + 1);
                    for (int midx = lx; midx <= rx; ++midx) {
                        if (!checkZero(midx, midx, ly, ry)) continue;
                        int fans = 0;
                        if (midx != lx) fans += dp[lx][midx - 1][ly][ry];
                        if (midx != rx) fans += dp[midx + 1][rx][ly][ry];
                        chkmin(val, fans);
                    }
                    for (int midy = ly; midy <= ry; ++midy) {
                        if (!checkZero(lx, rx, midy, midy)) continue;
                        int fans = 0;
                        if (midy != ly) fans += dp[lx][rx][ly][midy - 1];
                        if (midy != ry) fans += dp[lx][rx][midy + 1][ry];
                        chkmin(val, fans);
                    }
                }
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build();
    calcDp();
    cout << dp[0][n - 1][0][n - 1] << '\n';
    return 0;
}