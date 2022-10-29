#include <iomanip>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef double ld;

const int MAXN = 501;
const int MAXK = 100500;

bool trap[MAXN];
ld res[MAXN];
ld mx[MAXN][MAXN];
ld mtmp[MAXN][MAXN];
int deg[MAXN];
int sm[MAXN][MAXN];
ld mg[MAXN][2 * MAXN];
int n, m, k;
int bad[MAXN], cnt_b;

ld vec[MAXN];

void
gauss()
{
    for (int i = 0; i < n; ++i) {
        mg[i][i] = 1.;
        for (int j = 0; j < n; ++j) {
            if (i != j && !trap[j]) {
                mg[i][j] = -(sm[i][j] + 0.) / deg[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mg[j][i + n] = (sm[j][i] + 0.) / deg[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        int ind = i;
        for (int j = i; j < n; ++j) {
            if (fabs(mg[j][i]) > fabs(mg[ind][i])) {
                ind = j;
            }
        }
        for (int k = i; k < 2 * n; ++k) {
            swap(mg[i][k], mg[ind][k]);
        }
        ld tmp = mg[i][i];
        for (int k = i; k < 2 * n; ++k) {
            mg[i][k] /= tmp;
        }
        for (int j = i + 1; j < n; ++j) {
            ld cur = mg[j][i];
            for (int k = i; k < 2 * n; ++k) {
                mg[j][k] -= mg[i][k] * cur;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i - 1; j >= 0; --j) {
            ld tmp = mg[j][i];
            for (int k = i; k < 2 * n; ++k) {
                mg[j][k] -= tmp * mg[i][k];
            }
        }
    }
}

void
calc_init()
{
    for (int i = 0; i < cnt_b; ++i) {
        res[i] = mg[0][bad[i] + n];
        for (int j = 0; j < cnt_b; ++j) {
            mx[j][i] = mg[bad[j]][bad[i] + n];
        }
    }
}

void
mult(int st)
{
    while (st) {
        if (st & 1) {
            for (int i = 0; i < cnt_b; ++i) {
                vec[i] = 0;
                for (int j = 0; j < cnt_b; ++j) {
                    vec[i] += res[j] * mx[j][i];
                }
            }
            for (int i = 0; i < cnt_b; ++i) {
                res[i] = vec[i];
            }
        }
        st /= 2;
        for (int i = 0; i < cnt_b; ++i) {
            for (int j = 0; j < cnt_b; ++j) {
                ld tmp = 0.;
                for (int k = 0; k < cnt_b; ++k) {
                    tmp += mx[i][k] * mx[k][j];
                }
                mtmp[i][j] = tmp;
            }
        }
        for (int i = 0; i < cnt_b; ++i) {
            for (int j = 0; j < cnt_b; ++j) {
                mx[i][j] = mtmp[i][j];
            }
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    cnt_b = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        trap[i] = cur;
        if (cur) {
            bad[cnt_b++] = i;
        }
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b; --a, --b;
        sm[a][b]++;
        sm[b][a]++;
        deg[a]++;
        deg[b]++;
    }
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(5);
    gauss();
    calc_init();
    mult(k - 2);
    cout << res[cnt_b - 1] << '\n';
    return 0;
}