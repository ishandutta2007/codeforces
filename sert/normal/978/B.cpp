//made by Sert
#include <bits/stdc++.h>
using namespace std;

const int N = 100;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if ((int)s.length() != n) exit(11);
    if (n < 3 || n > N) exit(22);
    s.push_back('_');
    int len = 0;
    int ans = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == 'x') len++;
        else {
            ans += max(0, len - 2);
            len = 0;
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