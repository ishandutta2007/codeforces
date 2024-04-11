#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN];
vector<int> G[MAXN];
vector<int> v;
bool check(int x)
{
	int need=0;
	for(int i=0;i<(int)v.size();i++)
		need+=1+max(0,v[i]-(x-i));
	return need<=x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&p[i]);
			G[p[i]].push_back(i);
		}
		v.clear();
		for(int i=1;i<=n;i++) if(G[i].size()) v.push_back(G[i].size());
		v.push_back(1);
		sort(v.begin(),v.end(),greater<int>());
		int l=0,r=n;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(check(mid)) r=mid; else l=mid;
		}
		printf("%d\n",r);
	}
	return 0;
}