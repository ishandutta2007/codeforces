#include<bits/stdc++.h>
using namespace std;
namespace red{
#define int long long
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define y1 qwq 
	inline int read()
	{
		int x=0;char ch,f=1;
		for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
		if(ch=='-') f=0,ch=getchar();
		while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
		return f?x:-x;
	}
	const int N=2e5+10,inf=1ll<<60;
	int n,tmp[N];
	struct node
	{
		int x,y;
	}s[N];
	inline bool cmp(const node &a,const node &b)
	{
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
	inline bool cmps(const int &a,const int &b)
	{
		return s[a].y<s[b].y;
	}
	inline int dist(int i,int j)
	{
		return (s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y);
	}
	inline int solve(int l,int r)
	{
		int d=inf;
		if(l==r) return d;
		if(l+1==r) return dist(l,r);
		int mid=(l+r)>>1;
		int d1=solve(l,mid);
		int d2=solve(mid+1,r);
		d=min(d1,d2);
		int top=0;
		for(int i=l;i<=r;++i)
			if((s[mid].x-s[i].x)*(s[mid].x-s[i].x)<=d) tmp[++top]=i;
		sort(tmp+1,tmp+top+1,cmps);
		for(int i=1;i<=top;++i)
			for(int j=i+1;j<=top&&(s[tmp[j]].y-s[tmp[i]].y)*(s[tmp[j]].y-s[tmp[i]].y)<d;++j)
				d=min(d,dist(tmp[i],tmp[j]));
		return d;
	}
	inline void main()
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			s[i].x=i,s[i].y=s[i-1].y+read();
		}
		printf("%lld\n",solve(1,n));
	}
}
signed main()
{
	red::main();
	return 0;
}