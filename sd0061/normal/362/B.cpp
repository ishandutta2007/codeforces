#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 100005

int n , m , a[N];

void work()
{
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d",&a[i]);
    sort(a , a + m);
    if (a[0] == 1 || a[m - 1] == n)
        puts("NO");
    else
    {
        for (i = 1 ; i + 1 < m ; ++ i)
            if (a[i] == a[i - 1] + 1 && a[i] == a[i + 1] - 1)
                break;
        if (i + 1 < m)
            puts("NO");
        else puts("YES");
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d",&n,&T))
        work();
    return 0;
}