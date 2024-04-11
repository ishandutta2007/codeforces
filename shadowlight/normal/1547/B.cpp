#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int now = 0;

    vector <int> pos(26, -1);
    for (char c : s) {
        int k = c - 'a';
        if (pos[k] != -1) {
            cout << "NO\n";
            return;
        }
        pos[k] = now++;
    }
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (pos[i] == -1) {
            cout << "NO\n";
            return;
        }
    }
    int l = pos[0], r = pos[0];
    for (int i = 1; i < n; ++i) {
        if (pos[i] == l - 1) {
            --l;
        } else if (pos[i] == r + 1) {
            ++r;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}