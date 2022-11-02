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

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int n;
    cin >> n;
    map<pair<int, int>, int> have;
    map<int, int> a;
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        int w, h;
        cin >> w >> h;
        if (w > h) swap(w, h);
        int add = 0;
        if (w == h) {
            add = a[w];
        } else {
            add = a[w] + a[h] - have[{w, h}];
        }
        // cerr << "add = " << add << endl;
        ans += add;
        have[{w, h}]++;
        a[w]++;
        if (w != h) a[h]++;
    }
    cout << ans << endl;
    return 0;
}