#include <bits/stdc++.h>

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool win[100][100][2];

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    forn (q, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        int x = 0;
        forn (i, n) {
            cin >> a[i];
            x ^= a[i];
        }
        if (x == 0) {
            cout << "DRAW" << endl;
            continue;
        }
        int bit = 0;
        forn (i, 30) {
            if (x & (1 << i)) {
                bit = i;
            }
        }
        int cnt = 0;
        forn (i, n) {
            if (a[i] & (1 << bit)) {
                cnt++;
            }
        }
        if (cnt % 4 == 1 || (n - cnt) % 2) {
            cout << "WIN" << endl;
        } else {
            cout << "LOSE" << endl;
        }
    }
    /*win[0][0][1] = true;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            for (int k = 0; k < 2; k++) {
                if (i > 0 && !win[i - 1][j][(i % 2) ^ 1 ^ k]) {
                    win[i][j][k] = true;
                }
                if (j > 0 && !win[i][j - 1][(i % 2) ^ 1 ^ k]) {
                    win[i][j][k] = true;
                }
            }
        }
    }
    forn (i, 10) {
        forn (j, 10) {
            cout << i << " " << j << " " << win[i][j][0] << endl;
        }
    }*/
}