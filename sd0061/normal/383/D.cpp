#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n , f[2][20005] , Q = 1e9 + 7;
void work()
{
    int i , j , x , ans = 0;
    scanf("%d",&n);
    int cur = 0 , nxt = 1;
    for (i = 0 ; i < n ; ++ i)
    {
        scanf("%d",&x);
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (j = 0 ; j <= 20000 ; ++ j)
            if (f[cur][j])
            {
                f[nxt][j + x] += f[cur][j] , f[nxt][j + x] %= Q;
                f[nxt][j - x] += f[cur][j] , f[nxt][j - x] %= Q;
            }
        ++ f[nxt][10000 + x] , ++ f[nxt][10000 - x];
        swap(nxt , cur) , ans += f[cur][10000] , ans %= Q;
    }
    printf("%d\n" , ans);
}

int main()
{
    work();
    return 0;
}