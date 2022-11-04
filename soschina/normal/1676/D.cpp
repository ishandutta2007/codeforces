#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 401;

int t, n, m, a[N][N], r[N], c[N];

int main(){
    scanf("%d", &t);
    while(t--){
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++){
                scanf("%d", &a[i][j]);
                r[i + j] += a[i][j];
                c[i - j + m] += a[i][j];
            }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                ans = max(ans, r[i + j] + c[i - j + m] - a[i][j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}