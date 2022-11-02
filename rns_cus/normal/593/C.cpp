#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

const int maxn = 51;
int x[maxn],y[maxn],r[maxn];
int n;

void input()
{
    scanf("%d",&n);
    for (int i = 1;i <= n;++ i)
        scanf("%d%d%d",&x[i],&y[i],&r[i]);
}

void f(int *a)
{
    for (int i = 1;i < n;++ i)
        printf("(");
    for (int i = 1;i <= n;++ i)
    {
        int k = a[i] / 2;
        printf("(%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))",k,i,i);
        if (i != 1)
            printf(")");
        if (i != n)
            printf("+");
    }
    printf("\n");
}

void solve()
{
    f(x);
    f(y);
}

int main()
{
    input();
    solve();
    return 0;
}