#include<bits/stdc++.h>
#define M 1000000009
#define N 100005
using namespace std;
typedef long long ll;
int n,a,b,k;
inline ll ksm(ll x,int t)
{
	ll y=1;
	for(;t;t>>=1)
	t&1?y=y*x%M:0,x=x*x%M;
	return y;
}
ll co,ans;
char S[N];
int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&k);
    co=ksm(ksm(a,M-2)*b%M,k);
    if(co==1)co=(n+1)/k;
    else co=(ksm(co,n/k+1)-1)*ksm(co-1,M-2)%M;
    scanf("%s",S);
    for(int i=0;i<k;i++)
	ans+=ksm(a,n-i)*ksm(b,i)%M*co%M*(S[i]=='+'?1:-1);
    printf("%lld",(ans%M+M)%M);
}