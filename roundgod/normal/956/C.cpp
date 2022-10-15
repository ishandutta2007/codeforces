#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN],num[MAXN];
int main()
{
	scanf("%I64d",&n);
	for(ll i=0;i<n;i++)
		scanf("%I64d",&a[i]);
	ll maxi=1;
	num[0]=1;
	for(ll i=1;i<n;i++)
	{
		if(a[i]>=maxi) maxi=a[i]+1;
		num[i]=maxi;
	}
	for(ll i=n-2;i>=0;i--)
		num[i]=max(num[i],num[i+1]-1);
	ll ans=0;
	for(ll i=0;i<n;i++)
		ans+=num[i]-a[i]-1;
	printf("%I64d\n",ans);
	return 0;
}