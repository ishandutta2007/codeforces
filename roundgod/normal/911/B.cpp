#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,a,b;
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    int ans=-INF;
    for(int i=1;i<=n-1;i++)
        ans=max(ans,min(a/i,b/(n-i)));
    printf("%d\n",ans);
    return 0;
}