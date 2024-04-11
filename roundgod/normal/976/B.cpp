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
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	ll x=1,y=1;
	if(k<=n-1)
	{
		printf("%I64d %I64d\n",x+k,1LL);
		return 0;
	}
	k-=n;
	x=n;y=2;
	ll steps=k/(2*m-2);
	x=x-2*steps;
	k=k%(2*m-2);
	if(k<=m-2)
	{
		printf("%I64d %I64d\n",x,y+k);
		return 0;
	}
	k-=m-1;
	x--;y=m;
	printf("%I64d %I64d\n",x,y-k);
	return 0;
}