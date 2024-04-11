#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll n,k,A,B;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&A,&B);
	ll ans=0;
	while(n>1)
	{
		if(n<k||k==1)
		{
			ans+=(n-1)*A;
			n=1;
		}
		else if(n%k==0)
		{
			ans+=min(B,(n-n/k)*A);
			n=n/k;
		}
		else
		{
			ans+=(n%k)*A;
			n-=n%k;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}