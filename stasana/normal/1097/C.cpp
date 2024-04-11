// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    ll n;
    cin >> n;
    multiset<ll> a;
    vector<ll> b;
    ll result = 0;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ll cnt = 0;
        for (auto j : s) {
            if (j == '(') {
                ++cnt;
            }
            if (j == ')') {
                --cnt;
            }
        }
        ll f1 = 0;
        ll f2 = 0;
        ll bal = 0;
        for (ll i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                ++bal;
            }
            if (s[i] == ')') {
                --bal;
            }
            if (bal < 0) {
                f1 = 1;
            }
        }
        bal = 0;
        for (ll i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++bal;
            }
            if (s[i] == ')') {
                --bal;
            }
            if (bal > 0) {
                f2 = 1;
            }
        }
        if (cnt < 0 && !f2) {
            a.insert(cnt);
        }
        if (cnt > 0 && !f1) {
            b.emplace_back(cnt);
        }
        if (cnt == 0 && !f1 && !f2) {
            ++result;
        }
    }
    result /= 2;
    for (ll i : b) {
        if (a.find(-i) != a.end()) {
            a.erase(a.find(-i));
            ++result;
        }
    }
    cout << result << endl;
}

int main() {
    start();
    solve();
    return 0;
}