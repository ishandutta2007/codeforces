#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 405;

int n , K , a[N];
LL s[N] , f[55][N][N];

void work() {
    int i , j , k , l;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    memset(f , 0xC0 , sizeof(f));
    for (i = 1 ; i <= n ; ++ i)
        for (j = 0 ; j < i ; ++ j)
            f[1][i][j] = 0;
    for (i = 1 ; i < K ; ++ i) {
        for (j = 1 ; j + K - i <= n ; ++ j)
            for (k = 0 ; k < j ; ++ k) {
                if (f[i][j][k] < 0)  continue;
                for (l = j + 1 ; l + K - i - 1 <= n ; ++ l) {
                    LL val = f[i][j][k] + abs(s[k] + s[l] - s[j] - s[j]);
                    f[i + 1][l][j] = max(f[i + 1][l][j] , val);
                }
            }
    }
    LL res = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 0 ; j < i ; ++ j)
            res = max(res , f[K][i][j]);
    cout << res << endl;
}

int main() {
//    freopen("1" , "r" , stdin);
    work();
    return 0;
}