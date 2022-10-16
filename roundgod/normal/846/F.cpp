#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN],occ[MAXN],last[MAXN];
int main()
{
	scanf("%I64d",&n);
	memset(occ,0,sizeof(occ));
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		last[i]=occ[a[i]];
		occ[a[i]]=i;
	}
	ll sum=0;
	for(ll i=1;i<=n;i++)
		sum+=(i-last[i])*(n-i+1)-1;
	printf("%.10f\n",(double)(sum*2+n)/(n*n));
	return 0;
}