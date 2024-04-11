#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 3e5 + 10, LOG = 20;
int n, q;
int a[N];
int dp[N][LOG];
int last[LOG];

void init() {
    fill(last, last + LOG, -1);
    for (int i = 0; i < n; ++i) {
        for (int bit = 0; bit < LOG; ++bit) {
            dp[i][bit] = -1;
            if ((a[i] >> bit) & 1) {
                dp[i][bit] = i;
            }
        }
        for (int prevBit = 0; prevBit < LOG; ++prevBit) {
            if (last[prevBit] == -1) continue;
            if (!((a[i] >> prevBit) & 1)) continue;
            for (int hasBit = 0; hasBit < LOG; ++hasBit) {
                chkmax(dp[i][hasBit], dp[last[prevBit]][hasBit]);
            }
        }
        for (int bit = 0; bit < LOG; ++bit) {
            if ((a[i] >> bit) & 1) {
                last[bit] = i;
            }
        }
    }
    // cerr << "dp = " << endl;
    // for (int i = 0; i < n; ++i) {
    //     for (int bit = 0; bit < LOG; ++bit) {
    //         cerr << dp[i][bit] << ' '; 
    //     } 
    //     cerr << endl;
    // }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    init();
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        bool ok = false;
        for (int bit = 0; bit < LOG; ++bit) {
            if (dp[y][bit] >= x && ((a[x] >> bit) & 1)) {
                ok = true;
            }
        }
        if (ok) {
            cout << "Shi\n";
        } else {
            cout << "Fou\n";
        }
    }
    return 0;
}