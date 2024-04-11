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
int n,m;
bitset<4000> f[2000];
array<int,2> a[500000];
signed main()
{
	n=read();
	m=read();
	for(int i=0;i<m;i++)
	{
		int x=read()-1,y=read()-1;
		a[i]={x,y};
		f[x][y]=1;
	}
	for(int i=0;i<n;i++)
		f[i][n+i]=1;
	for(int i=0;i<n;i++)
	{
		int now=0;
		for(int l=i;l<n;l++)
			if(f[l][i])
				now=l;
		if(i!=now)
			swap(f[i],f[now]);
		for(int l=0;l<n;l++)
			if(i!=l&&f[l][i])
				f[l]^=f[i];
	}
	for(int i=0;i<m;i++)
		if(f[a[i][1]][a[i][0]+n])
			puts("NO");
		else
			puts("YES");
	return 0;
}