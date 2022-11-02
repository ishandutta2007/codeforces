#include<bits/stdc++.h>
#define N 2005
using namespace std;
int n,a[N],s[2][N],f[N][N],mx1,mx2,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
    scanf("%d",a+i),a[i]--,s[a[i]][i]=1,
    s[0][i]+=s[0][i-1],s[1][i]+=s[1][i-1];
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    if(j==i)f[i][i]=1;
    else f[i][j]=(a[j]==1)?f[i][j-1]+1:max(f[i][j-1],s[0][j]-s[0][i-1]);
    for(int i=1;i<=n;i++)
    {
        mx1=mx2=0;
        for(int j=i;j;j--)
        mx1=max(mx1,f[j][i]);
        for(int j=i+1;j<=n;j++)
        mx2=max(mx2,f[i+1][j]);
        ans=max(ans,mx1+mx2);
    }
    printf("%d",ans);
}