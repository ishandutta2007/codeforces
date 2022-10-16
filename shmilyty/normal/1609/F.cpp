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
const int N=1e6+10;
int n,ans,now,tmx,tmn,k,a[N],b[N],mx[N],mn[N],num[N];
#define lowbit(x) (x&(-x))
struct node{
	int t[2][N];
	void init()
	{
		memset(t,0,sizeof(t));
	}
	void modify(int x,int y)
	{
		for(int z=x*y;x<=n;x+=lowbit(x))
		{
			t[0][x]+=y;
			t[1][x]+=z;
		}
	}
	int query(int x)
	{
		int u=0,v=0;
		for(int i=x;i;i^=lowbit(i))
		{
			u+=t[0][i];
			v+=t[1][i];
		}
		return u*(x+1)-v;
	}
	void ad(int l,int r,int v)
	{
		modify(l,v);
		modify(r+1,-v);
	}
	int sum(int l,int r)
	{
		return query(r)-query(l-1);
	}
}T[2];
void add(bool f,int l,int r,int v)
{
	now+=v*T[!f].sum(l,r);
	T[f].ad(l,r,v);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		num[i]=__builtin_popcountll(a[i]);
	}
	for(int i=0;i<64;i++)
	{
		bool ok=1;
		for(int l=1;l<=n;l++)
			if(num[l]==i)
			{
				ok=0;
				break;
			}
		if(ok)
			continue;
		T[0].init();
		T[1].init();
		tmx=tmn=now=0;
		for(int l=1;l<=n;l++)
		{
			if(num[l]==i)
				b[l]=1;
			else
				b[l]=0;
			while(tmx&&a[k=mx[tmx]]<=a[l])
			{
				tmx--;
				if(b[k]^b[l])
				{
					if(b[k])
						add(0,mx[tmx]+1,k,-1);
					else
						add(0,mx[tmx]+1,k,1);
				}
			}
			while(tmn&&a[k=mn[tmn]]>=a[l])
			{
				tmn--;
				if(b[k]^b[l])
				{
					if(b[k])
						add(1,mn[tmn]+1,k,-1);
					else
						add(1,mn[tmn]+1,k,1);
				}
			}
			mx[++tmx]=l;
			mn[++tmn]=l;
			if(b[l])
			{
				add(0,l,l,1);
				add(1,l,l,1);
			}
			ans+=now;
		}
	}
	cout<<ans<<endl;
	return 0;
}