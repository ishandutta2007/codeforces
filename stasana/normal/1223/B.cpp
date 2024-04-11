#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    vector<ll> cnt(26);
    string s;
    cin >> s;
    for (char i : s) {
        ++cnt[i - 'a'];
    }
    cin >> s;
    for (char i : s) {
        if (cnt[i - 'a']) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
}

int main() {
    start();
    int n;
    cin >> n;
    while (n) {
        --n;
        solve();
    }
    //solve();
    return 0;
}