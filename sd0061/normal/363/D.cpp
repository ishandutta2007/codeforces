#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define N 200005

int n , m , a;
int b[N] , p[N];
long long sum;
bool check(int val)
{
    long long x = 0 , y = 0; sum = 0;
    for (int i = 1 ; i <= val ; ++ i)
    {
        if (b[i] >= p[val - i + 1])
            x += p[val - i + 1] , y += p[val - i + 1];
        else
            x += b[i] , y += p[val - i + 1];
    }
    sum = max(0LL , y - a);
    return x + a >= y;
}

void work()
{
    int i , j;
    long long ans = 0 , tmp , x = 0 , y = 0;

    scanf("%d%d%d",&n,&m,&a);
    tmp = a;

    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&b[i]);
    for (i = 1 ; i <= m ; ++ i)
        scanf("%d",&p[i]);
    sort(b + 1 , b + n + 1 , greater<int>());
    sort(p + 1 , p + m + 1);

    int top = 0 , bot = min(n , m) , mid;
    while (top < bot)
    {
        mid = top + bot + 1 >> 1;
        if (check(mid))
            top = mid;
        else bot = mid - 1;
    }
    check(top);
    cout << top << ' ' << sum << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d%d",&n,&m,&k))
        work();
    return 0;
}