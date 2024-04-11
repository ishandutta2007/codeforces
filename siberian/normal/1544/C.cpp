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

int n;
vector<int> a, b;

bool check(int k) {
    k += n;
    int cnt = k - k / 4;
    int sum = 0;
    for (int i = 0; i < n && i < cnt; ++i) {
        sum -= a[i];
    }
    int add100 = min(k - n, cnt);
    sum += 100 * add100;
    cnt -= add100;
    for (int i = 0; i < n && i < cnt; ++i) {
        sum += b[i];
    }
    return sum >= 0;
}

void solve() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    // vin(a);
    // vin(b);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    sort(all(a));
    reverse(all(a));
    sort(all(b));
    reverse(all(b));
    swap(a, b);
    int l = -1, r = 1e9;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
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