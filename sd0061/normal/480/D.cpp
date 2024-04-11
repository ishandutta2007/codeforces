#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
int n , S;
struct pack {
    int l , r , w , s , v;
    bool operator < (const pack& R) const {
        return make_pair(r , -l) < make_pair(R.r , -R.l);
    }
}a[N];
int f[N][N + N];
int g[N + N];

void work() {
    int i , j , k , l;
    scanf("%d%d",&n,&S);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d%d%d%d%d",&a[i].l,&a[i].r,&a[i].w,&a[i].s,&a[i].v);
    a[++ n] = (pack) {0 , n + n , 0 , S , 0};
    sort(a + 1 , a + n + 1);
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 0 ; j <= a[i].s ; ++ j) {
            if (j) f[i][j] = f[i][j - 1];
            memset(g , 0 , sizeof(g));
            for (l = a[i].l + 1 , k = 1; l <= a[i].r ; ++ l) {
                g[l] = g[l - 1];
                while (k < i && a[k].r <= l) {
                    if (a[k].r == l && a[k].l >= a[i].l && a[k].w <= j)
                        g[l] = max(g[l] , g[a[k].l] + f[k][min(j - a[k].w , a[k].s)]);
                    ++ k;
                }
            }
            f[i][j] = max(f[i][j] , g[a[i].r] + a[i].v);
        }
    }
    printf("%d\n" , f[n][S]);
}

int main()
{
    work();
    return 0;
}