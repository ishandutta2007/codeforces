/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define m_k make_pair
#define int long long
#define ls x+x
#define rs x+x+1
#define len(a) (int)a.size()
using namespace std;
const int N=8*1e5+100;
int T,n,m,x[N],p[N],b[N],w,pre[N],suc[N],v[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct node
{
	int a,b;//ai+b;
	int cal(int x){return a*x+b;}
};
node operator +(node a,node b){a.a+=b.a;a.b+=b.b;return a;}
node operator -(node a,node b){a.a-=b.a;a.b-=b.b;return a;}
node sa[N],sb[N],sc[N];
void upd(int l,int r,node v)
{
	sa[l]=sa[l]+v;sa[r]=sa[r]-v;
}
struct st
{
	int sh[N*4];
	void pushup(int x){sh[x]=max(sh[ls],sh[rs]);}
	void build(int x,int l,int r)
	{
		if (l==r){sh[x]=v[l];return;}
		int mid=(l+r)>>1;
		build(ls,l,mid);build(rs,mid+1,r);
		pushup(x);
	}
	int ask(int x,int l,int r,int ll,int rr)
	{
		if (ll<=l&&rr>=r) return sh[x];
		int mid=(l+r)>>1,ans=-inf;
		if (ll<=mid) ans=max(ans,ask(ls,l,mid,ll,rr));
		if (rr>mid) ans=max(ans,ask(rs,mid+1,r,ll,rr));
		return ans;
	}
	int query(int l,int r)
	{
		if (l>r) return 0;
		return ask(1,1,w,l,r);
	}
}A;
st B;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		for (int i=1;i<=n;i++) x[i]=read(),p[i]=read();
		w=0;
		for (int i=1;i<=n;i++) b[++w]=x[i]-p[i],b[++w]=x[i],b[++w]=x[i]+p[i]+1;
		sort(b+1,b+1+w);w=unique(b+1,b+1+w)-b-1;
		for (int i=1;i<=w;i++) sa[i]=sb[i]=sc[i]=(node){0,0};
		for (int i=1;i<=n;i++)
		{
			int L=lower_bound(b+1,b+1+w,x[i]-p[i])-b;
			int R=lower_bound(b+1,b+1+w,x[i])-b;
			upd(L,R,(node){1,p[i]-x[i]});
			L=R;R=lower_bound(b+1,b+1+w,x[i]+p[i]+1)-b;
			upd(L,R,(node){-1,x[i]+p[i]});
		}
		for (int i=1;i<=w;i++)
		{
			sa[i]=sa[i-1]+sa[i];
			sb[i]=sc[i]=sa[i];
			sb[i].a++;sc[i].a--;
		}
		b[w+1]=inf;
		for (int i=1;i<=w;i++) pre[i]=max({pre[i-1],sa[i].cal(b[i+1]-1),sa[i].cal(b[i])});
		suc[w+1]=0;
		for (int i=w;i>=1;i--) suc[i]=max({suc[i+1],sa[i].cal(b[i+1]-1),sa[i].cal(b[i])});
		for (int i=1;i<=w;i++) v[i]=max(sb[i].cal(b[i+1]-1),sb[i].cal(b[i]));
		A.build(1,1,w);
		for (int i=1;i<=w;i++) v[i]=max(sc[i].cal(b[i+1]-1),sc[i].cal(b[i]));
		B.build(1,1,w);
		for (int i=1;i<=n;i++)
		{
			int MAX=0;
			int L=lower_bound(b+1,b+1+w,x[i]-p[i])-b;
			int R=lower_bound(b+1,b+1+w,x[i])-b;
			MAX=max(MAX,B.query(L,R-1)+x[i]-p[i]);MAX=max(MAX,pre[L-1]);
			L=R;R=lower_bound(b+1,b+1+w,x[i]+p[i]+1)-b;
			MAX=max(MAX,A.query(L,R-1)-x[i]-p[i]);MAX=max(MAX,suc[R]);
			if (MAX>m) printf("0");
			else printf("1");
		}
		printf("\n");
	}
}