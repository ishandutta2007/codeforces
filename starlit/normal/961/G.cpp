#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;
ll ans,inv[200005];
ll ksm(ll x,int tim)
{
	register ll r=1;
	for(;tim;tim>>=1)
	tim&1?r=r*x%M:0,x=x*x%M;
	return r;
}
int n,k,w;
int main()
{
	scanf("%d%d",&n,&k);
	inv[0]=1;
	for(int i=1;i<=n;i++)
	inv[i]=inv[i-1]*ksm(i,M-2)%M;
	for(int i=0;i<=k;i++)
	(ans+=(k-i&1?-1:1)*(ksm(i,n)+(n-1)*ksm(i,n-1))%M*inv[i]%M*inv[k-i]%M)%=M;
	for(int i=0;i<n;i++)
	scanf("%d",&k),(w+=k)%=M;
	printf("%lld",(ans*w%M+M)%M);
}