#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 505;
int n , m , a[N] , g[N][N];

void work() {
    int i , j , x , y , z;
    double ans = 0;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&j);
        g[x][y] = g[y][x] = j;
        ans = max(ans , 1.0 * (a[x] + a[y]) / j);
    }
    printf("%.20f\n" , ans);
}

int main()
{
    work();
    return 0;
}