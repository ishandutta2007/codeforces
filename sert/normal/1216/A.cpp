#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i += 2) {
        if (s[i] == s[i + 1]) {
            s[i] = 'a' + 'b' - s[i];
            ans++;
        }
    }
    cout << ans << "\n" << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
#ifdef MADE_BY_SERT
    int T = 3;
    for (int i = 1; i < T; i++) solve();    
#endif
}