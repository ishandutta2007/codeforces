#include<bits/stdc++.h>
#define N 270000
#define M 998244353
using namespace std;
typedef long long ll;
void ksm(ll x,ll&y,int t)
{
	for(t<0?ksm(x,x,M-2),t=-t:0,y=1;t;t>>=1)
	t&1?y=y*x%M:0,x=x*x%M;
}
ll A[N],a[N],b[N],fac[N],inv[N],g,G,tp,iv;
int i,j,k,l,T[N];
inline void get(int n)
{
	for(l=1,k=-1;l<=n<<1;l<<=1,k++);
	for(i=1;i<l;i++)
	T[i]=T[i>>1]>>1|(i&1)<<k;
	ksm(l,iv,M-2);
}
inline void ntt(ll*c,int t)
{
	for(i=0;i<l;i++)
	if(T[i]<i)swap(c[i],c[T[i]]);
	for(i=1;i<l;i<<=1)
	for(ksm(3,G,(M-1)/i/2*t),j=0;j<l;j+=i<<1)
	for(k=0,g=1;k<i;k++,g=g*G%M)
	tp=g*c[j+k+i],c[j+k+i]=(c[j+k]-tp)%M,(c[j+k]+=tp)%=M;
	if(t<0)for(i=0;i<l;i++)(c[i]*=iv)%=M;
}
void cal(int nn)
{
	if(!nn){A[0]=1;return;}
	int n=nn>>1;cal(n),get(n);
	for(i=0;i<=n;i++)
	a[n-i]=A[i]*fac[i]%M,ksm(n,b[i],i),(b[i]*=inv[i])%=M;
	for(i=n+1;i<l;i++)a[i]=b[i]=0;
	ntt(a,1),ntt(b,1);
	for(i=0;i<l;i++)(a[i]*=b[i])%=M;
	ntt(a,-1);
	for(i=0;i<l;i++)b[i]=i<=n?a[n-i]*inv[i]%M:0;
	ntt(A,1),ntt(b,1);
	for(i=0;i<l;i++)(A[i]*=b[i])%=M;
	ntt(A,-1);for(i=n<<1|1;i<l;i++)A[i]=0;
    if(nn&1)
	for(i=n<<1|1;i>=0;i--)A[i]=(2*n*A[i]+(i?A[i-1]:0))%M;
}
int n,s1,s2;
int main()
{
    scanf("%d%d%d",&n,&s1,&s2);
    fac[0]=inv[0]=1;
    for(i=1;i<=n;i++)
	fac[i]=fac[i-1]*i%M,ksm(fac[i],inv[i],M-2);
	cal(n-1);
	if(s1+s2<=n+1&&s1&&s2)
	s1--,s2--,printf("%lld",(A[s1+s2]*fac[s1+s2]%M*inv[s1]%M*inv[s2]%M+M)%M);
	else puts("0");
}