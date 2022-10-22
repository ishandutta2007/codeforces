#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 100005
int n , m , a[N] , b[N];

void work()
{
    int i , j , x , ans;
    scanf("%d%d",&n,&m) , ans = n;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    sort(a , a + n);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d",&b[i]);
    sort(b , b + m);
    for (i = j = 0 ; j < n && i < m ; ++ i)
        if (b[i] >= a[j])
            -- ans , ++ j;
    printf("%d\n" , ans);
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //init();

    //while (~scanf("%d",&n))
        work();
    return 0;
}