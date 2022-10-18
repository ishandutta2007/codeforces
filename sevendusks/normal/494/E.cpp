/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e5+100;
int n,m,k,b[N<<1],w,pre[40],suc[40];
struct node
{
	int a,b,c,d;
}sh[N];
vector <tuple<int,int,int> > p[N<<1];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
namespace seg
{
	struct node
	{
		int ls,rs,cnt,ans;
	}sh[N*32];
	int cnt;
	void pushup(int x,int l,int r)
	{
		if (sh[x].cnt) sh[x].ans=r^(r>>1)^(l-1)^((l-1)>>1);
		else sh[x].ans=sh[sh[x].ls].ans^sh[sh[x].rs].ans;
	}
	int change(int x,int l,int r,int ll,int rr,int v)
	{
		if (!x) x=++cnt;
		if (ll<=l&&rr>=r)
		{
			sh[x].cnt+=v;
			pushup(x,l,r);
			return x;
		}
		int mid=(l+r)>>1;
		if (ll<=mid) sh[x].ls=change(sh[x].ls,l,mid,ll,rr,v);
		if (rr>mid) sh[x].rs=change(sh[x].rs,mid+1,r,ll,rr,v);
		pushup(x,l,r);return x;
	}
}
signed main()
{
	// freopen("b.in","r",stdin);
	// freopen("b.out","w",stdout);
	n=read();m=read();k=read();
	for (int i=1;i<=m;i++) sh[i]=(node){read(),read(),read(),read()};
	for (int i=1;i<=m;i++) b[++w]=sh[i].a,b[++w]=sh[i].c+1;
	sort(b+1,b+1+w);w=unique(b+1,b+1+w)-b-1;
	int MAX=0;
	for (int i=1;i<=m;i++)
	{
		sh[i].a=lower_bound(b+1,b+1+w,sh[i].a)-b;
		sh[i].c=lower_bound(b+1,b+1+w,sh[i].c+1)-b;
		p[sh[i].a].emplace_back(sh[i].b,sh[i].d,1);
		p[sh[i].c].emplace_back(sh[i].b,sh[i].d,-1);
		MAX=max(MAX,sh[i].d);
	}
	pre[0]=1;
	for (int i=1;i<=30;i++) pre[i]=pre[i-1]|(1<<i);
	suc[30]=(1<<30);
	for (int i=29;i>=0;i--) suc[i]=suc[i+1]|(1<<i);
	int ans=0;seg::cnt=1;
	for (int i=1;i<w;i++)
	{
		for (auto [l,r,v]:p[i]) seg::change(1,1,MAX,l,r,v);
		int A=seg::sh[1].ans,l=b[i],r=b[i+1]-1,B=r^(r>>1)^(l-1)^((l-1)>>1);
		for (int j=0;j<=30;j++) if (B>>j&1)
		{
			int tmp=A&pre[j];
			if (__builtin_popcount(A&suc[j+1])&1) tmp^=(1<<j);
			ans^=tmp;
		}
	}
	for (int i=30;i>=0;i--) if (k>>i&1)
	{
		int tmp=ans&pre[i];
		if (__builtin_popcount(ans&suc[i+1])&1) tmp^=(1<<i);
		ans=tmp;break;
	}
	if (ans) printf("Hamed\n");
	else printf("Malek\n");
}