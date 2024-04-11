#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	while(n&&m)
	{
		if(n>=2*m)
		{
			ll res=n/m;
			if(res&1) res-=1;
			n=n-res*m;
			continue;
		}
		else if(m>=2*n)
		{
			ll res=m/n;
			if(res&1) res-=1;
			m=m-res*n;
			continue;
		}
		else break;
	}
	printf("%I64d %I64d\n",n,m);
	return 0;
}