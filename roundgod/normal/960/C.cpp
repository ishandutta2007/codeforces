#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int X,d;
int pow2[31];
vector<ll> ans;
int main()
{
	scanf("%d%d",&X,&d);
	pow2[0]=1;
	for(int i=1;i<=30;i++)
		pow2[i]=pow2[i-1]*2;
	int res=30;
	ll now=1;
	while(X>0)
	{
		while(X<pow2[res]-1) res--;
		X-=pow2[res]-1;
		for(int i=0;i<res;i++) ans.push_back(now);
		now+=d;
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%I64d ",ans[i]);
	return 0;
}