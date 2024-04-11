#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int m,b;
int main()
{
	scanf("%d%d",&m,&b);
	int h=b,w=0;
	ll ans=0;
	while(h>=0)
	{
		ans=max(ans,1LL*(h+w)*(h+1)*(w+1)/2);
		h-=1;
		w+=m;
	}
	printf("%I64d\n",ans);
	return 0;
}