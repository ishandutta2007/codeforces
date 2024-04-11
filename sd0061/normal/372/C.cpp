#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
#define N 150005
#define M 305
int n , m , d;
int a[M] , b[M] , t[M];
int q[N] , top , bot;
LL sum , f[2][N];
void work()
{
    int i , j , k , l , r;
    scanf("%d%d%d",&n,&m,&d);
    for (i = 1 ; i <= m ; ++ i)
        scanf("%d%d%d",&a[i],&b[i] , &t[i]) , sum += b[i];
    int cur = 0 , nxt = 1;
    for (i = 1 ; i <= n ; ++ i)
        f[0][i] = 0;
    for (k = 1 ; k <= m ; ++ k)
    {
        top = 0 , bot = -1;
        LL T = (LL)(t[k] - t[k - 1]) * d;
        for (i = 1 ; i <= (int)min(T , (LL)n) ; ++ i)
        {
            while (top <= bot && f[cur][q[bot]] >= f[cur][i])
                -- bot;
            q[++ bot] = i;
        }
        for (i = 1 ; i <= n ; ++ i)
        {
            l = (int)max(1LL , i - T);
            r = (int)min((LL)n , i + T);
            if (i + T <= n)
            {
                while (top <= bot && f[cur][q[bot]] >= f[cur][i + T])
                    -- bot;
                q[++ bot] = i + T;
            }
            while (top <= bot && q[top] < l)
                ++ top;
            f[nxt][i] = f[cur][q[top]] + abs(a[k] - i);
        }
        swap(nxt , cur);
    }
    LL ans = 1LL << 60;
    for (i = 1 ; i <= n ; ++ i)
        ans = min(ans , f[cur][i]);
    cout << sum - ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //while (~scanf("%d%d%d%d",&n,&m,&C,&D))
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}