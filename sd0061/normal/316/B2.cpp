#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
int n , K , a[N] , m , b[N] , id , c[N];
bool f[N];

void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&K);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        if (a[i]) b[a[i]] = i;
    }
    for (i = 1 ; i <= n ; ++ i) {
        if (a[i]) continue;
        x = i , y = 0 , j = 0;
        while (x) {
            ++ y;
            if (x == K)
                id = y , j = 1;
            x = b[x];
        }
        if (!j)
            c[m ++] = y;
    }
    memset(f , 0 , sizeof(f));
    f[0] = 1;
    for (i = 0 ; i < m ; ++ i) {
        for (j = n ; j >= c[i] ; -- j)
            f[j] |= f[j - c[i]];
    }
    for (i = 0 ; i <= n ; ++ i)
        if (f[i])
            printf("%d\n" , i + id);
}

int main() {
    work();
    return 0;
}