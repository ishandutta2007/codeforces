#include <bits/stdc++.h>
using namespace std;
int dp[1000000];
int a[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    int last=-1;
    int num=-1;
    dp[0]=-1;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&a[i]);
        if (a[i]==a[i-1])
            dp[i]=dp[i-1];
        else
            dp[i]=i-1;
    }
    for (int i=1;i<=m;i++)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
            if (a[r]==x)
            {

        if (dp[r]<l)
            printf("-1\n");
            else
                printf("%d\n",dp[r]);
            }
            else
                printf("%d\n",r);

    }
}