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
#define N 2005
int n , m ;
bool r[N] , c[N];
double f[N][N];

double F(int x , int y)
{
    if (x == n && y == n) return 0;
    if (x > n || y > n) return 0;
    if (f[x][y] > 1e-9) return f[x][y];
    f[x][y] += F(x + 1 , y) * (n - x) * y;
    f[x][y] += F(x , y + 1) * (n - y) * x;
    f[x][y] += F(x + 1 , y + 1) * (n - x) * (n - y);
    f[x][y] += n * n;
    f[x][y] /= n * n - x * y;
    return f[x][y];
}
void work()
{
    int i , x , y;
    scanf("%d%d",&n,&m);
    while (m --)
        scanf("%d%d",&x,&y) , r[x] = c[y] = 1;
    x = y = 0;
    for (i = 1 ; i <= n ; ++ i)
        x += r[i] , y += c[i];
    printf("%f\n" , F(x , y));
}

int main()
{
    work();
    return 0;
}