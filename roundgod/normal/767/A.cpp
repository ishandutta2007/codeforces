#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]=i;
	}
	for(int i=n-1;i>=1;i--)
		a[i]=max(a[i],a[i+1]);
	for(int i=n;i>=1;i--)
		G[a[i]].push_back(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<G[i].size();j++)
			printf("%d ",G[i][j]);
		puts("");
	}
	return 0;
}