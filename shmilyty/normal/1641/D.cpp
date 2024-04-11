#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=INT_MAX;
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
array<int,6> a[100001];
int n,m,ans=INF;
const int N=12000;
bitset<N> b;
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		for(int l=1;l<=m;l++)
			a[i][l]=read();
		a[i][0]=read();
	}
	sort(a+1,a+1+n);
	for(int i=0;i<=n/N;i++)
	{
		int l=max(i*N,1),r=min(i*N+N-1,n);
		if(l>=r||a[l][0]+a[l+1][0]>=ans)
			break;
		unordered_map<int,bitset<N>> mp;
		for(int k=l;k<=r;k++)
			for(int j=1;j<=m;j++)
				mp[a[k][j]][k-l]=1;
		for(int j=1;j<=n;j++)
		{
			if(a[l][0]+a[j][0]>=ans)
				break;
			b.set();
			int x=0;
			for(int k=1;k<=m;k++)
			{
				if(mp.find(a[j][k])!=mp.end())
					b&=~mp[a[j][k]];
				x=b._Find_first();
				if(l+x>r)
					break;
			}
			if(l+x<=r)
				ans=min(ans,a[j][0]+a[l+x][0]);
		}
	}
	if(ans==INF)
		ans=-1;
	cout<<ans;
	return 0;
}