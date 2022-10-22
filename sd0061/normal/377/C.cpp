#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
#define N 105
int n , m , a[N] , q[25];
int f[1 << 20] , cnt[1 << 20];
char s[25][2];
void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    sort(a , a + n , greater<int>());
    scanf("%d",&m);
    for (i = m ; i > 0 ; -- i)
        scanf("%s %d", s[i] , &q[i]);
    f[0] = 0;
    for (i = 1 ; i < 1 << m; ++ i)
    {
        cnt[i] = cnt[i & (i - 1)] + 1;
        f[i] = 1 << 30;
        if (q[cnt[i]] == 1) f[i] = -f[i];
        for (j = 0 ; j < m ; ++ j)
            if (i >> j & 1)
            {
                if (*s[cnt[i]] == 'p')
                {
                    if (q[cnt[i]] == 1)
                        f[i] = max(f[i] , f[i ^ (1 << j)] + a[j]);
                    else
                        f[i] = min(f[i] , f[i ^ (1 << j)] - a[j]);
                }
                else
                {
                    if (q[cnt[i]] == 1)
                        f[i] = max(f[i] , f[i ^ (1 << j)]);
                    else
                        f[i] = min(f[i] , f[i ^ (1 << j)]);
                }
            }
    }
    printf("%d\n" , f[(1 << m) - 1]);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d",&n))
        work();
    return 0;
}