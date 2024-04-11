#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

// TEMPLATE STARTS BELOW

template<int r, int c, class T> struct Matrix {
    T a[r+1][c+1];
    Matrix() {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                a[i][j] = 0;
            }
        }
    }
};

template<int r, int c, int k, class T>
void matrix_mult(Matrix<r, k, T>& ans, const Matrix<r, c, T>& first,
    const Matrix<c, k, T>& second) {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= k; j++) {
            ans.a[i][j] = 0;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 1; x <= c; x++) {
                ans.a[i][j] = ans.a[i][j] + first.a[i][x] * second.a[x][j];
            }
        }
    }
}

template<int n, class T>
void matrix_power(Matrix<n, n, T>& base, ll exponent)
{
    Matrix<n, n, T> cur = base;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            base.a[i][j] = (i == j ? 1 : 0);
        }
    }
    while (exponent) {
        Matrix<n, n, T> tmp;
        if (exponent & 1LL) {
            matrix_mult(tmp, base, cur);
            base = tmp;
        }
        matrix_mult(tmp, cur, cur);
        cur = tmp; exponent >>= 1LL;
    }
}

template<int N, class T>
void matrix_invert(Matrix<N, N, T>& orig, int siz = N)
{
    Matrix<N, 2 * N, T> mat;
    for (int i = 1; i <= siz; i++) {
        for (int j = 1; j <= siz; j++) {
            mat.a[i][j] = orig.a[i][j];
        }
    }
    for (int i = 1; i <= siz; i++) {
        mat.a[i][siz+i] = 1;
    }
    for (int i = 1; i <= siz; i++) {
        int bestrow = i;
        for (int j = i + 1; j <= siz; j++) {
            if (mat.a[j][i] > mat.a[bestrow][i]) bestrow = j;
        }
        if (bestrow != i) {
            for (int j = 1; j <= 2 * siz; j++) swap(mat.a[i][j], mat.a[bestrow][j]);
        }
        for (int j = i + 1; j <= siz; j++) {
            T mult_by = mat.a[j][i] / mat.a[i][i];
            for (int k = 1; k <= 2 * siz; k++) {
                mat.a[j][k] = mat.a[j][k] - mult_by * mat.a[i][k];
            }
        }
        for (int j = 2 * siz; j >= i; j--) {
            mat.a[i][j] = mat.a[i][j] / mat.a[i][i];
        }
    }
    for (int i = 1; i <= siz; i++) {
        for (int j = 1; j < i; j++) {
            T mult_by = mat.a[j][i];
            for (int k = 1; k <= 2 * siz; k++) {
                mat.a[j][k] = mat.a[j][k] - mult_by * mat.a[i][k];
            }
        }
    }
    for (int i = 1; i <= siz; i++) {
        for (int j = 1; j <= siz; j++) {
            orig.a[i][j] = mat.a[i][siz+j];
        }
    }
}

int n, m, k;
int hastrap[505];
int id[505];

vector<int> graph[505];
int adj[505][505];
int notrap_rev[505];
int trap_rev[505];
Matrix<500, 500, double> markov;
Matrix<1, 105, double> beginprob;
Matrix<1, 105, double> ans;
Matrix<105, 105, double> traptrans;
Matrix<500, 105, double> res;
Matrix<500, 105, double> notrap2trap;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", hastrap + i);
    }
    int notrap_next = 1; int trap_next = 1;
    for (int i = 1; i <= n; i++) {
        if (hastrap[i]) {
            id[i] = trap_next++;
            trap_rev[id[i]] = i;
        } else {
            id[i] = notrap_next++;
            notrap_rev[id[i]] = i;
        }
    }
    notrap_next--; trap_next--;
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
        adj[u][v]++; adj[v][u]++;
    }
    for (int i = 1; i <= notrap_next; i++) {
        markov.a[i][i] = 1.0;
    }
    for (int i = 1; i <= notrap_next; i++) {
        for (int j = 1; j <= notrap_next; j++) {
            int u = notrap_rev[i];
            int v = notrap_rev[j];
            //printf("!%d %d\n", u, v);
            markov.a[i][j] -= (double)adj[u][v] / (double)(graph[u].size());
        }
    }
    matrix_invert(markov, notrap_next);
    for (int i = 1; i <= notrap_next; i++) {
        for (int j = 1; j <= trap_next; j++) {
            int u = notrap_rev[i];
            int v = trap_rev[j];
            notrap2trap.a[i][j] += (double)adj[u][v] / (double)(graph[u].size());
        }
    }
    matrix_mult(res, markov, notrap2trap);
    for (int i = 1; i <= trap_next; i++) {
        int node = trap_rev[i];
        for (int nxt = 1; nxt <= n; nxt++) {
            double prob_use = adj[node][nxt] / (double)(graph[node].size());
            if (hastrap[nxt]) {
                traptrans.a[i][id[nxt]] += prob_use;
            } else {
                for (int j = 1; j <= trap_next; j++) {
                    traptrans.a[i][j] += prob_use * res.a[id[nxt]][j];
                }
            }
        }
    }
    matrix_power(traptrans, k - 2);
    /*for (int i = 1; i <= trap_next; i++) {
        for (int j = 1; j <= trap_next; j++) {
            printf("%.8f ", traptrans.a[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 1; i <= trap_next; i++) {
        beginprob.a[1][i] = res.a[id[1]][i];
        //printf("%.8f ", beginprob.a[1][i]);
    }
    matrix_mult(ans, beginprob, traptrans);
    printf("%.8f", ans.a[1][id[n]]);
    return 0;
}