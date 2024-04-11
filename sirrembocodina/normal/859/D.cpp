#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int n, N;
ld p[100][100];
ld w[200][100];
ld d[200][100];
bool can[200][100];
int sc[200];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    int n = 1 << N;
    forn (i, n) {
        forn (j, n) {
            int x;
            cin >> x;
            p[i][j] = ld(x) * 0.01;
        }
    }
    forn (i, 2 * n) {
        forn (j, n) {
            w[i][j] = d[i][j] = 0;
        }
    }
    forn (i, n) {
        w[n + i][i] = 1;
        d[n + i][i] = 0;
        sc[n + i] = 1;
        can[n + i][i] = true;
    }
    cerr.precision(13);
    cerr << fixed;
    for (int i = n - 1; i >= 1; --i) {
        sc[i] = sc[2 * i] + sc[2 * i + 1];
        forn (j, n) {
            can[i][j] = can[2 * i][j] || can[2 * i + 1][j];
        }
        forn (j, n) {
            forn (k, n) {
//                cerr << w[2 * i][j] << " " << w[2 * i + 1][k] << " " << p[j][k] << endl;
//                cerr << w[2 * i][j] * w[2 * i + 1][k] * p[j][k] << endl;
                w[i][j] += w[2 * i][j] * w[2 * i + 1][k] * p[j][k];
//                cerr << j << " " << k << endl;
//                cerr << w[i][j] << endl;
                w[i][k] += w[2 * i][j] * w[2 * i + 1][k] * p[k][j];
            }
        }
//        return 0;
        forn (j, n) {
            forn (k, n) {
                if (can[2 * i][j] && can[2 * i + 1][k]) {
                    d[i][j] = max(d[i][j], d[2 * i][j] + d[2 * i + 1][k] + w[i][j] * sc[i]);
                    d[i][k] = max(d[i][k], d[2 * i][j] + d[2 * i + 1][k] + w[i][k] * sc[i]);
                }
            }
        }
/*        forn (j, n) {
            cerr << double(d[i][j]) << ' ';
        }
        cerr << endl;
*/    }
    ld ans = 0;
    forn (i, n) {
        ans = max(ans, d[1][i]);
    }
    cout.precision(15);
    cout << fixed << double(ans / 2) << endl;
    return 0;
}