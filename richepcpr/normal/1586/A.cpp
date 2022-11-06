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
const ll N=5e5+7,mod=998244353;
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
aN p,a,np;
void calc() {
	ll n=readll(),s=0,f=0;
	rep(i,1,n)s+=a[i]=readll();
	if(np[s]) {
		writell(n,10);
		rep(i,1,n)writell(i);
		pc(10);
	}
	else {
		writell(n-1,10);
		rep(i,1,n)if(a[i]&1&&!f)f=1;
		else writell(i);
		pc(10);
	}
}
int main() {
//	IO();
	static const ll n=301*50;
	ll t=0;
	p[0]=mod;
	rep(i,2,n)rep(j,np[i]||(p[++t]=i),t&&p[j]*i<=n&&i%p[j-1])np[i*p[j]]=1;
//	rep(i,1,100)printf("%lld\n",isp[i]);
	ll T=readll();
	while(T--)calc();
	return 0;
}