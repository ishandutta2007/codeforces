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
        if (cnt[1] == max({cnt[0], cnt[1], cnt[2]})) {
            m = 1;
        } else if (cnt[2] == max({cnt[0], cnt[1], cnt[2]})) {
            m = 2;
        }
        m %= 3;

        vector<int> crest(3 * n + 100);
        vector<int> zero(3 * n + 100);
        for (int i = 10; i < n + 10; i++) {
            for (int j = 10; j < n + 10; j++) {
                if ((i + j) % 3 != m) {
                    if (F[i][j] == 'X') {
                        crest[(i + j)]++;
                    } else if (F[i][j] == 'O') {
                        zero[(i + j)]++;
                    }
                }
            }
        }
        int a = 0, b = 0, c = 0, d = 0;
        for (int s = 20; s < 2 * n + 40; s++) {
            if (s % 3 != m && (s - 1) % 3 != m) {
                a += zero[s - 1];
                b += crest[s - 1];
                c += zero[s];
                d += crest[s];
            }
        }
        for (int s = 20; s < 2 * n + 40; s++) {
            if (s % 3 != m && (s - 1) % 3 != m) {
                if (a+d<b+c) {
                    for (int i = 10; i < n + 10; i++) {
                        int j = s - 1 - i;
                        if (10 <= j && j < n + 10) {
                            if (F[i][j] != '.') {
                                F[i][j] = 'X';
                            }
                        }
                    }
                    for (int i = 10; i < n + 10; i++) {
                        int j = s - i;
                        if (10 <= j && j < n + 10) {
                            if (F[i][j] != '.') {
                                F[i][j] = 'O';
                            }
                        }
                    }
                } else {
                    for (int i = 10; i < n + 10; i++) {
                        int j = s - 1 - i;
                        if (10 <= j && j < n + 10) {
                            if (F[i][j] != '.') {
                                F[i][j] = 'O';
                            }
                        }
                    }
                    for (int i = 10; i < n + 10; i++) {
                        int j = s - i;
                        if (10 <= j && j < n + 10) {
                            if (F[i][j] != '.') {
                                F[i][j] = 'X';
                            }
                        }
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