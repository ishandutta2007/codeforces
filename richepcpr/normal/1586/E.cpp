#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,n)rfor(ll i=d;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
bool p1;
typedef long long ll;
typedef unsigned long long ull;
const ll N=5e6+7,mod=998244353;
typedef ll aN[N];
char is[1<<21],os[1<<22],*i1=is,*i2=is,*o1=os;
int fgc() {
	return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;
}
int fpc(int c) {
	return*o1++=c;
}
void fout() {
	fwrite(os,o1-os,1,stdout),o1=os;
}
int(*gc)()=getchar,(*pc)(int)=putchar;
static inline ll qm(ll&a,ll b) {
	return a>=b?a-=b,1:0;
}
ll readll() {
	ll x=0,w=1;
	int c=gc();
	for(; c<48||c>57; c=gc())c-45||(w=-w);
	for(; c>47&&c<58; c=gc())x=x*10+c-48;
	return x*w;
}
int readchar(int l=33,int r=126) {
	if(l>r)std::swap(l,r);
	int c=gc();
	for(; c<l||c>r; c=gc());
	return c;
}
ll wt[122];
void writell(ll x,int c=32) {
	ll t=0;
	for(ull n=x<0?pc(45),0ull-x:x; n; n/=10)wt[++t]=n%10;
	for(t||pc(48); t;)pc(wt[t--]^48);
	c&&pc(c);
}
int mygets(char*s,int c=0) {
	char*t=s;
	while((*t=gc())>31)t++;
	c&&(*t++=c),*t=0;
	return t-s;
}
int myputs(const char*s,int c=10) {
	const char*t=s;
	while(*t)pc(*t++);
	c&&pc(c);
	return t-s;
}
aN next,to,head,deep,f,tag,x,y,sz,lk,vis;
ll cnt=0,ans=0;
void add(ll u,ll v) {
	next[++cnt]=head[u],to[head[u]=cnt]=v;
}
void dfs0(ll u,ll fa) {
    vis[u]=1;
	deep[u]=deep[fa]+1,f[u]=fa;
	rev(i,u,v)if(v^fa&&vis[v]!=1)dfs0(v,u);
}
void dfs1(ll u,ll fa) {
    vis[u]=2;
//    printf("%lld->%lld %lld\n",fa,u,tag[u]);
	ll f=0;
	rev(i,u,v)if(v^fa&&vis[v]!=2)f+=tag[v],dfs1(v,u);
	ans+=f/2+(f&!tag[u]);
}
int main() {
	IO();
	ll n=readll(),m=readll(),u,v;
	static_cast<void>(n);
	rep(i,1,m)u=readll(),v=readll(),add(u,v),add(v,u);
	dfs0(1,0);//exit(0);
	ll q=readll();
	rep(i,1,q)for(u=x[i]=readll(),v=y[i]=readll(),sz[i]=1; deep[u]<deep[v]?std::swap(u,v),u!=v:u!=v; u=f[u])tag[u]^=1,sz[i]++;
	dfs1(1,0),ans+=tag[1];
	if(ans) myputs("NO"),writell(ans,10);
	else {
		myputs("YES");
		rep(i,1,q) {
			ll cntu=1,cntv=sz[i],g=1;
			writell(sz[i],10);
			for(u=x[i],v=y[i]; deep[u]<deep[v]?g^=1,std::swap(cntu,cntv),std::swap(u,v),u!=v:u!=v; g?++cntu:--cntu,u=f[u])lk[cntu]=u;
            lk[cntu]=u;
			rep(j,1,sz[i])writell(lk[j]);pc(10);
		}
	}
	return 0;
}