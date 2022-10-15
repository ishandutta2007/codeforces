#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],b[MAXN];
int main()
{
	scanf("%I64d",&n);
	ll sum=0;
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}
	for(ll i=0;i<n;i++)
		scanf("%I64d",&b[i]);
	sort(b,b+n);
	if(sum>b[n-1]+b[n-2]) puts("NO"); else puts("YES");
	return 0;
}