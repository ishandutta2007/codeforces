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

bool correct(const string& s, int mask) {
    assert(s.size() == 10);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') continue;
        if (((mask >> i) & 1) != s[i] - '0') {
            return false;
        }
    }
    return true;
}

int getMax0(int it) {
    int ans = 0;
    ++it;
    for (; it < 10; ++it) {
        if (it & 1) continue;
        ++ans;
    }
    return ans;
}

int getMax1(int it) {
    int ans = 0;
    ++it;
    for (; it < 10; ++it){
        if (it & 1) ++ans;
    }
    return ans;
}

int calc(int mask) {
    int have0 = 0, have1 = 0;
    for (int i = 0; i < 10; ++i) {
        if ((mask >> i) & 1) {
            if (i % 2 == 0) {
                have0++;
            } else  {
                have1++;
            }
        } else {
            // if (i % 2 == 0) {

            // } else {

            // }
        }
        if (have0 + getMax0(i) < have1) return i + 1;
        if (have1 + getMax1(i) < have0) return i + 1;
    }
    return 10;
}

void solve() {
    string s;
    cin >> s;
    int n = 10;
    int ans = 10;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (!correct(s, mask)) continue;
        chkmin(ans, calc(mask));
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