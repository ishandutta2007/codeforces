#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 250;
LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x >> 1);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD;
}
LL inv(int x) {
    return mpow(x, MOD - 2);
}
int r, T; LL p[4];
int idx[N][N], px[1000000 + 10], py[1000000 + 10];
struct Mat {
    int n; 
    int a[7850][7850]; // 1-index, col n+1 is b
    void gauss() {
        for (int i = 1; i <= n; i ++) {
            //int p = -1;
            //for (int j = i; j <= n; j ++) if (a[j][i]) p = j;
            //if (p == -1) return;
            //for (int j = i; j <= n + 1; j ++) swap(a[i][j], a[p][j]);

            //printf("i = %d, p = %d, dt = %d\n", i, p, p - i);
            //mx = max(mx, p - i);
            //printf("mx = %d\n", mx);
            for (int j = i + 1; j <= min(n, i + 110); j ++) {
                if (a[j][i] == 0) continue;
                LL cof = (- 1LL * a[j][i] * inv(a[i][i]) % MOD + MOD) % MOD;
                for (int k = i; k <= min(n, i + 110); k ++) {
                    a[j][k] = ((a[j][k] + 1LL * a[i][k] * cof) % MOD + MOD) % MOD; 
                }
                a[j][n+1] = ((a[j][n+1] + 1LL * a[i][n+1] * cof) % MOD + MOD) % MOD; 
            }
        }
        for (int i = n; i >= 1; i --) {
            LL iv = inv(a[i][i]);
            for (int j = i - 1; j >= max(1, i - 110); j --) {
                if (a[j][i] == 0) continue;
                LL cof = (- 1LL * a[j][i] * iv % MOD + MOD) % MOD;
                a[j][i] = ((a[j][i] + cof * a[i][i]) % MOD + MOD) % MOD;
                a[j][n+1] = ((a[j][n+1] + 1LL * cof * a[i][n+1]) % MOD + MOD) % MOD;
            }
            a[i][n+1] = 1LL * a[i][n+1] * inv(a[i][i]) % MOD;
            a[i][i] = 1;
        }
    }
    void debug() {
        printf("n = %d\n", n);
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) {
                printf("%d ", a[i][j]);
            }
            printf("| %d\n", a[i][n+1]);
        }
    }
} A;
void build_Equations() {
    int tot = 0;
    for (int i = -r; i <= r; i ++) {
        for (int j = -r; j <= r; j ++) {
            if (i * i + j * j <= r * r) {
                idx[i + r][j + r] = ++ tot;
                px[tot] = i, py[tot] = j;
            }
        }
    }
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    A.n = tot;
    for (int i = -r; i <= r; i ++) {
        for (int j = -r; j <= r; j ++) {
            if (i * i + j * j <= r * r) {
                int row = idx[i + r][j + r];
                for (int k = 0; k < 4; k ++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni * ni + nj * nj <= r * r) {
                        A.a[row][ idx[ni + r][nj + r] ] = MOD - p[k];
                    }
                }
                A.a[row][tot + 1] = A.a[row][row] = (p[0] + p[1] + p[2] + p[3]);
            }
        }
    }
    A.gauss();
    printf("%d\n", A.a[idx[r][r]][tot + 1]);
}
int main() {
    cin >> r >> p[0] >> p[1] >> p[2] >> p[3];
    build_Equations();
}