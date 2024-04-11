#include<bits/stdc++.h>
#define upd(a,b) a=add(a,b)
#define rdc(a,b) a=sub(a,b)
#define inv(x) power(x,Mod-2)
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
const ll N=520;
ll F,B,W,n;
ll p[N],c[N],h[N],_h[N],f[N],g[N],dp[N];
void trans(ll *a,ll *b,ll *r)
{
	ll i,j,xs;
	static ll c[N];
	memset(c,0,sizeof(c));
	for(i=0;i<n;i++) 
	{
		for(j=0;j<n;j++)
		{
			upd(c[i+j],mul(a[i],b[j]));
		}
	}
	for(i=(n-1)*2;i>=n;i--)
	{
		xs=mul(_h[n],c[i]);
		for(j=0;j<=n;j++) rdc(c[i-n+j],mul(h[j],xs));
	}
	for(i=0;i<=(n-1)*2;i++) r[i]=c[i];
}
void power(ll *ans,ll *x,ll cs)
{
	while(cs)
	{
		if(cs&1ll) trans(ans,x,ans);
		trans(x,x,x);cs>>=1;
	}
}
void ins(ll w)
{
	ll i;
	static ll a[N],b[N];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	a[0]=1;b[1]=1;
	power(a,b,w);
	for(i=0;i<n;i++) upd(f[i],a[i]);
}
int main()
{
	ios::sync_with_stdio(false);
	ll i,j;
	cin>>F>>B>>W;
	for(i=1;i<=F;i++) cin>>p[i];
	n=0;
	for(i=1;i<=B;i++)
	{
		cin>>c[i];
		n=max(n,c[i]);
	}
	n++;
	h[n]=1;
	for(i=1;i<=B;i++) h[n-c[i]]=sub(h[n-c[i]],1);
	for(i=1;i<=n;i++) if(h[i]) _h[i]=inv(h[i]);
	for(i=1;i<=F;i++) ins(p[i]);
	g[0]=1;
	power(g,f,W);
	for(i=n-1;i>=0;i--)
	{
		upd(dp[i],g[i]);
		for(j=1;j<=B;j++)
		{
			if(i>=c[j]) upd(dp[i-c[j]],dp[i]);
		}
	}
	printf("%lld",dp[0]);
	return 0;
}