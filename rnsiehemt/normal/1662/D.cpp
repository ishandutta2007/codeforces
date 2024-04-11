#include <bits/stdc++.h>
using namespace std;

int canon(string s) {
    int b = 0;
    string t;
    for (char c : s) {
        if (c == 'B') {
            b++;
        } else {
            if (!t.empty() && t.back() == c) {
                t.pop_back();
            } else {
                t.push_back(c);
            }
        }
    }
    b %= 2;
    return b + (!t.empty() && t[0] == 'C' ? 2 : 0) + 4*int(t.length());
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string u, v;
        cin >> u >> v;
        cout << (canon(u) == canon(v) ? "YES" : "NO") << "\n";
    }
}