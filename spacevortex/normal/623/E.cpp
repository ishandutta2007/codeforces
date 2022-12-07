#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define inv(x) power(x,Mod-2)
#define cle(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const ll Mod=1e9+7;
ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
ll sub(ll a,const ll b){a-=b;if(a<0)a+=Mod;return a;}
ll mul(const ll a,const ll b){return (ll)a*b%Mod;}
ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}

typedef double db;
typedef complex<double> cod;
const db PI=acos(-1);
const ll L=(1<<16),N=L+20,S=(1<<16)-1;
ll lo[N],rev[N];
cod g[2][N];
void init()
{
	ll i;
	db sita;
	for(i=2;i<=L;i++) lo[i]=lo[i>>1]+1;
	for(i=0;i<L;i++)
	{
		sita=2.0*PI*i/L;
		g[0][i]=cod(cos(sita),sin(sita));
		g[1][i]=cod(cos(-sita),sin(-sita));
	}
}
void DFT(ll n,ll opt,cod *w)
{
	ll i,j,mws,len,mid;
	cod tmp;
	mws=lo[n]-1;
	for(i=1;i<n;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<mws);
	}
	for(i=1;i<n;i++)
	{
		//printf("#%lld %lld\n",i,rev[i]);
		if(rev[i]<i) swap(w[rev[i]],w[i]);
	}
	for(len=2;len<=n;len<<=1)
	{
		mid=len>>1;
		for(i=0;i<n;i+=len)
		{
			for(j=0;j<mid;j++)
			{
				tmp=g[opt][L/len*j]*w[i+mid+j];
				w[i+mid+j]=w[i+j]-tmp;
				w[i+j]=w[i+j]+tmp;
			}
		}
	}
}
void trans(ll n,ll *a,ll *b,ll *c)
{
	ll i,len;
	static cod h1[N],h2[N];
	for(len=1;len<n*2;len<<=1);
	cle(h1);cle(h2);
	for(i=0;i<n;i++) 
	{
		h1[i].real(a[i]);h2[i].real(b[i]);
	}
	DFT(len,0,h1);DFT(len,0,h2);
	for(i=0;i<len;i++) h1[i]*=h2[i];
	DFT(len,1,h1);
	for(i=0;i<n*2;i++)
	{
		h1[i]/=len;
		c[i]=floor(h1[i].real()+0.5);
	}
}
void strans(ll n,ll *a,ll *b,ll *c)
{
	ll i,len;
	static ll a1[N],a2[N],b1[N],b2[N],h[N];
	//printf("strans\n");
	//for(i=0;i<4;i++) printf("%lld ",a[i]);putchar('\n');
	//for(i=0;i<4;i++) printf("%lld ",b[i]);putchar('\n');
	for(len=1;len<n*2;len<<=1);
	cle(a1);cle(a2);cle(b1);cle(b2);
	
	for(i=0;i<n;i++)
	{
		a1[i]=a[i]>>16;a2[i]=a[i]&S;
		b1[i]=b[i]>>16;b2[i]=b[i]&S;
		//printf("#%lld  %lld %lld %lld %lld\n",i,a1[i],a2[i],b1[i],b2[i]);
	}
	for(i=0;i<n*2;i++) c[i]=0;
	trans(n,a1,b1,h);
	for(i=0;i<n*2;i++) upd(c[i],mul(h[i]%Mod,(1ll<<32)%Mod));
	trans(n,a1,b2,h);
	for(i=0;i<n*2;i++) upd(c[i],mul(h[i]%Mod,1<<16));
	trans(n,a2,b1,h);
	for(i=0;i<n*2;i++) upd(c[i],mul(h[i]%Mod,1<<16));
	trans(n,a2,b2,h);
	for(i=0;i<n*2;i++) upd(c[i],h[i]%Mod);
}

const ll Log=16;
ll m,n,ans=0;
ll zp[N],fp[N],cf[N],f[Log+3][N],a[N],b[N],t[N];
void init2()
{
	ll i;
	zp[0]=fp[0]=1;
	for(i=1;i<=n;i++) zp[i]=mul(zp[i-1],i);
	fp[n]=inv(zp[n]);
	for(i=n-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
	cf[0]=1;
	for(i=1;i<=n;i++) cf[i]=mul(cf[i-1],2);
}
ll C(ll a,ll b)
{
	return mul(zp[a],mul(fp[b],fp[a-b]));
}
int main()
{
	ll i,j,w;
	cin>>m>>n;
	if(m>n)
	{
		puts("0");
		return 0;
	}
	init();
	init2();
	/*
	a[0]=3;a[1]=4;
	b[0]=7;b[1]=5;
	strans(100,a,b,t);
	for(i=0;i<3;i++) printf("%lld ",t[i]);
	return 0;
	*/
	for(i=1;i<=n;i++) f[0][i]=fp[i];
	for(i=1;i<=Log;i++)
	{
		w=1;
		for(j=0;j<=n;j++)
		{
			a[j]=mul(f[i-1][j],w);
			b[j]=f[i-1][j];
			w=mul(w,cf[(1<<(i-1))]);
		}
		strans(n+1,a,b,f[i]);
		//printf("S%lld\n",i);
		//for(j=0;j<=n;j++) printf("%lld ",f[i][j]);
		//putchar('\n');
	}
	t[0]=1;
	for(i=Log;i>=0;i--)
	{
		if((m&(1<<i))==0) continue;
		w=1;
		for(j=0;j<=n;j++) 
		{
			t[j]=mul(t[j],w);
			w=mul(w,cf[1<<i]);
		}
		strans(n+1,t,f[i],t);
	}
	for(i=1;i<=n;i++) 
	{
		//printf("#%lld %lld\n",i,mul(t[i],zp[i]));
		upd(ans,mul(mul(t[i],zp[i]),C(n,i)));
	}
	printf("%lld",ans);
	return 0;
}