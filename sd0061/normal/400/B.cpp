#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 1004
int n , m;
char s[N][N];
int a[N];
void work()
{
    int i , j ;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" ,s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
    {
        int x , y;
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == 'G')
                x = j;
            else if (s[i][j] == 'S')
                y = j;
        if (y < x)
            break;
        a[i] = y - x;
    }
    if (i <= n)
    {
        puts("-1");
        return;
    }
    sort(a + 1 , a + n + 1);
    printf("%d\n" , unique(a + 1 , a + n + 1) - a - 1);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}