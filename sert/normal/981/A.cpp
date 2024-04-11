//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

int go(string &s, int l, int r) {
    int len = r - l;
    for (int i = 0; i < len / 2; i++) {
        if (s[l + i] != s[r - i - 1]) return len;
    }
    return 0;
}

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    for (int l = 0; l < (int)s.length(); l++) {
        for (int r = l + 1; r <= (int)s.length(); r++) {
            ans = max(ans, go(s, l, r));
        }
    }
    cout << ans << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
#endif
    solve();
    return 0;
}