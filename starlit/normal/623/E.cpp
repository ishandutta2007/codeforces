#include<bits/stdc++.h>
#define M 1000000007
#define N 66000
using namespace std;
typedef long long ll;
const double pi=2*acos(-1);
struct cp{double x,y;}a[N],b[N],c[N],d[N],e[N],w[N],s;
cp operator+(cp x,cp y){return{x.x+y.x,x.y+y.y};}
cp operator-(cp x,cp y){return{x.x-y.x,x.y-y.y};}
cp operator*(cp x,cp y){return{x.x*y.x-x.y*y.y,x.y*y.x+x.x*y.y};}
ll m,now,fac[N],inv[N],ans;
int K,n=1,i,j,k=-1,r[N],f[N],T[N];
inline void fft(cp*c,int t)
{
	for(i=0;i<n;i++)T[i]<i?swap(c[T[i]],c[i]),0:0;
	for(i=1;i<n;i<<=1)
	for(j=0;j<n;j+=i<<1)
	for(k=0;k<i;k++)s=w[(t?n:0)+(t?-1:1)*n/i/2*k]*c[j+k+i],
	c[j+k+i]=c[j+k]-s,c[j+k]=c[j+k]+s;
}
inline void split(int*a,cp*b,cp*c,int t)
{
	for(i=0;i<n;i++)
	k=(1ll*a[i]*(t?t:1)%M+M)%M,t=t*now%M,
	b[i].x=k>>15,c[i].x=k&32767,b[i].y=c[i].y=0;
	fft(b,0),fft(c,0);
}
inline ll get(cp x){return (ll)(x.x/n+0.5)%M;}
inline void mul(int*v)
{
	split(v,c,d,1);
	for(i=0;i<n;i++)
	e[i]=a[i]*d[i]+b[i]*c[i],
	c[i]=a[i]*c[i],d[i]=b[i]*d[i];
	fft(c,1),fft(d,1),fft(e,1);
    for(i=0;i<n;i++)
	v[i]=i<=K?((get(c[i])<<30)+(get(e[i])<<15)+get(d[i]))%M:0;
}
int main()
{
	scanf("%lld%d",&m,&K);
	if(m>K)return puts("0"),0;
	for(fac[0]=inv[0]=fac[1]=inv[1]=1,i=2;i<=K;i++)
	fac[i]=fac[i-1]*i%M,inv[i]=-M/i*inv[M%i]%M;
	for(i=2;i<=K;i++)inv[i]=inv[i-1]*inv[i]%M;
	for(;n<=K<<1;n<<=1,k++);
	for(i=0;i<=n;i++)w[i]={cos(pi*i/n),sin(pi*i/n)};
	for(i=1;i<n;i++)T[i]=T[i>>1]>>1|(i&1)<<k;
	for(i=1;i<=K;i++)f[i]=inv[i];
	for(r[0]=1,now=2;m;m>>=1)
	split(f,a,b,0),m&1?mul(r),0:0,
	mul(f),(now*=now)%=M;
	for(i=1;i<=K;i++)ans+=r[i]*inv[K-i]%M;
	printf("%d",(ans%M*fac[K]%M+M)%M);
}