#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 505;
const int Q = 1e9 + 7;
typedef long long LL;

int n , a[N] , f[N][N];

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d" , a + i);
    for (int i = 1 ; i <= n ; ++ i)
        f[i][i] = f[i][i - 1] = 1;
    for (int k = 2 ; k <= n ; ++ k) {
        for (int i = 1 , j = k ; j <= n ; ++ i , ++ j) {
            f[i][j] = 1 << 29; 
            if (a[i] == a[j])
                f[i][j] = f[i + 1][j - 1];
            for (int l = i ; l < j ; ++ l)
                f[i][j] = min(f[i][j] , f[i][l] + f[l + 1][j]);
        }
    }
    printf("%d\n" , f[1][n]);
    return 0;
}