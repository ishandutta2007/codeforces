#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int n,m,kmp[100001],f[100001],g[100001];
char a[100001],b[100001];
bool sub(int x,int y)
{
	for(int i=x;i<=y;i++)
		if(a[i]!='?'&&a[i]!=b[i-x+1])
			return 0;
	return 1;
}
signed main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	int j=0;
	for(int i=2;i<=m;i++)
	{
		while(j&&b[j+1]!=b[i])
			j=kmp[j];
		if(b[j+1]==b[i])
			j++;
		kmp[i]=j;
	}
	for(int i=m;i<=n;i++)
	{
		if(sub(i-m+1,i))
		{
			f[i]=g[i-m];
			for(int l=kmp[m];l;l=kmp[l])
				f[i]=max(f[i],f[i-m+l]);
			f[i]++;
		}
		g[i]=max(f[i],g[i-1]);
	}
	cout<<g[n];
	return 0;
}