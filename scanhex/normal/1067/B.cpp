#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int N = 100000 + 10;

vector<int> g[N];
void fail()
{
	 cout << "NO\n";
	 exit(0);
}

int k = 0;

void d(int u, int p, int curd)
{
	if (p == -1)
	{
		if (g[u].size() < 3)
			fail();
	}
	else 
	{
		if (g[u].size() < 4 && g[u].size() != 1)
		{
			cerr << "kek\n";
			fail();
		}

		if (curd > k || (g[u].size() == 1 && curd < k))
		{
			cerr << curd << ' ' << k << '\n';
			fail();
		}
	}
	for (int v : g[u])
	{
		if (v == p)
			continue;
		d(v, u, curd + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> k;
	if (k > 30)
	{
		 cout << "NO\n";
		 return 0;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		 int a, b;
		 cin >> a >> b;
		 --a, --b;
		 g[a].push_back(b);
		 g[b].push_back(a);
	}
	vector<int> q = {0};
	vector<int> dist(n, -1);
	vector<int> prev(n, -1);
	dist[0] = 0;
	for (int i = 0; i < q.size(); ++i)
	{
		int x = q[i];
		for (int y : g[x])
			if (dist[y] == -1)
				dist[y] = dist[x] + 1, q.emplace_back(y), prev[y] = x;
	}
	fill(prev.begin(), prev.end(), -1);
	int mem = max_element(dist.begin(), dist.end()) - dist.begin();
	q = {mem};
	fill(dist.begin(), dist.end(), -1);
	fill(prev.begin(), prev.end(), -1);
	dist[mem] = 0;
	for (int i = 0; i < q.size(); ++i)
	{
		int x = q[i];
		for (int y : g[x])
			if (dist[y] == -1)
				dist[y] = dist[x] + 1, q.emplace_back(y), prev[y] = x;
	}
	int kek = max_element(dist.begin(), dist.end()) - dist.begin();
	vector<int> path;
	while (kek != mem)
		path.push_back(kek), kek = prev[kek];
	path.push_back(mem);
	if (path.size() % 2 == 0)
		fail();
	int cent = path[path.size() / 2];
	//cerr << cent << '\n';
	d(cent, -1, 0);
	cout << "YES\n";
	return 0;
}