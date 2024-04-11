#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n , m , a[N + N];
LL s[N + N];
int f[N];
int cal(LL W) {
    int i , j , k = 1;
    for (i = 1 , j = 1 ; i <= n ; ++ i) {
        while (j - i < n && s[j] - s[i - 1] <= W)
            ++ j;
        f[i] = j - i;
        if (f[i] < f[k])
            k = i;
    }
    int res = 1 << 30;
    for (i = k ; i <= k + f[k] ; ++ i) {
        int delta = 0 , x = (i - 1) % n + 1 , y = 0;
        while (delta < n) {
            delta += f[x];
            x += f[x];
            ++ y;
            if (x > n)
                x -= n;
        }
        res = min(res , y);        
    }
    return res;
    
}
void work() {
    int i , j , k , x , y;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        a[i + n] = a[i];
    }
    for (i = 1 ; i <= n + n ; ++ i)
        s[i] = s[i - 1] + a[i];
    for (i = 1 ; i <= m ; ++ i) {
        LL W;
        scanf("%lld" , &W);
        printf("%d\n" , cal(W));
    }    
}

int main() {
    work();
    return 0;
}