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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

int n, m, k;
vector<int> a;

void solve() {
    cin >> n >> m >> k;
    a.resize(k);
    vin(a);
    set<int> has;
    int pos = 0;
    while (pos < n * m - 3 && pos < k) {
        has.insert(a[pos++]);
    }
    int need = k;
    while (!has.empty()) {
        if (!has.count(need)) {
            cout << "TIDAK" << '\n';
            return;
        }
        has.erase(need);
        --need;
        if (pos < k) {
            has.insert(a[pos++]);
        }
    }
    cout << "YA" << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}