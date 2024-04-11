#include<bits/stdc++.h>
#define N 530000
#define M 998244353
typedef long long ll;
inline void ksm(ll x,ll&y,int t)
{
	for(t<0?t+=M-1:0,y=1;t;t>>=1)
	t&1?y=y*x%M:0,x=x*x%M;
}
int n,m,i,j,k,l,T[N];
ll B[N],A[N],S[N],I[N],g,G,p;
inline void ntt(ll*c,int t)
{
	for(i=1;i<l;i++)T[i]<i?std::swap(c[T[i]],c[i]),0:0;
	for(i=1;i<l;i<<=1)
	for(j=0,ksm(3,G,M/i/2*t);j<l;j+=i<<1)
	for(k=0,g=1;k<i;k++,g=g*G%M)
	p=c[j+k+i]*g%M,c[j+k+i]=(c[j+k]-p)%M,(c[j+k]+=p)%=M;
	if(t<0)
	for(i=0;i<l;i++)c[i]=-M/l*c[i]%M;
}
void getInv(int n)
{
	if(n==1){ksm(S[0],I[0],M-2),I[1]=0;return;}
	getInv(n+1>>1);
	for(l=1;l<n<<1;l<<=1);
	for(i=1;i<l;i++)
	T[i]=T[i>>1]>>1|(i&1?l>>1:0);
    for(i=0;i<l;i++)i<n?B[i]=S[i]:(B[i]=I[i]=0);
    ntt(B,1),ntt(I,1);
    for(i=0;i<l;i++)
	I[i]=I[i]*(2-B[i]*I[i]%M)%M;
	ntt(I,-1);
	for(i=n;i<l;i++)I[i]=0;
}
void getSqr(int n)
{
	if(n==1){S[0]=1;return;}
	getSqr(n+1>>1);
	getInv(n);
    for(i=0;i<l;i++)
	B[i]=i<n?A[i]:0;
	ntt(B,1),ntt(I,1);
	for(i=0;i<l;i++)I[i]=I[i]*B[i]%M;
	ntt(I,-1);
	for(i=0;i<n;i++)S[i]=(S[i]+I[i])*(M+1>>1)%M;
}
int main()
{
	scanf("%d%d",&n,&m),m++;
	for(i=0;i<n;i++)scanf("%d",&k),A[k]=-4;
	A[0]=1,getSqr(m);
	S[0]++,getInv(m);
	for(i=1;i<m;i++)printf("%d\n",(I[i]*2%M+M)%M);
}