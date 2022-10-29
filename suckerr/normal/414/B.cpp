#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2005;
const int MOD = 1000000007;
int f[N][N];
int n, k;

int main() {
    scanf("%d %d", &n, &k);
    
    for(int i = 1; i <= n; i++) {
        f[1][i] = 1;
    }
    
    for(int i = 1; i < k; i++) {
        for(int j = 1; j <= n; j++) if (f[i][j]) {
            for(int k = j; k <= n; k += j) {
                (f[i + 1][k] += f[i][j]) %= MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        (ans += f[k][i]) %= MOD;
    }
    
    printf("%d\n", ans);
    return 0;
}