#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define fro for
#define pb push_back
#define ld long double


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = -1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            string ff = "";
            for (int c = 0; c < n; c++) {
                if (c <= i || c >= j) {
                    ff += s[c];
                }
            }
            if (ff == "CODEFORCES") {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}