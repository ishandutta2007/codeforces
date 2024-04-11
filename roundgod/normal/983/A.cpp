#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,p,q,b;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&p,&q,&b);
		if(q==1||p==0||p%q==0) {puts("Finite"); continue;}
		ll x=gcd(p,q);
		q/=x;
		bool f=true;
		while(q!=1)
		{
			ll x=gcd(q,b);
			if(x==1) {f=false; break;}
			while(q%x==0) q/=x;
		}
		if(f) puts("Finite"); else puts("Infinite");
	}
	return 0;
}