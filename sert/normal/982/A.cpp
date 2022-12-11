//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
        cout << (s[0] == '0' ? "No\n" : "Yes\n");
        return;
    }
    cout << (((s[0] == '0' && s[1] == '0') || (s.back() == '0' && s[(int)s.length() - 2] == '0') || s.find("000") != string::npos || s.find("11") != string :: npos) ? "No\n" : "Yes\n");
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