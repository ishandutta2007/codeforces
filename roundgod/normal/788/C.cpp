#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
bool valid[MAXN],visited[2*MAXN];
vector<int> G[2*MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	memset(valid,false,sizeof(valid));
	bool f1=false,f2=false,f3=false;
	for(int i=0;i<k;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==n) f3=true;
		if(x>n) f2=true;
		if(x<n) f1=true;
		valid[x]=true;
	}
	if(f3)
	{
		puts("1");
		return 0;
	}
	if(!f1||!f2)
	{
		puts("-1");
		return 0;
	}
	for(int i=0;i<=1000;i++)
	{
		if(!valid[i]) continue;
		for(int j=0;j<=2000;j++)
		{
			int to=j+i-n;
			if(to>2000||to<0) continue;
			G[j].push_back(to);
		}
	}
	queue<P> que;
	memset(visited,false,sizeof(visited));
	que.push(P(1000,0));
	while(!que.empty())
	{
		P p=que.front();
		que.pop();
		if(visited[p.F]) continue;
		if(p.F!=1000) visited[p.F]=true;
		if(p.F==1000&&p.S!=0)
		{
			printf("%d\n",p.S);
			return 0;
		}
		for(int i=0;i<G[p.F].size();i++)
		{
			if(visited[G[p.F][i]]) continue;
			que.push(P(G[p.F][i],p.S+1));
		}
	}
	return 0;
}