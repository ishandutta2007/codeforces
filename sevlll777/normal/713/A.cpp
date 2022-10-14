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
    int t;
    cin >> t;
    map<string, int> kek;
    while (t--) {
        char cmd; string x;
        cin >> cmd >> x;
        while (x.size() < 18) {
            x = "0" + x;
        }
        for (int c = 0;c < 18; c++) {
            x[c] = '0' + (x[c] - '0') % 2;
        }
        if (cmd == '+') {
            kek[x]++;
        } else if (cmd == '-') {
            kek[x]--;
        } else {
            cout << kek[x] << '\n';
        }
    }
}