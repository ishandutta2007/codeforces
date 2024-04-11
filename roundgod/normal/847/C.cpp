#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
void dfs(ll x,ll y)
{
    if(y==0)
    {
        for(int i=0;i<x;i++)
            printf("()");
        return;
    }
    if(y>=x-1)
    {
        printf("(");
        dfs(x-1,y-x+1);
        printf(")");
    }
    else
    {
        printf("()");
        dfs(x-1,y);
    }
    return;
}
int main()
{
    scanf("%I64d %I64d",&n,&k);
    if(n*(n-1)/2<k)
    {
        printf("Impossible\n");
        return 0;
    }
    dfs(n,k);
    return 0;
}