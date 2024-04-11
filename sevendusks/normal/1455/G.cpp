/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int n,m,f,cnt,match[N],rt[N],d[N];
struct node
{
	int op,y,v;
}sh[N];
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
namespace seg
{
	int cnt;
	struct node
	{
		int ls,rs,MIN,tag;
	}sh[N*20];
	void init(){sh[0].MIN=inf;}
	void pushup(int x){sh[x].MIN=min(sh[sh[x].ls].MIN,sh[sh[x].rs].MIN);}
	void upd(int x,int v){sh[x].MIN+=v;sh[x].tag+=v;}
	void pushdown(int x)
	{
		if (sh[x].tag)
		{
			if (sh[x].ls) upd(sh[x].ls,sh[x].tag);
			if (sh[x].rs) upd(sh[x].rs,sh[x].tag);
			sh[x].tag=0;
		}
	}
	int change(int x,int l,int r,int wh,int v)
	{
		if (!x) sh[x=++cnt].MIN=inf;
		if (l==r){ckmin(sh[x].MIN,v);return x;}
		int mid=(l+r)>>1;pushdown(x);
		if (wh<=mid) sh[x].ls=change(sh[x].ls,l,mid,wh,v);
		else sh[x].rs=change(sh[x].rs,mid+1,r,wh,v);
		pushup(x);return x;
	}
	int query(int x,int l,int r,int wh)
	{
		if (!x) return inf;
		if (l==r) return sh[x].MIN;
		int mid=(l+r)>>1;pushdown(x);
		if (wh<=mid) return query(sh[x].ls,l,mid,wh);
		else return query(sh[x].rs,mid+1,r,wh);
	}
	int merge(int a,int b,int l,int r,int v,int d)
	{
		if (!a) upd(b,d);
		if (!a||!b) return a+b;
		if (l==r)
		{
			upd(b,d);
			if (l==v) sh[a].MIN=sh[b].MIN;
			else ckmin(sh[a].MIN,sh[b].MIN);
			return a;
		}
		int mid=(l+r)>>1;pushdown(a);pushdown(b);
		sh[a].ls=merge(sh[a].ls,sh[b].ls,l,mid,v,d);
		sh[a].rs=merge(sh[a].rs,sh[b].rs,mid+1,r,v,d);
		pushup(a);return a;
	}
}
void upd(int x,int y,int v)
{
	if (y==f){d[x]+=v;return;}
	int now=seg::sh[rt[x]].MIN-v;
	rt[x]=seg::change(rt[x],0,m,y,now);
	d[x]+=v;
}
void dfs(int x,int id)
{
	int ret=0;
	for (int i=x+1;i<=match[x];i++)
	{
		if (sh[i].op==1)
		{
			upd(id,sh[i].y,sh[i].v);
			continue;
		}
		if (sh[i].op==2)
		{
			int now=seg::query(rt[id],0,m,sh[i].y);
			if (now!=inf)
			{
				rt[id+1]=d[id+1]=0;
				now+=d[id];
				rt[id+1]=seg::change(rt[id+1],0,m,sh[i].y,now);
				dfs(i,id+1);
				rt[id]=seg::merge(rt[id],rt[id+1],0,m,sh[i].y,d[id+1]-d[id]);
			}
			i=match[i];
		}
	}
}
signed main()
{
	n=read();f=read();
	for (int i=1;i<=n;i++)
	{
		string ch;cin>>ch;
		if (ch=="set") sh[i]=(node){1,read(),read()};
		else if (ch=="if") sh[i]=(node){2,read(),0};
		else sh[i]=(node){3,0,0};
	}
	for (int i=1;i<=n;i++) ckmax(m,sh[i].y);
	stack <int> st;
	for (int i=1;i<=n;i++)
	{
		if (sh[i].op==2) st.push(i);
		if (sh[i].op==3)
		{
			assert(!st.empty());
			match[st.top()]=i,st.pop();
		}
	}
	match[0]=n;
	seg::init();
	rt[0]=seg::change(rt[0],0,m,0,0);
	dfs(0,0);
	printf("%lld\n",seg::sh[rt[0]].MIN+d[0]);
}