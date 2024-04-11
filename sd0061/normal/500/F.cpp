#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 20005;
int n , p , Q;
struct item {
    int v , w , t;
    bool operator < (const item& R) const {
        return t < R.t;
    }
}a[4005];
int bel[N];
int f[4005][4005] , g[4005][4005];
int main() {
   // freopen("~input.txt" , "r" , stdin);
    int i , j , k , l , t , x , y;
    scanf("%d%d",&n,&p);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d%d",&a[i].v , &a[i].w , &a[i].t);
        -- a[i].t;
    }
    sort(a , a + n);
    int m = (20000 + p - 1) / p;
    for (i = 0 , j = 0 ; i < m ; ++ i) {
        int T = (i + 1) * p;
        int L = j , R;
        while (j < n && a[j].t < T)
            bel[j] = i , ++ j;
        R = j; //[l , r)
        if (L == R)
            continue;
        for (l = a[L].v ; l <= 4000 ; ++ l)
            f[L][l] = a[L].w;
        for (k = L + 1 ; k < R ; ++ k) {
            for (l = 0 ; l <= 4000 ; ++ l) {
                f[k][l] = f[k - 1][l];
                if (l >= a[k].v)
                    f[k][l] = max(f[k][l] , f[k - 1][l - a[k].v] + a[k].w);
            }
        }
        //printf("%d %d\n" , L , R);
        -- L , -- R;
        for (l = a[R].v ; l <= 4000 ; ++ l)
            g[R][l] = a[R].w;
        for (k = R - 1 ; k > L ; -- k) {
            for (l = 0 ; l <= 4000 ; ++ l) {
                g[k][l] = g[k + 1][l];
                if (l >= a[k].v)
                    g[k][l] = max(g[k][l] , g[k + 1][l - a[k].v] + a[k].w);
            }
        }
    }
    scanf("%d",&Q);
    while (Q --) {
        scanf("%d%d",&t,&x);
        -- t;
        int L = upper_bound(a , a + n , (item){0 , 0 , t - p}) - a;
        int R = upper_bound(a , a + n , (item){0 , 0 , t}) - a - 1;
        //printf("%d %d | %d %d | " , L , R , bel[L] , bel[R]);
        y = 0;
        if (L <= R) {
            if (bel[L] != bel[R]) {
                for (i = 0 ; i <= x ; ++ i)
                    y = max(y , g[L][i] + f[R][x - i]);
            } else {
                if (!L || bel[L] != bel[L - 1])
                    y = f[R][x];
                else
                    y = g[L][x];
            }
        }
        printf("%d\n" , y);
    }



    return 0;
}