#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<P> v;
vector<P> ans;
vector<int> dist[MAXN];
int pos[MAXN];
void add_edge(int u,int v)
{
	ans.push_back(P(u,v));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		int d;
		scanf("%d",&d);
		v.push_back(P(d,2*i-1));
	}
	sort(v.begin(),v.end(),greater<P>());
	for(int i=0;i<n-1;i++) add_edge(v[i].S,v[i+1].S);
	for(int i=0;i<n;i++) 
	{
		pos[v[i].S]=i;
		dist[i].push_back(v[i].S);
	}
	for(int i=0;i<n;i++)
	{
		int u=v[i].S;
		int need=(pos[u]+v[i].F-1);
		dist[need+1].push_back(u+1);
		add_edge(u+1,dist[need][0]);
	}
	for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}