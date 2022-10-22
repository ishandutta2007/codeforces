#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long LL;

#define N 100005
int n , m;
struct Point {
    LL x , y;
    Point () {}
    Point (LL A , LL B) {
        x = A , y = B;
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);
    }
    LL operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
}a[N];

int f[17][N] , dep[N];
int s[N] , top;
void work()
{
    int i , j , x , y;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%I64d%I64d",&a[i].x , &a[i].y);
    }
    for (i = n ; i >= 1 ; -- i) {
        while (top > 1 && ((a[s[top - 1]] - a[i]) ^ (a[s[top]] - a[s[top - 1]])) < 0)
            s[top --] = 0;
        f[0][i] = s[top] ;
        dep[i] = dep[s[top]] + 1;
        s[++ top] = i;
    }
    for (j = 1 ; j <= 16 ; ++ j)
        for (i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    scanf("%d",&m);
    while (m --) {
        scanf("%d%d",&x,&y);
        if (dep[x] < dep[y]) swap(x , y);
        for (i = 16 ; i >= 0 ; -- i)
            if (dep[x] - dep[y] >> i & 1)
                x = f[i][x];
        if (x == y)
            printf("%d " , y);
        else {
            for (i = 16 ; i >= 0 ; -- i)
                if (f[i][x] != f[i][y])
                    x = f[i][x] , y = f[i][y];
            printf("%d " , f[0][x]);
        }
    }
}

int main()
{
    work();
    return 0;
}