#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
const int MOD=1e9+7;
struct mint{int x;mint(int x=0):x(x){}};
inline mint operator+  (mint a,mint b){return a.x+b.x<MOD?a.x+b.x:a.x+b.x-MOD;}
inline mint operator-  (mint a){return MOD-a.x;}
inline mint operator-  (mint a,mint b){return a+-b;}
inline mint operator*  (mint a,mint b){return 1LL*a.x*b.x%MOD;}
inline mint operator<< (mint x,int y){mint r=1;for(;y;y>>=1,x=x*x)if(y&1)r=r*x;return r;}
inline mint operator~  (mint x){return x<<MOD-2;}
inline mint operator/  (mint a,mint b){return a*~b;}
inline mint&operator+= (mint&a,mint b){return a=a+b;}
inline mint&operator-= (mint&a,mint b){return a=a-b;}
inline mint&operator*= (mint&a,mint b){return a=a*b;}
inline mint&operator<<=(mint&x,int y){return x=x<<y;}
inline mint&operator/= (mint&a,mint b){return a=a/b;}
#define MN 100000
#define N 524288
struct P{int l,r,t;}a[MN+5],b[MN+5],c[MN*2+5];
bool cmp(const P&a,const P&b){return a.r!=b.r?a.r<b.r:a.l>b.l;}
int p[MN*4+5],pn;
mint t0[N*2+5],t1[N*2+5],tt[N*2+5];
inline int f(int x){return lower_bound(p+1,p+pn+1,x)-p;}
void rw(mint*t,int k,mint x){for(k+=N;k;k>>=1)t[k]+=x;}
mint query(mint*t,int l,int r)
{
	mint res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res+=t[l+1];
		if( r&1)res+=t[r-1];
	}
	return res;
}
int main()
{
	int k,n,m,cn=0,i,mx;
	k=read();n=read();m=read();
	for(i=1;i<=n;++i)a[i].l=read(),a[i].r=read();
	sort(a+1,a+n+1,cmp);
	for(i=1,mx=0;i<=n;++i)if(a[i].l>mx)mx=a[i].l,c[++cn]=a[i];
	for(i=1;i<=m;++i)b[i].l=read(),b[i].r=read(),b[i].t=1;
	sort(b+1,b+m+1,cmp);
	for(i=1,mx=0;i<=m;++i)if(b[i].l>mx)mx=b[i].l,c[++cn]=b[i];
	sort(c+1,c+cn+1,cmp);
	for(i=1;i<=cn;++i)p[++pn]=c[i].l-1,p[++pn]=c[i].r;p[++pn]=0;
	sort(p+1,p+pn+1);pn=unique(p+1,p+pn+1)-p-1;
	rw(tt,f(0),1);
	for(i=1;i<=cn;++i)
	{
		if(c[i].t)
		{
			mint x=query(t1,f(c[i].l-1)+1,f(c[i].r))+query(tt,1,f(c[i].l-1))*(mint(2)<<c[i].l-1);
			rw(t1,f(c[i].r),-x);rw(tt,f(c[i].r),-x*(mint((MOD+1)/2)<<c[i].r));
		}
		else
		{
			mint x=query(t0,f(c[i].l-1)+1,f(c[i].r))+query(tt,1,f(c[i].l-1))*(mint(2)<<c[i].l-1);
			rw(t0,f(c[i].r),-x);rw(tt,f(c[i].r),-x*(mint((MOD+1)/2)<<c[i].r));
		}
	}
	printf("%d",query(tt,1,pn)*(mint(2)<<k));
}