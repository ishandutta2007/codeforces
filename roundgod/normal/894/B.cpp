#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,k;
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
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if(k==-1&&((n&1)!=(m&1)))
	{
		puts("0");
		return 0;
	}
	printf("%I64d\n",pow_mod(pow_mod(2,n-1),m-1));
	return 0;
}