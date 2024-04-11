#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 305;
int n , a[N] , p[N];
bool g[N][N];
char str[N];
int b[N];
bool f[N];
int main() {
    int i , j , k;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
        p[a[i]] = i;
    }
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , str + 1);
        for (j = 1 ; j <= n ; ++ j)
            g[i][j] = (str[j] == '1');
    }
    for (i = 1 ; i <= n ; ++ i)
        g[i][i] = 1;
    for (k = 1 ; k <= n ; ++ k)
        for (i = 1 ; i <= n ; ++ i)
            for (j = 1 ; j <= n ; ++ j)
                g[i][j] |= g[i][k] && g[k][j];
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= n ; ++ j) {
            if (!f[j] && g[p[j]][i]) {
                printf("%d%c" , j , " \n"[i == n]);
                f[j] = 1;
                p[a[i]] = p[j];
                swap(a[i] , a[p[j]]);
                break;
            }
        }

    }
    return 0;
}