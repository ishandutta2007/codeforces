#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,a[5010],f[5010][5010],q[5010],g[5010],pre[5010];
array<int,2> b[5010];
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		b[i]={x,y};
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++)
		pre[i]=pre[i-1]+b[i][1];
	if(pre[m]<n)
	{
		puts("-1");
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	//cout<<f[1][1]<<'\n';
	f[0][0]=0;
	memset(q,0,sizeof(q));
	memset(g,0,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int l=0,r=0;
		f[i][0]=0;
		q[++r]=0;
		for(int j=1;j<=min(n,pre[i]);j++)
		{
			f[i][j]=f[i-1][j];
			g[j]=g[j-1]+abs(a[j]-b[i][0]);
			// cout<<g[j]<<'\n';
			while(l<=r&&((j-q[l]>b[i][1])||f[i-1][q[l]]-g[q[l]]>f[i-1][j]-g[j]))
			{
				//cout<<j-q[l]<<" "<<b[i][1]<<'\n';
				l++;
			}
			// cout<<b[i][1]<<'\n';
			//cout<<l<<" "<<q[l]<<'\n';
			q[++r]=j;
			f[i][j]=min(f[i][j],g[j]-g[q[l]]+f[i-1][q[l]]);
		}
	}
	cout<<f[m][n];
	return 0;
}