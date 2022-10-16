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
int n,q,cnt,a[300010],t[30][300001],f[30][600001];
mt19937 rng(time(NULL));
map<int,int> mp;
void modify(int id,int x,int v)
{
	for(;x<=n;x+=lowbit(x))
		t[id][x]+=v;
}
int query(int id,int x)
{
	int y=0;
	for(;x;x^=lowbit(x))
		y+=t[id][x];
	return y;
}
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(!mp.count(a[i]))
		{
			mp[a[i]]=++cnt;
			for(int l=0;l<30;l++)
				f[l][cnt]=rng();
		}
		int x=mp[a[i]];
		for(int l=0;l<30;l++)
			modify(l,i,f[l][x]);
	}
	while(q--)
	{
		int opt=read(),l=read(),r=read();
		if(opt&1)
		{
			int x=mp[a[l]];
			for(int i=0;i<30;i++)
				modify(i,l,-f[i][x]);
			a[l]=r;
			if(!mp.count(r))
			{
				mp[r]=++cnt;
				for(int i=0;i<30;i++)
					f[i][cnt]=rng();
			}
			x=mp[a[l]];
			for(int i=0;i<30;i++)
				modify(i,l,f[i][x]);
		}
		else
		{
			bool ok=1;
			int k=read();
			for(int i=0;i<30;i++)
				if((query(i,r)-query(i,l-1))%k)
				{
					ok=0;
					break;
				}
			if(ok)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}