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
    string s;
    cin >> s;
    set<char> q1, q2;
    for (int i = 0; i < 5; ++i) {
        string ss;
        cin >> ss;
        q1.insert(ss[0]);
        q2.insert(ss[1]);
    }
    if (q1.count(s[0]) || q2.count(s[1])) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    start();
    solve();
    return 0;
}