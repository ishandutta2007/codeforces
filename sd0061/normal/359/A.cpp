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
typedef unsigned long long ULL;
#define N 105

int n , m , a[N][N];

void work()
{
    int i , j , ans = 4;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j])
            {
                if (i == 1)
                {
                    ans = min(ans , 2);
                    if (j == 1 || j == m)
                        ans = min(ans , 1);
                }
                if (i == n)
                {
                    ans = min(ans , 2);
                    if (j == 1 || j == m)
                        ans = min(ans , 1);
                }
                if (j == 1)
                {
                    ans = min(ans , 2);
                    if (i == 1 || i == n)
                        ans = min(ans , 1);
                }
                if (j == m)
                {
                    ans = min(ans , 2);
                    if (i == 1 || i == n)
                        ans = min(ans , 1);
                }
            }
        }
    cout << ans << endl;
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
//    freopen("output.txt" , "w" , stdout);
//    int _; scanf("%d", &_) ; while (_ --)
//    while (~scanf("%s", s))
        work();
    return 0;
}