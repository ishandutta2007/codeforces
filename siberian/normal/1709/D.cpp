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

const int N = 2e5 + 10, LOG = 19;
int h, n;
int a[N];

int sparse[N][LOG];
int lg[N];

int getMax(int l, int r) {
    int log = lg[r - l];
    return max(sparse[l][log], sparse[r - (1 << log) + 1][log]);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> h >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sparse[i][0] = a[i];
    }
    lg[0] = lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int l = 1; l < LOG; ++l) {
        for (int i = 0; i + (1 << l) - 1 < n; ++i) {
            sparse[i][l] = max(sparse[i][l - 1], sparse[i + (1 << (l - 1))][l - 1]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int from_x, from_y, to_x, to_y;
        int k;
        cin >> from_y >> from_x >> to_y >> to_x >> k;
        --from_x;
        --to_x;
        if (abs(from_x - to_x) % k != 0 || abs(from_y - to_y) % k != 0) {
            cout << "NO\n";
            continue;
        }
        int maxY = from_y + (h - from_y) / k * k;
        if (getMax(min(from_x, to_x), max(from_x, to_x)) >= maxY) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}