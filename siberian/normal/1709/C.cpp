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
    string s;
    cin >> s;
    int cntOpen = 0;
    int cntClose = 0;
    for (auto i : s) {
        if (i == '(') {
            ++cntOpen;
        } else if (i == ')') {
            ++cntClose;
        }
    }
    assert(s.size() % 2 == 0);
    assert(cntOpen <= (int)s.size() / 2 && cntClose <= (int)s.size() / 2);
    int needOpen = (int)s.size() / 2 - cntOpen;
    int needClose = (int)s.size() / 2 - cntClose;
    auto gen = [&] (string from, int cnt, char type) -> string {
        string ans;
        for (auto i : from) {
            if (i == '?' && cnt > 0) {
                --cnt;
                ans += type;
            } else {
                ans += i;
            }
        }
        return ans;
    };
    auto check = [&] (string s) -> bool {
        int bal = 0;
        for (auto i : s) {
            if (i == '(') {
                ++bal;
            } else if (i == ')') {
                --bal;
            } else {
                assert(false);
            }
            if (bal < 0) {
                return false;
            }
        }
        return bal == 0;
    };
    string best = gen(gen(s, needOpen, '('), needClose, ')');
    assert(check(best));
    if (needOpen == 0 || needClose == 0) {
        cout << "YES\n";
        return;
    }
    string fbest = s;
    fbest = gen(fbest, needOpen - 1, '(');
    fbest = gen(fbest, 1, ')');
    fbest = gen(fbest, 1, '(');
    fbest = gen(fbest, needClose - 1, ')');
    if (check(fbest)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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