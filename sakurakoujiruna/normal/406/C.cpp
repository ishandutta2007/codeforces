#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

const int N = 100011;

vector <int> edges[N];
int anc[N];
int depth[N];
bool vis[N];
void dfs1(int cur, int last = -1)
{
	vis[cur] = true;
	anc[cur] = last;
	for(auto &v : edges[cur])
		if(v != last && !vis[v])
		{
			depth[v] = depth[cur] + 1;
			dfs1(v, cur);
		}
}

set <pair <int, int> > st;
void dfs2(int cur, int last = -1)
{
	vis[cur] = true;
	vector <int> t;
	for(auto &v : edges[cur])
		if(v != last && !vis[v])
			dfs2(v, cur);
	
	for(auto &v : edges[cur])
		if(v != last && st.find({v, cur}) == st.end())
		{
			t.push_back(v);
			st.insert({cur, v});
			st.insert({v, cur});
		}
	if(t.size() & 1)
	{
		t.push_back(last);
		st.insert({last, cur});
		st.insert({cur, last});
	}
	for(int i = 0; i < t.size() / 2; i ++)
		cout << t[2 * i] << ' ' << cur << ' ' << t[2 * i + 1] << '\n';
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	if(m & 1)
		cout << "No solution\n";
	else
	{
		dfs1(1);
		memset(vis, 0, sizeof(vis));
		dfs2(1);
	}
	return 0;
}