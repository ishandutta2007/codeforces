#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll n,k;
bool used[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&k);
	memset(used,false,sizeof(used));
	for(ll i=1;i<=min((ll)100000,k);i++)
	{
		if(used[n%i])
		{
			puts("No");
			return 0;
		}
		used[n%i]=true;
	}
	puts("Yes");
	return 0;
}