#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

typedef double ld;

const int N = 30;

ld prob[2][N][N][2];
int p[N], r[N];
int n, k;

int
main()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        r[p[i]] = i;
    }
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int k = 0; k < 2; ++k) {
                prob[0][a][b][k] = 0.;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            prob[0][r[i]][r[j]][0] = 1.;
            prob[0][r[j]][r[i]][1] = 1.;
        }
    }
    for (int it = 0; it < k; ++it) {
        int cur_pos = it % 2, next_pos = cur_pos ^ 1;
        ld pr = 2. / (n + 1.) / (n + 0.);
        for (int k = 0; k < n; ++k) {
            for (int l = 0; l < n; ++l) {
                for (int p = 0; p < 2; ++p) {
                    prob[next_pos][k][l][p] = 0.;
                }
            }
        }
        for (int l = 0; l < n; ++l) {
            for (int r = l; r < n; ++r) {
                for (int a = 0; a < n; ++a) {
                    for (int b = 0; b < n; ++b) {
                        if (a == b) {
                            continue;
                        }
                        int na = a, nb = b;
                        if (l <= a && a <= r) {
                            na = (r + l - a);
                        }
                        if (l <= b && b <= r) {
                            nb = (r + l - b);
                        }
                        for (int p = 0; p < 2; ++p) {
                            prob[next_pos][na][nb][p] += pr * prob[cur_pos][a][b][p];
                        }
                    }
                }
            }
        }
    }
    ld res = 0;
    for (int a = 0; a < n; ++a) {
        for (int b = a + 1; b < n; ++b) {
            res += prob[k & 1][a][b][1];
            /*if (prob[k & 1][i][b][j][a]) {
                cout << i << ' ' << b << " > " << j << ' ' << a << endl;
            }*/
        }
    }
    cout << fixed << setprecision(20) << res << '\n';
    return 0;
}