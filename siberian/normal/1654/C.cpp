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

void solve() {
    int n;
    cin >> n;
    
    multiset<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int sum = 0;
    for (auto i : a) {
        sum += i;
    }
    map<int, int> cur;
    cur[sum]++;
    // int cnt = 0;
    while (!cur.empty() && !a.empty()) {
        // ++cnt;
        int x = (--cur.end())->first;
        int cnt_x = (--cur.end())->second;
        cur.erase(--cur.end());
        while (a.find(x) != a.end() && cnt_x > 0) {
            a.erase(a.find(x));
            --cnt_x;
        }
        if (cnt_x > 0 && x > 1) {
            cur[x / 2] += cnt_x;
            cur[(x + 1) / 2] += cnt_x;
        }
    }
    // cerr <<cnt << endl;
    if (!a.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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