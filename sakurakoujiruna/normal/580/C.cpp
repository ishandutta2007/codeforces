#include <iostream>
#include <vector>
using namespace std;

const int N = 121111;

bool has_cat[N];
vector <int> edges[N];

int dfs(int cur, int last, int con_cnt, int max_con_cnt)
{
	if(has_cat[cur])
		con_cnt ++;
	else
		con_cnt = 0;
	if(con_cnt > max_con_cnt)
		return 0;

	int ret = 0;
	if(last != -1 && edges[cur].size() == 1)
		ret = 1;
	for(auto v: edges[cur])
		if(v != last)
			ret += dfs(v, cur, con_cnt, max_con_cnt);
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		cin >> has_cat[i];
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		u --;
		v --;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	cout << dfs(0, -1, 0, m) << '\n';
	return 0;
}