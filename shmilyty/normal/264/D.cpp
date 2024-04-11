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
int n,m,ans,a[1000001],b[1000001],L[1000001],R[1000001],f[3][3][1000001];
char s[1000001],t[1000001];
signed main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;i++)
		a[i]=s[i]%3;
	for(int i=1;i<=m;i++)
		b[i]=t[i]%3;
	a[0]=-1;
	b[0]=-1;
	for(int i=0;i<3;i++)
		for(int l=0;l<3;l++)
			for(int j=2;j<=m;j++)
			{
				f[i][l][j]=f[i][l][j-1];
				if(b[j-1]==i&&b[j]==l)
					f[i][l][j]++;
			}
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]==b[L[i-1]]&&L[i-1]<=m)
			L[i]=L[i-1]+1;
		else
			L[i]=L[i-1];
		R[i]=min(m,R[i-1]+1);
		while(R[i]<m&&a[i]!=b[R[i]])
			R[i]++;
		ans+=R[i]-L[i]+1;
		if(i!=1&&a[i]!=a[i-1])
			ans-=f[a[i]][a[i-1]][R[i]]-f[a[i]][a[i-1]][L[i]-1];
	}
	cout<<ans;
	return 0;
}