#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1) {
        cout << (k == 0 ? s : "0") << "\n";
        return;
    }

    for (int i = 0; i < n && k; i++) {
        char mn = (i ? '0' : '1');
        if (s[i] != mn) {
            s[i] = mn;
            k--;
        }
    }
    cout << s << "\n";
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