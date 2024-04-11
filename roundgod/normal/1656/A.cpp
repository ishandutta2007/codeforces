#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		P maxi=P(-INF-1,0),mini=P(INF+1,0);
		for(int i=1;i<=n;i++)
		{
			maxi=max(maxi,P(a[i],i));
			mini=min(mini,P(a[i],i));
		}
		printf("%d %d\n",maxi.S,mini.S);
	}
	return 0;
}