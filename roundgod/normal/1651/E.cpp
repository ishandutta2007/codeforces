#include<bits/stdc++.h>
#define MAXN 3005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> cycle;
vector<int> G[MAXN];
ll ans;
bool vis[MAXN];
void dfs(int v)
{
	vis[v]=true;
	cycle.push_back(v);
	for(auto to:G[v])
	{
		if(vis[to]) continue;
		dfs(to);
	}
}
ll calc(int mina,int maxa,int minb,int maxb)
{
	return 1LL*mina*(n-maxa+1)*minb*(n-maxb+1);
}
ll calc(int mina,int maxa,int minb,int maxb,int x)
{
	if(x<=n) {mina=min(mina,x); maxa=max(maxa,x);}
	else {minb=min(minb,x-n); maxb=max(maxb,x-n);}
	return calc(mina,maxa,minb,maxb);
}
ll calc(int mina,int maxa,int minb,int maxb,int x,int y)
{
	ll ans=calc(mina,maxa,minb,maxb);
	ans-=calc(mina,maxa,minb,maxb,x);
	if(y<=n) {mina=min(mina,y); maxa=max(maxa,y);}
	else {minb=min(minb,y-n); maxb=max(maxb,y-n);}
	ans-=calc(mina,maxa,minb,maxb);
	ans+=calc(mina,maxa,minb,maxb,x);
	return ans;
}
void solve()
{
	int sz=(int)cycle.size();
	int mina=INF,maxa=-INF,minb=INF,maxb=-INF;
	for(auto x:cycle)
	{
		if(x<=n) {mina=min(mina,x); maxa=max(maxa,x);}
		else {minb=min(minb,x-n); maxb=max(maxb,x-n);}
	}
	ans+=1LL*calc(mina,maxa,minb,maxb)*(sz/2);
	for(int i=0;i<sz;i++)
	{
		int mina=INF,maxa=-INF,minb=INF,maxb=-INF;
		int x=cycle[i];
		if(x<=n) {mina=min(mina,x); maxa=max(maxa,x);}
		else {minb=min(minb,x-n); maxb=max(maxb,x-n);}
		int last=i-1;
		if(last==-1) last=sz-1;
		for(int len=1;len<sz;len++)
		{
			int cur=i+len;
			if(cur>=sz) cur-=sz;
			int x=cycle[cur];
			if(x<=n) {mina=min(mina,x); maxa=max(maxa,x);}
			else {minb=min(minb,x-n); maxb=max(maxb,x-n);}
			int nxt=cur+1;
			if(nxt==sz) nxt=0;
			ans+=calc(mina,maxa,minb,maxb,cycle[last],cycle[nxt])*((len+1)/2);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y); G[y].push_back(x); 
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cycle.clear();
			dfs(i);
			solve();
		}
	}
	printf("%lld\n",ans);
	return 0;
}