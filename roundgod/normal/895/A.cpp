#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int a[MAXN];
int pre[MAXN],suf[MAXN];
int n,k;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    pre[0]=0;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+a[i];
    suf[n+1]=0;
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+a[i];
    int ans=180;
    for(int i=0;i<=n;i++)
        for(int j=i+1;j<=n+1;j++)
           ans=min(ans,max(suf[j]+pre[i]-180,180-suf[j]-pre[i]));
    printf("%d\n",ans*2);
    return 0;
}