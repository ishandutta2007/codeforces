#include<cstdio>
int main()
{
    long long multi;
    int n,i,ans;
    scanf("%d",&n);
    multi=1;
    for(i=1;i<=n;i++)
    {
      multi=multi*27;
      multi=multi%1000000007;
    }
    ans=multi;
    multi=1;
        for(i=1;i<=n;i++)
    {
      multi=multi*7;
      multi=multi%1000000007;
    }
    ans=ans-multi;
    if(ans<0) ans=ans+1000000007;
    printf("%d",ans);
    return 0;
}