#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define N 105
int n , a[N] , s[N] , sum;
void work()
{
    int i , j , x;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    sort(a , a + n);

    for (i = 0 ; i < n ; ++ i)
    {
        x = -1;
        for (j = 0 ; j < sum ; ++ j)
            if (a[i] >= s[j])
                if (x == -1 || s[j] < s[x])
                    x = j;
        if (x == -1)
            s[sum ++] = 1;
        else
            ++ s[x];
    }
    printf("%d\n" , sum);
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
//    int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}