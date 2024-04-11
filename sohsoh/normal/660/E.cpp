#include <iostream>
using namespace std;
#define ll int64_t
ll poww(ll a,ll b,ll md){return(!b?1:(b&1?a*poww(a*a%md,b/2,md)%md:poww(a*a%md,b/2,md)%md));}
const ll N=1e6+1,M=1e9+7;
ll n,m,ans,F[N],I[N];
int main() {
	F[0]=I[0]=1;for(int i=1;i<N;i++)F[i]=F[i-1]*i%M,I[i]=poww(F[i],M-2,M);cin>>n>>m;ans=poww(m,n,M);for(int i=1;i<=n;i++)ans+=poww(m,i,M)*poww(m-1,n-i,M)%M*F[n]%M*I[i-1]%M*I[n-i+1]%M;cout<<ans%M;
}