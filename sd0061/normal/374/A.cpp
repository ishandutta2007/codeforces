#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int N = 300005;

int n , m , x , y , a , b;

void work()
{
    scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&a,&b);
    int x1 , x2 , y1 , y2;
    if ((x - 1) % a == 0)
        x1 = (x - 1) / a;
    else
        x1 = -1;
    if ((n - x) % a == 0)
        x2 = (n - x) / a;
    else
        x2 = -1;
    if ((y - 1) % b == 0)
        y1 = (y - 1) / b;
    else
        y1 = -1;
    if ((m - y) % b == 0)
        y2 = (m - y) / b;
    else
        y2 = -1;
    int ans = 1 << 30;

    int x11 , x22 , y11 , y22;

    if (y + b <= m || y - b > 0)
        x11 = x1 % 2 , x22 = x2 % 2;
    else x11 = x1 , x22 = x2;
    if (x + a <= n || x - a > 0)
        y11 = y1 % 2 , y22 = y2 % 2;
    else y11 = y1 , y22 = y2;

    if (~x1 && ~y1 && x11 == y11)
        ans = min(ans , max(x1 , y1));
    if (~x1 && ~y2 && x11 == y22)
        ans = min(ans , max(x1 , y2));
    if (~x2 && ~y1 && x22 == y11)
        ans = min(ans , max(x2 , y1));
    if (~x2 && ~y2 && x22 == y22)
        ans = min(ans , max(x2 , y2));
    if (ans == 1 << 30)
        puts("Poor Inna and pony!");
    else
        cout << ans << endl;
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
    //while (~scanf("%d%d%d",&n,&m,&u))
        work();
    return 0;
}