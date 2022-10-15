#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a,b;
set<ll> s;
ll fact[MAXN];
ll pow_mod(ll a,ll i)
{
    if(i==0) return 1;
    ll s=1;
    while(i>0)
     {
         if(i&1) s=(s*a)%MOD;
         a=(a*a)%MOD;
         i>>=1;
     }
     return s;
}
ll mod_comb(ll n,ll k)
{
    return fact[n]*pow_mod(fact[k]*fact[n-k]%MOD,MOD-2)%MOD;
}
int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&n);
	fact[0]=1;
	for(ll i=1;i<=n;i++)
		fact[i]=fact[i-1]*i%MOD;
	queue<ll> que;
	que.push(a);
	que.push(b);
	while(que.size())
	{
		ll p=que.front();
		s.insert(p);
		if(p>=10000000) break;
		que.pop();
		que.push(p*10+a);
		que.push(p*10+b);
	}
	ll ans=0;
	for(ll i=0;i<=n;i++)
		if(s.count(i*a+(n-i)*b)) ans=(ans+mod_comb(n,i))%MOD;
	printf("%I64d\n",ans);
	return 0;
}