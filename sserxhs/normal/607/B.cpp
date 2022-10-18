#include <bits/stdc++.h>
using namespace std;
const int N=502;
int a[N],f[N][N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n,i,j,k,l,r;
	cin>>n;
	memset(f,0x3f,sizeof f);
	for (i=1;i<=n;i++) cin>>a[i],f[i][i]=1;
	for (k=1;k<n;k++) for (l=1;(r=l+k)<=n;l++)
	{
		if (a[l]==a[r]) f[l][r]=l+1==r?1:f[l+1][r-1];
		for (i=l;i<r;i++) f[l][r]=min(f[l][r],f[l][i]+f[i+1][r]);
	}
	assert(f[1][n]!=f[0][0]);
	cout<<f[1][n]<<endl;
}