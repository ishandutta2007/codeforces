#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long LL;
#define N 100005
int n , m , a[N] , b[N];
int nxt[N] , pre[N] , f[N];

void work() {
    int i , j , k;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    sort(a + 1 , a + n + 1);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d",&b[i]);
    sort(b , b + m);
    a[0] = a[n + 1] = -1;
    for (i = 1 ; i <= n ; ++ i)
        pre[i] = a[i] == a[i - 1] + 1 ? pre[i - 1] : i;
    for (i = n ; i >= 1 ; -- i)
        nxt[i] = a[i] == a[i + 1] - 1 ? nxt[i + 1] : i;
    for (i = 1; i <= n ; ++ i) {
        int l = upper_bound(b , b + m , a[i]) - b - 1;
        int t = f[i - 1];
        for (j = l ; j >= 0 ; -- j) {
            k = i - (a[i] - b[j]);
            if (k <= 0) break;
            t = max(t , f[pre[k] - 1] + l - j + 1);
        }
        f[i] = max(f[i], t);
        for (j = l + 1; j < m; ++ j) {
            k = i + b[j] - a[i];
            if (k > n) break;
            f[nxt[k]] = max(f[nxt[k]], t + j - l);
        }
    }
    printf("%d\n", f[n]);
}

int main()
{
    work();
    return 0;
}