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

#define int ll

const int N = 1e3 + 10;

int n;
int a[N];

// int minBalL[N][N];
// int minBalR[N][N];

// void precalc() {
//     for (int i = 0; i < n; ++i) {
//         int bal = 0;
//         int minBal = 0;
//         for (int j = i; j < n; ++j) {
//             if (j % 2 == 0) {
//                 bal += a[i];
//             } else {
//                 bal -= a[i];
//             }
//             chkmin(minBal, bal);
//             minBalL[i][j] = minBal;
//         }
//     }
//     for (int j = 0; j < n; ++j) {
//         int bal = 0;
//         int minBal = 0;
//         for (int i = j; i >= 0; --i) {
//             if (i % 2 == 0) {
//                 bal -= a[i];
//             } else {
//                 bal += a[i];
//             }
//             chkmin(minBal, bal);
//             minBalR[i][j] = minBal;
//         }
//     }
// }

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // precalc();
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        if (l % 2 != 0) continue;
        int bal = 0;
        int minBal = 0;
        for (int r = l + 1; r < n; ++r) {
            if (r % 2 == 1) {
                int L = max(minBal < 0 ? -minBal : 0LL, 1LL);
                int R = a[l];
                chkmin(R, a[r] - bal);
                // chkmax(L, minBalR[l + 1][r - 1] < 0 ? -minBalR[l + 1][r - 1] : 0);
                // cerr << "l = " << l << " r = " << r << " L = " << L << " R = " << R << " bal = " << bal << " minBal = " << minBal << " add = " << R - L + 1 << endl;
                ans += max(0LL, R - L + 1);
            }

            if (r % 2 == 0) {
                bal += a[r];
            } else {
                bal -= a[r];
            }
            chkmin(minBal, bal);
        }
    }
    cout << ans << endl;
    return 0;
}