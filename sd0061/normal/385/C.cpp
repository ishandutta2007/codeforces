#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

#define N 10000005
#define M 10000000
int n , m , a[N];
bool f[N];
long long sum[N];

void work()
{
    int i , j;
    f[1] = 1;
    for (i = 2 ; i * i <= M ; ++ i) if (!f[i])
        for (j = i * i ; j <= M ; j += i) f[j] = 1;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&j) , ++ a[j];
    scanf("%d" ,&m);
    for (i = 1 ; i <= M ; ++ i)
    {
        if (!f[i])
        {
            for (j = i ; j <= M ; j += i)
                sum[i] += a[j];
        }
        sum[i] += sum[i - 1];
    }
    while (m --)
        scanf("%d%d",&i,&j) , j = min(j , M) , i = min(i , M) ,  printf("%I64d\n" , sum[j] - sum[i - 1]);
}

int main()
{
   //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}