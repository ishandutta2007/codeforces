#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , a[N];

void work() {
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
    }
    scanf("%d" , &m);
    LL res = 0; j = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d",&x,&y);
        res = max((LL)a[x] , res + j);
        printf("%lld\n" , res);
        j = y;
    }
}

int main() {
    work();
    return 0;
}