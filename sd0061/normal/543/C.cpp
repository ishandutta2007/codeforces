#include <bits/stdc++.h>
using namespace std;
const int N = 24;

int n , m , a[N][N] , f[1 << 20];
char str[N][N];


void work() {
    int i , j , k , x;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n ; ++ i)
        scanf("%s" , str[i]);
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < m ; ++ j)
            scanf("%d" , &a[i][j]);
    for (i = 1 ; i < 1 << n ; ++ i) {
        x =__builtin_ctz(i & -i);
        f[i] = 1 << 30;
        for (j = 0 ; j < m ; ++ j) {
            f[i] = min(f[i] , f[i ^ (1 << x)] + a[x][j]);
            int sum = 0 , mx = 0 , mask = 0;
            for (k = 0 ; k < n ; ++ k) {
                if (str[k][j] == str[x][j]) {
                    sum += a[k][j];
                    mx = max(mx , a[k][j]);
                    mask |= 1 << k;
                }
            }
            f[i] = min(f[i] , f[i & (i ^ mask)] + sum - mx); 
        }
    }
    cout << f[(1 << n) - 1] << endl;
}

int main() {
    work();
    return 0;
}