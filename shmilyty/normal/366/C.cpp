#include <bits/stdc++.h>
#define N 50005
using namespace std;
int a[N],v[N],f[100][N],m,n,k,t;
int main()
{
	cin>>n>>k;
	m=n*100;
	memset(f,-0x7f,sizeof(f));
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>t,v[i]=a[i]-t*k;
	f[0][m]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=2*m;j++)
			f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+a[i]);
	cout<<(f[n][m]==0?-1:f[n][m]);
	return 0;
}