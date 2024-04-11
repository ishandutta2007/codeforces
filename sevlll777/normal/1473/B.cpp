#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t0;
    cin >> t0;
    while (t0--) {
        string s, t;
        cin >> s >> t;
        int l = lcm(s.size(), t.size());
        string tt = "";
        while (tt.size() < l) {
            tt += t;
        }
        for (int i = 0; i < l; i++) {
            if (tt[i] != s[i % s.size()]) {
                tt = "-1";
                break;
            }
        }
        cout << tt;
        cout << '\n';
    }
}