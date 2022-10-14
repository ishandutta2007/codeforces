#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        int j = n - 1;
        while (j >= 0 && s[j] == 'A') j--;
        if (j == -1) {
            cout << n << '\n';
            continue;
        }
        int a = 0, b = 0;
        for (int i = 0; i < j; i++) {
            a += (s[i] == 'A');
            b += (s[i] == 'B');
            if (a && s[i] == 'B') {
                a--;
                b--;
            }
        }
        if (a) {
            a -= 2;
            b %= 2;
            cout << (n - j) + a + b;
        } else {
            b++;
            b %= 2;
            cout << (n - 1 - j) + a + b;
        }
        cout << '\n';
    }

}