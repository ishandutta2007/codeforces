#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int a[5100];
int d[5100][3100][2];

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
    }
    forn (i, n + 10) {
        forn (j, n / 2 + 10) {
            forn (k, 2) {
                d[i][j + 1][k] = 2000000000;
            }
        }
    }
    d[0][1][1] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= (n + 1) / 2; ++j) {
            if (a[i] >= a[i - 1]) {
                d[i][j][0] = min(d[i - 1][j][0], d[i - 1][j][1] + a[i] - a[i - 1] + 1);
            } else {
                d[i][j][0] = d[i - 1][j][1];
            }
            if (a[i] > a[i - 1]) {
                d[i][j][1] = min(d[i][j][0], d[i - 1][j - 1][0]);
            } else {
                if (i == 1) {
                    d[i][j][1] = min(d[i][j][0], a[i - 1] - a[i] + 1 + (j > 1) * 2000000000);
                } else {
                    d[i][j][1] = min(d[i][j][0], min(d[i - 2][j - 1][0] + a[i - 1] - a[i] + 1,
                                                     d[i - 2][j - 1][1] + a[i - 1] - min(a[i], a[i - 2]) + 1));
                }
            }/*
            if (a[i] == a[i - 1]) {
                d[i][j][0] = min(d[i - 1][j][0], d[i - 1][j][1] + 1);
                if (i == 1) {
                    d[i][j][1] = min(d[i][j][0], 1 + (j > 1) * 2000000000);
                } else {
                    d[i][j][1] = min(d[i][j][0], min(d[i - 2][j - 1][0] + 1,
                                                     d[i - 2][j - 1][1] + a[i - 1] - min(a[i], a[i - 2]) + 1));
                }
            }*/
        }
    }
//    cout << d[0][1][1] << " " << d[2][2][1] << " " << d[4][3][1] << endl;
    forn (j, (n + 1) / 2) {
        cout << d[n - 1][j + 1][1] << " ";
    }
    cout << endl;
    return 0;
}