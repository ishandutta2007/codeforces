#include <iostream>
#include <vector>
#define MAXN 1000100
typedef long long ll;
using namespace std;
vector<int> conn[MAXN];
bool self[MAXN];
bool vis[MAXN];
ll N, M;
int x, y;
ll counter;
ll ans;
void dfs(int node)
{
	if(vis[node])
	{
		return;
	}
	vis[node] = true;
	for(int j=0; j<conn[node].size(); j++)
	{
		if(conn[node][j] != node)
			dfs(conn[node][j]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0; i<M; i++)
	{
		cin>>x>>y;
		if(x!=y)
		{
			ans += (ll) (conn[x].size());
			ans += (ll) (conn[y].size());
			conn[x].push_back(y);
			conn[y].push_back(x);
		}
		else
		{
			self[x] = true;
			counter++;
			ans += (M-counter);
		}
	}
	for(int i=1; i<=N; i++)
	{
		if(conn[i].size()>0||self[i])
		{
			dfs(i);
			break;
		}
	}
	for(int i=1; i<=N; i++)
	{
		if((conn[i].size() > 0||self[i]) && !vis[i])
		{
			cout<<0<<endl;
			return  0;
		}
	}
	cout<<ans<<endl;
}