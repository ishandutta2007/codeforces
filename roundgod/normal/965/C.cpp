#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,M,D;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&M,&D);
	ll d=1,ans=0;
	for(int i=1;i<=D;i++)
	{
		if(d>n) break;
		ans=max(ans,min(M,n/d)*i);
		d+=k;
	}
	printf("%I64d\n",ans);
	return 0;
}