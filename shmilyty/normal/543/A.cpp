#include<bits/stdc++.h>
using namespace std;
int n,m,b,mod,ans,f[501][501],a[501];
int main()
{
	scanf("%d %d %d %d",&n,&m,&b,&mod);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=b;i++)
		f[i][0]=1;
	for(int l=1;l<=n;l++)
		for(int i=1;i<=m;i++)
			for(int j=0;j+a[l]<=b;j++)
				f[j+a[l]][i]=(f[j+a[l]][i]+f[j][i-1])%mod;
	cout<<f[b][m];
	return 0;
}