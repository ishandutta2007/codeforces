#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int si = s.size() - 1, ti = t.size() - 1;
    while (ti >= 0) {
        if (si < 0) {
            cout << "NO\n";
            return;
        }
        if (s[si] == t[ti]) {
            --si;
            --ti;
        } else {
            si -= 2;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}