/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define ull unsigned long long
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=(1<<12)+100,Q=(1<<16)+100,B=1<<8;
int n,q,a[N],b[N],cnt,ans[Q];
ull v[N];
vector <pair<int,int> > p;
random_device rd;
mt19937_64 rnd(rd());
unordered_map <ull,int> mp;
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void write(int x)
{
	if (x>=10) write(x/10);
	putchar('0'+x%10);
}
namespace seg
{
	ull sum[N*4];
	int id[N*4];
	void pushup(int x)
	{
		sum[x]=sum[ls]^sum[rs];
		if (mp.count(sum[x])) id[x]=mp[sum[x]];
		else
		{
			assert(sum[ls]&&sum[rs]);
			id[x]=++cnt;
			p.emplace_back(id[ls],id[rs]);
			mp[sum[x]]=id[x];
		}
	}
	void build(int x,int l,int r)
	{
		sum[x]=id[x]=0;
		if (l==r) return;
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
	}
	void change(int x,int l,int r,int wh)
	{
		if (l==r)
		{
			sum[x]=v[wh];id[x]=b[wh];
			return;
		}
		int mid=(l+r)>>1;
		if (wh<=mid) change(ls,l,mid,wh);
		else change(rs,mid+1,r,wh);
		pushup(x);
	}
}
struct block
{
	int l,r,w,id[B+5][B+5],pos[B+5];
	void init()
	{
		w=r-l+1;
		mp.clear();
		for (int i=l;i<=r;i++) mp[v[i]]=b[i];
		for (int i=l;i<=r;i++) pos[i-l+1]=b[i];
		sort(pos+1,pos+w+1);
		for (int i=1;i<=w;i++)
		{
			seg::build(1,l,r);
			for (int j=i;j<=w;j++)
			{
				seg::change(1,l,r,a[pos[j]]);
				id[i][j]=seg::id[1];
			}
		}
	}
	int query(int L,int R)
	{
		int tl=lower_bound(pos+1,pos+1+w,L)-pos;
		int tr=upper_bound(pos+1,pos+1+w,R)-pos-1;
		if (tl>tr) return -1;
		return id[tl][tr];
	}
}T[N/B+10];
signed main()
{
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[a[i]]=i,v[i]=rnd();
	int w;cnt=n;
	for (int i=1,j=1;i<=n;i+=B,j++)
	{
		w=j;
		T[j].l=i;T[j].r=min(n,i+B-1);
		T[j].init();
	}
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read(),last=-1;
		for (int j=1;j<=w;j++)
		{
			int now=T[j].query(l,r);
			if (now==-1) continue;
			if (last==-1) last=now;
			else
			{
				p.emplace_back(last,now);
				last=++cnt;
			}
		}
		assert(last!=-1);
		ans[i]=last;
	}
	write(cnt);putchar('\n');
	for (auto [x,y]:p) write(x),putchar(' '),write(y),putchar('\n');
	for (int i=1;i<=q;i++) write(ans[i]),putchar(' ');
	putchar('\n');
}