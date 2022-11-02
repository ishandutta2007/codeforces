#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 121111;
const int M = 23;

vector <int> imerge(const vector <int> &a, const vector <int> &b)
{
	vector <int> ret;
	/*
	vector <int> tmp;
	for(int i = 0; i < 20; i ++)
	{
		tmp.push_back(a[i]);
		tmp.push_back(b[i]);
	}
	sort(tmp.begin(), tmp.end());
	int cnt = 0;
	for(int i = 0; i < 40; i ++)
	{
		if(cnt < 20 && (i == 0 || tmp[i] != tmp[i - 1] || tmp[i] == 999999))
		{
			ret.push_back(tmp[i]);
			cnt ++;
		}
	}
	*/
	int p_a = 0;
	int p_b = 0;
	int cnt = 0;
	while(cnt < 10)
	{
		if(p_a == 10)
			ret.push_back(b[p_b ++]);
		else if(p_b == 10)
			ret.push_back(a[p_a ++]);
		else if(a[p_a] < b[p_b])
			ret.push_back(a[p_a ++]);
		else if(a[p_a] > b[p_b])
			ret.push_back(b[p_b ++]);
		else
		{
			ret.push_back(a[p_a ++]);
			p_b ++;
		}
		cnt ++;
	}
	return ret;
}

int height[N];
int anc[N][M];
vector <int> edges[N];
vector <int> people[N][M];

void dfs_get_anc(int cur, int last = -1)
{
	if(last == -1)
	{
		height[cur] = 0;
		for(int i = 0; i < M; i ++)
			anc[cur][i] = cur;
		for(int i = 1; i < M; i ++)
			people[cur][i] = people[cur][0];
	}
	else
	{
		for(int i = 1; i < M; i ++)
		{
			anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
			people[cur][i] = imerge(people[cur][i - 1], people[anc[cur][i - 1]][i - 1]);
		}
	}

	for(int i = 0; i < edges[cur].size(); i ++)
	{
		int v = edges[cur][i];
		if(v == last)
			continue;
		anc[v][0] = cur;
		height[v] = height[cur] + 1;
		dfs_get_anc(v, cur);
	}
}

void swim(int &x, int h)
{
	for(int i = 0; h > 0; i ++)
	{
		if(h & 1)
			x = anc[x][i];
		h /= 2;
	}
}

int get_lca(int x, int y)
{
	if(height[x] > height[y])
		swap(x, y);
	swim(y, height[y] - height[x]);
	if(x == y)
		return x;
	while(true)
	{
		int i;
		for(i = 0; anc[x][i] != anc[y][i]; i ++);
		if(i == 0)
			return anc[x][0];
		x = anc[x][i - 1];
		y = anc[y][i - 1];
	}
	return -1;
}

vector <int> get_ans(int cur, int lca)
{
	vector <int> ans = people[lca][0];

	for(int i = M - 1; i >= 0; i --)
		if(height[anc[cur][i]] >= height[lca])
		{
			ans = imerge(ans, people[cur][i]);
			cur = anc[cur][i];
			if(cur == lca)
				break;
		}
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j < 10; j ++)
			people[i][0].push_back(999999);
	for(int i = 1; i <= m; i ++)
	{
		int x;
		cin >> x;
		people[x][0].push_back(i);
	}
	for(int i = 1; i <= n; i ++)
	{
		vector <int> tmp = people[i][0];
		sort(tmp.begin(), tmp.end());
		people[i][0].clear();
		for(int j = 0; j < 10; j ++)
			people[i][0].push_back(tmp[j]);
	}

	dfs_get_anc(1);
	/*
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j < M; j ++)
			cout << i << ' ' << j << ' ' << anc[i][j] << '\n';
	*/
	while(q --)
	{
		int u, v, a;
		cin >> u >> v >> a;
		int lca = get_lca(u, v);
		//cout << lca << '\n';
		
		vector <int> ans = imerge(get_ans(u, lca), get_ans(v, lca));

		int cnt = 0;
		for(int i = 0; i < a; i ++)
			if(ans[i] != 999999)
				cnt ++;
		cout << cnt << ' ';
		for(int i = 0; i < a; i ++)
			if(ans[i] != 999999)
				cout << ans[i] << ' ';
		cout << '\n';
		
	}
	
	return 0;
}