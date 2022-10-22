#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

map<vector<int>, int> mp;

int que(vector<int> s)
{
	sort(s.begin(), s.end());
	if (s.size() <= 1)
		return 0;
	if (mp.count(s))
		return mp[s];
	cout << "? " << s.size() << endl;
	for (auto &x : s)
		cout << x + 1 << ' ';
	cout << endl;
	int x;
	cin >> x;
	return mp[s] = x;
}

int que(vector<int> a, vector<int> b)
{
	vector<int> c = a;
	for (auto& x : b)
		c.push_back(x);
	return que(c) - que(a) - que(b);
}

int que(vector<int> a, int b)
{
	int x = que(a);
	a.push_back(b);
	return que(a) - x;
}
const int N = 600;
vector<pair<int, int>> edg;
int part[N];

int find(vector<int> a, int b)
{
	int L = 0, R = a.size();
	while (R - L > 1)
	{
		int M = (L + R) / 2;
		vector<int> q(a.begin(), a.begin() + M);
		if (que(q, b))
			R = M;
		else
			L = M;
	}
	return a[R - 1];
}

void solve(vector<int> inds)
{
	if (inds.size() <= 1)
		return;
	int sz = inds.size();
	vector<bool> mem(inds.size());
	mem[0] = true;
	while (count(mem.begin(), mem.end(), false) > 0)
	{
		vector<int> a, b;
		for (int i = 0; i < sz; ++i)
			if (mem[i])
				a.push_back(inds[i]);
			else
				b.push_back(inds[i]);
		if (que(a, b) == 0)
		{
			solve(a);
			solve(b);
			return;
		}
		int L = 0, R = sz;
		while (R - L > 1)
		{
			int M = (L + R) / 2;
			a.clear();
			b.clear();
			for (int i = 0; i < sz; ++i)
				if (mem[i])
					a.push_back(inds[i]);
				else if (i < M)
					b.push_back(inds[i]);
			if (que(a, b))
				R = M;
			else
				L = M;
		}
		int to = inds[R - 1];
		L = 0, R = sz;
		while (R - L > 1)
		{
			int M = (L + R) / 2;
			a.clear();
			b.clear();
			for (int i = 0; i < M; ++i)
				if (mem[i])
					a.push_back(inds[i]);
			if (que(a, to))
				R = M;
			else
				L = M;
		}
		int from = inds[R - 1];
		edg.emplace_back(from, to);
		mem[lower_bound(inds.begin(), inds.end(), to) - inds.begin()] = true;
	}
}

vector<int> g[N];
int c[N];

void d(int u, int col)
{
	if (c[u] != -1)
		return;
	c[u] = col;
	for (int v : g[u])
		d(v, col ^ 1);
}

int p[N];

int getp(int x)
{
	 return p[x] == x ? x : p[x] = getp(p[x]);
}

void unite(int a, int b)
{
	 p[getp(a)] = getp(b);
}

int main()
{
	int n;
	cin >> n;
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	solve(ord);
	vector<pair<int, int>> edg1;
	iota(p, p + N, 0);
	for (auto& x : edg)
	{
		if (getp(x.first) != getp(x.second))
			edg1.push_back(x), unite(x.first, x.second);
	}
	edg = edg1;
	for (auto& x : edg)
		g[x.first].push_back(x.second),
			g[x.second].push_back(x.first);
	fill(c, c + n, -1);
	for (int i = 0; i < n; ++i)
	{
		if (c[i] == -1)
			d(i, 0);
	}
	vector<vector<int>> whic(2);
	for (int i = 0; i < n; ++i)
		whic[c[i]].push_back(i);
	for (int i = 0; i < n; ++i)
	{
		vector<int> v = whic[c[i]];
		v.erase(find(v.begin(), v.end(), i));
		if (que(v, i))
		{
			int j = find(v, i);
			vector<int> prev(n, -1);
			vector<int> q = {i};
			prev[i] = -2;
			for (int k = 0; k < q.size(); ++k)
			{
				int x = q[k];
				for (int y : g[x])
					if (prev[y] == -1)
						prev[y] = x, q.push_back(y);
			}
			vector<int> path;
			path.push_back(j);
			while (j != i)
			{
				j = prev[j];
				path.push_back(j);
			}
			cout << "N " << path.size() << endl;
			for (auto& x : path)
				cout << x + 1 << ' ';
			cout << endl;
			return 0;
		}
	}
	cout << "Y " << count(c, c + n, 0) << endl;
	for (int i = 0; i < n; ++i)
		if (c[i] == 0)
			cout << i + 1 << ' ';
	cout << endl;
	return 0;
}