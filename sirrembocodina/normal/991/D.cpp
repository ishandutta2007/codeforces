#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

string s[2];
int d[110][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s[0] >> s[1];
    int n = s[0].size();
    forn (j, 4) {
        if (j) {
            d[0][j] = -2000000000;
        }
    }
    forn (i, n) {
        forn (J, 4) {
            bool ok = true;
            int j = J;
            forn (k, 2) {
                if (s[k][i] == 'X') {
                    j |= 1 << k;
                }
                if (s[k][i] == 'X' && (J & (1 << k))) {
                    ok = false;
                }
            }
            if (!ok) {
                continue;
            }
            d[i + 1][0] = max(d[i + 1][0], d[i][J]);
            if (j == 0) {
                d[i + 1][1] = max(d[i + 1][1], d[i][J] + 1);
                d[i + 1][2] = max(d[i + 1][2], d[i][J] + 1);
            }
            if (j != 3) {
                d[i + 1][3] = max(d[i + 1][3], d[i][J] + 1);
            }
        }
    }
    forn (i, n + 1) {
        forn (j, 4) {
//            cout << d[i][j] << " ";
        }
//        cout << endl;
    }
    cout << d[n][0] << endl;
    return 0;
}