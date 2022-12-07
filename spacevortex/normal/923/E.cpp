#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define cle(x,y) memset(x,0,sizeof(ll)*(y))
using namespace std;
typedef long long ll;
const ll Mod=998244353;
inline ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
inline ll sub(ll a,const ll b){a-=b;if(a<0)a+=Mod;return a;}
inline ll mul(const ll a,const ll b){return a*b%Mod;}
inline ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
inline ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
const ll L=1<<18,N=L+50;
ll rev[N],lo[N],c1[N],c2[N],g[2][N],zp[N],fp[N];
inline void init()
{
	ll i,x;
	for(i=2;i<=L;i++) lo[i]=lo[i>>1]+1;
	g[0][0]=1;
	for(i=1,x=power(3,(Mod-1)/L);i<L;i++) g[0][i]=mul(g[0][i-1],x);
	g[1][0]=1;
	for(i=1,x=power(inv(3),(Mod-1)/L);i<L;i++) g[1][i]=mul(g[1][i-1],x);
	zp[0]=fp[0]=1;
	for(i=1;i<=L;i++) zp[i]=mul(zp[i-1],i);
	fp[L]=inv(zp[L]);
	for(i=L-1;i>=1;i--) fp[i]=mul(fp[i+1],i+1);
}
inline void NTT(ll n,ll opt,ll *w)
{
	
	ll i,j,mws=lo[n],len=1,mid,tmp;
	for(i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(mws-1));
	for(i=1;i<n;i++) if(rev[i]<i) swap(w[rev[i]],w[i]);
	while(len<n)
	{
		
		len<<=1;mid=len>>1;
		for(i=0;i<n;i+=len)
		{
			for(j=0;j<mid;j++)
			{
				tmp=mul(g[opt][(L/len)*j],w[i+mid+j]);
				w[i+mid+j]=sub(w[i+j],tmp);
				w[i+j]=add(w[i+j],tmp);
			}
		}
	}
}
inline void trans(ll n,ll m,ll *w1,ll *w2,ll *w3)
{
	ll len=1,ny,i;
	while(len<n+m) len<<=1;
	cle(c1,len+3);cle(c2,len+3);
	for(i=0;i<n;i++) c1[i]=w1[i];
	for(i=0;i<m;i++) c2[i]=w2[i];
	NTT(len,0,c1);NTT(len,0,c2);
	for(i=0;i<len;i++) c1[i]=mul(c1[i],c2[i]);
	NTT(len,1,c1);
	for(i=0,ny=inv(len);i<n+m;i++) w3[i]=mul(c1[i],ny); 
}
ll n,m;
ll F[N],G[N],h[N];
int main()
{
//	freopen("t.in","r",stdin);
	ll i;
	init();
	n=rd();m=rd();
	for(i=0;i<=n;i++) 
	{
		F[i]=rd();F[i]=mul(F[i],zp[i]);
	}
	for(i=0;i<=n;i++) h[i]=fp[i];
	reverse(F,F+n+1);
	trans(n+1,n+1,F,h,F);
	for(i=0;i<=n;i++) G[i]=mul(F[n-i],fp[i]);
	for(i=0;i<=n;i++)
	{
		G[i]=mul(G[i],inv(power(i+1,m)));
	}
	for(i=0;i<=n;i++) G[i]=mul(G[i],zp[i]);
	for(i=0;i<=n;i++)
	{
		if(i&1) h[i]=sub(0,fp[i]);
		else h[i]=fp[i];
	}
	reverse(G,G+n+1);
	trans(n+1,n+1,G,h,G);
	for(i=0;i<=n;i++) F[i]=mul(fp[i],G[n-i]);
	for(i=0;i<=n;i++) printf("%lld ",F[i]);
	return 0;
}