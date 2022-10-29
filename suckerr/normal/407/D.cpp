#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 401;

int a[N][N], f[N][N][N];
int tHash[222222], times = 0, pos[N * N];
int n, m, ans;

int main() {
    scanf("%d %d", &n, &m); 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", a[i] + j);
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            for(int k = 1; k <= m; k++)
                f[i][j][k] = m + 1;
    
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) {
            ++times;
            for(int k = m; k >= 1; k--) {
                if (tHash[a[i][k]] == times) {
                    f[i][j][k] = min(f[i][j][k], pos[a[i][k]]);
                }
                tHash[a[i][k]] = times;
                pos[a[i][k]] = k;
                if (i == j)
                    continue;
                if (tHash[a[j][k]] == times) {
                    f[i][j][k] = min(f[i][j][k], pos[a[j][k]]);
                }
                tHash[a[j][k]] = times;
                pos[a[j][k]] = k;
            }
        }

    ans = 0;    
    for(int i = m; i >= 1; i--) {
        for(int length = 1; length <= n; length++)
            for(int j = 1; j + length - 1 <= n; j++) {
                int k = j + length - 1;
                ans = max(ans, length * (f[j][k][i] - i));
                if (j > 1) {
                    f[j - 1][k][i] = min(f[j - 1][k][i], f[j][k][i]);
                }
                if (k < n) {
                    f[j][k + 1][i] = min(f[j][k + 1][i], f[j][k][i]);
                }
                if (i > 1) {
                    f[j][k][i - 1] = min(f[j][k][i - 1], f[j][k][i]);
                }
            }
    }
    printf("%d\n", ans);
    return 0;
}