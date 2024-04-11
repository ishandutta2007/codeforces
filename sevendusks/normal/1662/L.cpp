/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2*1e5+100;
int n,V,t[N],a[N],p[N],f[N];
int b[N],c[N],v[N],w;
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
struct bit//
{
	int sh[N],ti[N],dfn,n;
	inline void init(int m){n=m;memset(sh,-0x3f,(n+10)*sizeof(int));}
	int lowbit(int x){return x&(-x);}
	void upd(int x){if(ti[x]!=dfn)ti[x]=dfn,sh[x]=-inf;}
	void change(int x,int v){while(x<=n)upd(x),ckmax(sh[x],v),x+=lowbit(x);}
	int query(int x){int ans=-inf;while(x)upd(x),ckmax(ans,sh[x]),x-=lowbit(x);return ans;}
}T;
bool cmp(int x,int y){return a[x]<a[y];}
void solve(int l,int r)
{
	if (l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid);
	for (int i=l;i<=r;i++)p[i]=i;
	sort(p+l,p+mid+1,cmp);sort(p+mid+1,p+r+1,cmp);
	int i=mid,j=r;T.dfn++;
	while (i>=l&&j>mid)
	{
		if (a[p[i]]>a[p[j]]) T.change(c[p[i]],f[p[i]]),i--;
		else ckmax(f[p[j]],T.query(c[p[j]])+1),j--;
	}
	while (j>mid) ckmax(f[p[j]],T.query(c[p[j]])+1),j--;
	w=0;
	i=l,j=mid+1;T.dfn++;
	while (i<=mid&&j<=r)
	{
		if (a[p[i]]<=a[p[j]]) T.change(b[p[i]],f[p[i]]),i++;
		else ckmax(f[p[j]],T.query(b[p[j]])+1),j++;
	}
	while (j<=r) ckmax(f[p[j]],T.query(b[p[j]])+1),j++;
	solve(mid+1,r);
}
signed main()
{
	n=read();V=read();
	for (int i=1;i<=n;i++) t[i]=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=0;i<=n;i++) p[i]=i;
	for (int i=0;i<=n;i++)
	{
		b[i]=V*t[i]-a[i];
		c[i]=V*t[i]+a[i];
	}
	for (int i=0;i<=n;i++) v[++w]=b[i];
	sort(v+1,v+1+w);w=unique(v+1,v+1+w)-v-1;
	for (int i=0;i<=n;i++) b[i]=lower_bound(v+1,v+1+w,b[i])-v;
	w=0;
	for (int i=0;i<=n;i++) v[++w]=c[i];
	sort(v+1,v+1+w);w=unique(v+1,v+1+w)-v-1;
	for (int i=0;i<=n;i++) c[i]=lower_bound(v+1,v+1+w,c[i])-v;
	T.init(n+1);
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	solve(0,n);
	printf("%lld\n",*max_element(f,f+n+1));
}