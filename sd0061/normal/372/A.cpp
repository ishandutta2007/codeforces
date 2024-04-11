#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <set>
using namespace std;

#define N 500005
int n , a[N] , m , ans;
bool f[N];

void work()
{
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    sort(a , a + n) , ans = n , m = n >> 1;
    for (i = 0 , j = m ; i < m && j < n ; ++ i)
    {
        while (j < n && a[i] + a[i] > a[j])
            ++ j;
        if (j < n && a[i] + a[i] <= a[j])
            -- ans , ++ j;
    }
    cout << ans << endl;

}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //while (~scanf("%d%d%d%d",&n,&m,&C,&D))
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}