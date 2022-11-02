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

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto i : s) {
        cnt[i]++;
    }
    string ans = "";
    for (int i = 0; i < k; ++i) {
        int cur = 0;
        while (cur < n / k && cnt['a' + cur] > 0) {
            cnt['a' + cur]--;
            ++cur;
        }
        ans += 'a' + cur;
    }
    cout << ans << '\n';
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