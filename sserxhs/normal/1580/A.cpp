#include <bits/stdc++.h>
using namespace std;
const int N=402,inf=1e9;
char a[N][N];
int t,n,m,i,j,k,ans;
int s[N][N],b[N],ud[N],lr[N],pre[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	t=1;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;ans=n*m;
		for (i=1;i<=n;i++) cin>>a[i]+1;
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) a[i][j]-='0';
		for (i=1;i<=n;i++) for (j=1;j<=m;j++) s[i][j]=s[i-1][j]+a[i][j];
		for (i=1;i<=n;i++) for (j=i+4;j<=n;j++)
		{
			for (k=1;k<=m;k++) ud[k]=ud[k-1]+2-(a[i][k]+a[j][k]);
			for (k=1;k<=m;k++) lr[k]=(j-i-1)-(s[j-1][k]-s[i][k]);
			for (k=1;k<=m;k++) b[k]=s[j-1][k]-s[i][k]+b[k-1];
			pre[0]=inf;
			for (k=1;k<=m;k++) pre[k]=min(pre[k-1],lr[k]-ud[k]-b[k]);
			for (k=4;k<=m;k++) ans=min(ans,pre[k-3]+lr[k]+ud[k-1]+b[k-1]);
		}
		cout<<ans<<'\n';
	}
}