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
        int n;
        cin >> n;
        string ke = "";
        for (int _ = 0; _ < n + 47; _++) ke += '.';
        vector<string> F(n + 47, ke);
        vector<int> cnt(3);
        for (int i = 10; i < n + 10; i++) {
            string h;
            cin >> h;
            for (int j = 10; j < n + 10; j++) {
                F[i][j] = h[j - 10];
                if (F[i][j] != '.') {
                    cnt[(i + j) % 3]++;
                }
            }
        }
        int m = 0;
        if (cnt[1] == min({cnt[0], cnt[1], cnt[2]})) {
            m = 1;
        } else if (cnt[2] == min({cnt[0], cnt[1], cnt[2]})) {
            m = 2;
        }
        for (int i = 10; i < n + 10; i++) {
            for (int j = 10; j < n + 10; j++) {
                if ((i + j) % 3 == m) {
                    if (F[i][j] == 'X') {
                        F[i][j] = 'O';
                    } else if (F[i][j] == 'O') {
                        F[i][j] = 'X';
                    }
                }
            }
        }

        for (int i = 10; i < n + 10; i++) {
            for (int j = 10; j < n + 10; j++) {
                cout << F[i][j];
            }
            cout << '\n';
        }
    }
}