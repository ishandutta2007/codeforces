#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
map<P,int> id;
P ans[MAXN];
set<P> s;
void bfs()
{
	queue<P> que;
	for(auto p:s) if(!id[p]) que.push(p);
	while(que.size())
	{
		P p=que.front(); que.pop();
		P res;
		if(!id[p]) res=p; else res=ans[id[p]];
		for(int i=0;i<4;i++)
		{
			int nx=p.F+dx[i],ny=p.S+dy[i];
			P q=P(nx,ny);
			if(!id[q]||ans[id[q]]!=P(-1,-1)) continue;
			ans[id[q]]=res;
			que.push(q);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d%d",&x[i],&y[i]);
		id[P(x[i],y[i])]=i;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<4;j++)
			s.insert(P(x[i]+dx[j],y[i]+dy[j]));
	for(int i=1;i<=n;i++) ans[i]=P(-1,-1);
	bfs();
	for(int i=1;i<=n;i++) printf("%d %d\n",ans[i].F,ans[i].S);
	return 0;
}