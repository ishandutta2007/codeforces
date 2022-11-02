#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

const int maxN = 210000;
const int inf = 1000000000;
int d[maxN][2][2];

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                d[i][j][k] = inf;
            }
        }
    }

    d[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (d[i][j][k] == inf) {
                    continue;
                }

                d[i + 1][k][1] = min(d[i + 1][k][1], d[i][j][k] + 1);
                bool good = true;
                if (i > 0 && s[i] == s[i - 1] && k == 0) {
                    good = false;
                }
                if (i > 1 && s[i] == s[i - 2] && j == 0) {
                    good = false;
                }
                if (good) {
                    d[i + 1][k][0] = min(d[i + 1][k][0], d[i][j][k]);
                }
            }
        }
    }
    int res = inf;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            res = min(res, d[n][i][j]);
        }
    }
    cout << res << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }


    return 0;
}