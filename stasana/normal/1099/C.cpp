// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    string s;
    cin >> s;
    ll n;
    cin >> n;
    ll m = 0;
    ll cnt1 = 0, cnt2 = 0;
    for (auto i : s) {
        if (i == '*') {
            ++cnt2;
            continue;
        }
        if (i == '?') {
            ++cnt1;
            continue;
        }
        ++m;
    }
    if (n < (m - cnt1 - cnt2) || cnt2 == 0 && n > m) {
        cout << "Impossible" << endl;
        return;
    }
    string result;
    for (ll i = 0; i < s.length(); ++i) {
        if (s[i] == '?') {
            if (m > n) {
                --m;
                result.pop_back();
            }
            continue;
        }
        if (s[i] == '*') {
            while (m < n) {
                ++m;
                result.push_back(s[i - 1]);
            }
            if (m > n) {
                --m;
                result.pop_back();
            }
            continue;
        }
        result.push_back(s[i]);
    }
    for (auto i : result) {
        if (i == '*' || i == '?') {
            continue;
        }
        cout << i;
    }
    cout << endl;
}

int main() {
    start();
    solve();
    return 0;
}