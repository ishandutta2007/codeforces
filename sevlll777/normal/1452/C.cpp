#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int op1 = 0, op2 = 0, ans = 0;
        for (auto c : s) {
            if (c == '(') {
                op1++;
            } else if (c == ')') {
                if (op1) {
                    op1--;
                    ans++;
                }
            } else if (c == '[') {
                op2++;
            } else {
                if (op2) {
                    op2--;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}