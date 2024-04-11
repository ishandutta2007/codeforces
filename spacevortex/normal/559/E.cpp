#include<bits/stdc++.h>
#define cmax(a,b) a=max(a,b)
using namespace std;
int rd()
{
	int rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const int N=210;
int n,m=0,ans=0;
int dp[N][N];
struct Node{int id,l,r;}p[N];
bool cmp(const Node &a,const Node &b){return a.r<b.r;}
int main()
{
	ios::sync_with_stdio(false);
	int i,j,k,w,l;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>w>>l;
		p[++m]=(Node){i,w-l,w};
		p[++m]=(Node){i,w,w+l};
	}
	sort(p+1,p+m+1,cmp);
	for(i=1;i<=m;i++) dp[i][0]=p[i].r-p[i].l;
	p[0].id=0;p[0].l=-5e8;p[0].r=-5e8;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<i;j++)
		{
			cmax(ans,dp[i][j]);
			for(k=i+1;k<=m;k++)
			{
				if(p[k].id==p[i].id||p[k].id==p[j].id||p[k].l<=p[j].r||p[k].l<=p[i].l) continue;
				cmax(dp[k][i],dp[i][j]+p[k].r-max(p[i].r,p[k].l));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}