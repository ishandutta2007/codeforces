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

const int K = 110;
int ans[K];

void build() {
    fill(ans, ans + K, (int)1e9);
    for (int e = 0; e < 1000; ++e) {
        for (int w = 0; w < 1000; ++w) {
            if (e + w == 0) continue;
            if (e * 100 % (e + w) != 0) continue;
            chkmin(ans[e * 100 / (e + w)], e + w);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    build();
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cout << ans[k] << endl;
    }
    return 0;
}