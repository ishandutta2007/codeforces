#include<bits/stdc++.h>
#define int long long
using namespace std;
int R,G,B,ans,r[201],g[201],b[201],rgb[202][202][202];
signed main()
{
	scanf("%lld %lld %lld",&R,&G,&B);
	for(int i=1;i<=R;i++)
		scanf("%lld",&r[i]);
	for(int i=1;i<=G;i++)
		scanf("%lld",&g[i]);
	for(int i=1;i<=B;i++)
		scanf("%lld",&b[i]);
	sort(r+1,r+1+R);
	sort(g+1,g+1+G);
	sort(b+1,b+1+B);
	for(int i=0;i<=R;i++)
		for(int l=0;l<=G;l++)
			for(int j=0;j<=B;j++)
			{
				rgb[i+1][l+1][j]=max(rgb[i+1][l+1][j],rgb[i][l][j]+r[i+1]*g[l+1]);
				rgb[i+1][l][j+1]=max(rgb[i+1][l][j+1],rgb[i][l][j]+r[i+1]*b[j+1]);
				rgb[i][l+1][j+1]=max(rgb[i][l+1][j+1],rgb[i][l][j]+g[l+1]*b[j+1]);
				ans=max(ans,rgb[i][l][j]);
			}
	cout<<ans;
	return 0;
}