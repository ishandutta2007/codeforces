#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100011;

vector <int> edges[N];
int u[N], v[N];
int deg[N];

int check(int n)
{
	queue <int> que;
	for(int i = 1; i <= n; i ++)
		if(deg[i] == 0)
			que.push(i);
	bool multi = false;
	int cnt = 0;
	while(!que.empty())
	{
		if(que.size() > 1)
			multi = true;
		int cur = que.front();
		que.pop();
		cnt ++;
		for(auto &v : edges[cur])
		{
			deg[v] --;
			if(deg[v] == 0)
				que.push(v);
		}
	}
	if(cnt != n)
		return 1;
	if(multi)
		return -1;
	return 0;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++)
		cin >> u[i] >> v[i];

	int left = 1, right = m + 1;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		for(int i = 0; i < N; i ++)
			edges[i].clear();
		memset(deg, 0, sizeof(deg));
		for(int i = 1; i <= mid - 1; i ++)
		{
			edges[u[i]].push_back(v[i]);
			deg[v[i]] ++;
		}
		if(check(n) >= 0)
			right = mid;
		else
			left = mid;
	}
	for(int i = 0; i < N; i ++)
		edges[i].clear();
	memset(deg, 0, sizeof(deg));
	for(int i = 1; i <= left; i ++)
	{
		edges[u[i]].push_back(v[i]);
		deg[v[i]] ++;
	}
	if(check(n) == 0)
		cout << left << '\n';
	else
		cout << -1 << '\n';
	return 0;
}