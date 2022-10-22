#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 9; j++) {
            string s;
            cin >> s;
            for (int k = 0; k < 9; k++) {
                if (s[k] == '1') s[k] = '2';
            }
            cout << s << '\n';
        }
    }
    return 0;
}