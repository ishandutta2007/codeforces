#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 121111;

struct Subtree
{
	int max_cnt;
	long long sum_color;
	map <int, int> cnt;
	Subtree() { }
	void init(int color)
	{
		max_cnt = 1;
		sum_color = color;
		cnt.clear();
		cnt[color] = 1;
	}
	void swap(Subtree &rhs)
	{
		cnt.swap(rhs.cnt);
		::swap(max_cnt, rhs.max_cnt);
		::swap(sum_color, rhs.sum_color);
	}
	void merge(Subtree &rhs)
	{
		if(cnt.size() < rhs.cnt.size())
			swap(rhs);
		for(auto it = rhs.cnt.begin(); it != rhs.cnt.end(); it ++)
		{
			cnt[it -> first] += it -> second;
			int tmp = cnt[it -> first];
			if(tmp > max_cnt)
			{
				max_cnt = tmp;
				sum_color = it -> first;
			}
			else if(tmp == max_cnt)
				sum_color += it -> first;
		}
	}
}subtree[N];

long long ans[N];
int color[N];
vector <int> edges[N];

void dfs(int cur, int last = -1)
{
	subtree[cur].init(color[cur]);
	for(auto &v : edges[cur])
		if(last != v)
		{
			dfs(v, cur);
			subtree[cur].merge(subtree[v]);
		}
	ans[cur] = subtree[cur].sum_color;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> color[i];
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1);
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}