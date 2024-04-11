#include<bits/stdc++.h>
#define int long long
using namespace std;
char a[2002][2002];
int n,m,ans,f[2002][2002];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=2;i<=n+1;i++)
        scanf("%s",a[i]+1);
    for(int i=2;i<=n+1;i++)
        for(int j=1;j<=m;j++)
		{
            if((a[i][j]!=a[i-1][j])||(a[i][j]!=a[i-1][j-1])||(a[i][j]!=a[i-1][j+1])||(a[i][j]!=a[i-2][j]))
				f[i][j]=1;
            else 
				f[i][j]=1+min(min(f[i-1][j-1],f[i-1][j+1]),f[i-2][j]);
            ans+=f[i][j];
        }
    cout<<ans;
    return 0;
}