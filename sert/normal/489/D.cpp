#include <cstdio>
#include <algorithm>
const short int N = 3001;
const short int one = 1;
const short int zero = 0;
short int a[N][N];
short int di[N][N];
short int du[N][N];
short int deg[N];
short int o[N][N];
short int dego[N], b[N];
short int n, m, v1, v2, t;
bool u[N][N];
int ans, t1, t2;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%hd%hd", &n, &m);
    for (short int i = zero; i < m; i++) {
        scanf("%hd%hd", &v1, &v2);
        v1--;
        v2--;
        u[v1][v2] = true;
        a[v1][deg[v1]++] = v2;
        o[v2][dego[v2]++] = v1;
    }

    for (short int i = 0; i < n; i++) {
        t1 = 0;
        for (short int j = 0; j < n; j++) {
            if (u[i][j] && u[j][i])
                t1++;
        }
        ans -= (t1 - 1) * t1 / 2;
    }

    for (short int i = zero; i < n; i++) {
        std::sort(a[i], a[i] + deg[i]);
        std::sort(o[i], o[i] + dego[i]);
    }
    for (short int i = zero; i < n; i++) {
        m = deg[i];
        for (short int j = zero; j < m; j++)
            b[j] = a[i][j];
        for (short int j = zero; j < m; j++) {
            t = b[j];
            for (short int k = j + one; k < m; k++) {
                di[t][b[k]]++;
            }
        }
        m = dego[i];
        for (short int j = zero; j < m; j++)
            b[j] = o[i][j];
        for (short int j = zero; j < m; j++) {
            t = b[j];
            for (short int k = j + one; k < m; k++)
                du[t][b[k]]++;
        }
    }
    for (short int i = zero; i < n; i++)
        for (short int j = i + one; j < n; j++) {
            t1 = di[i][j];
            t2 = du[i][j];
            ans += t1 * t2;
        }
    printf("%d\n", ans);
    return 0;
}