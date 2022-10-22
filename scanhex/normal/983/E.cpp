#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 20;
struct it
{
	int t[2 * N];
	it()
	{
		fill(t, t + 2 * N, 0);
	}
	int get(int l, int r)
	{
		l += N;
		r += N;
		int ans = 0;
		while (l < r)
		{
			if (l & 1)
				ans += t[l++];
			if (r & 1)
				ans += t[--r];
			l >>= 1, r >>= 1;
		}
		return ans;
	}
	void add(int x, int y)
	{
		x += N;
		t[x] += y;
		while (x)
			t[x >> 1] = t[x] + t[x ^ 1], x >>= 1;
	}
};

vector<int> ch[N];

int t = 0;
int de[N];
int tin[N];
int tout[N];

void d(int u)
{
	tin[u] = t++;
	for (int v : ch[u])
		de[v] = de[u] + 1, d(v);
	tout[u] = t++;
}

const int C = 20;
int ups[C][N];

int lca(int x, int y)
{
	if (de[x] > de[y])
		swap(x, y);
	for (int i = C - 1; i >= 0; --i)
		if (de[y] - de[x] >= (1 << i))
			y = ups[i][y];
	if (x == y)
		return x;
	for (int i = C - 1; i >= 0; --i)
		if (ups[i][x] != ups[i][y])
			x = ups[i][x], y = ups[i][y];
	return ups[0][x];
}

struct ev
{
	int x, l, r, id, type;
	bool operator <(ev b) const 
	{
		if (x != b.x)
			return x < b.x;
		return type < b.type;
	}
	ev(int x, int l, int r, int id, int type)
		: x(x), l(l), r(r), id(id), type(type)
	{}
};

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> par(n);
	for (int i = 1; i < n; ++i)
	{
		int p;
		cin >> p;
		--p;
		par[i] = p;
		ch[p].push_back(i);
	}
	d(0);
	int m;
	cin >> m;
	vector<pair<int, int>> buses(m);
	for (auto& x : buses)
		cin >> x.first >> x.second, --x.first, --x.second;
	vector<pair<int, int>> que;
	int q;
	cin >> q;
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		--u, --v;
		que.emplace_back(u, v);
	}
	q = que.size();
	int C = 20;
	par[0] = 0;
	for (int i = 0; i < n; ++i)
		ups[0][i] = par[i];
	for (int i = 0; i + 1 < C; ++i)
		for (int j = 0; j < n; ++j)
			ups[i + 1][j] = ups[i][ups[i][j]];
	vector<int> go(n);
	iota(go.begin(), go.end(), 0);
	for (auto x : buses)
	{
		int l = lca(x.first, x.second);
		go[x.first] = min(go[x.first], l);
		go[x.second] = min(go[x.second], l);
	}
	for (int i = n - 1; i >= 0; --i)
		go[par[i]] = min(go[par[i]], go[i]);
	vector<int> ansich(q);
	vector<vector<int>> ups1(C, vector<int>(n));
	ups1[0] = go;
	for (int i = 0; i + 1 < C; ++i)
		for (int j = 0; j < n; ++j)
			ups1[i + 1][j] = ups1[i][ups1[i][j]];

	vector<ev> evs;
	vector<bool> bad(q);
	for (int i = 0; i < q; ++i)
	{
		int a = que[i].first, b = que[i].second;
		int l = lca(a, b);
		int ans = 0;
		int a1 = a, b1 = b;
		for (int j = C - 1; j >= 0; --j)
		{
			if (ups1[j][a] > l)
				ans += (1 << j), a = ups1[j][a];
			if (ups1[j][b] > l)
				ans += (1 << j), b = ups1[j][b];
		}
		int a2 = a, b2 = b;
		bad[i] = a1 == l || b1 == l;
		if (a != l)
			a = go[a], ++ans;
		if (b != l)
			b = go[b], ++ans;
		if (a > l || b > l)
		{
			bad[i] = 1;
			ansich[i] = -1;
			continue;
		}
		a = a1, b = b1;
		ansich[i] = ans;
		if (bad[i])
			continue;
		int lx = tin[a2];
		int rx = tout[a2];
		int ly = tin[b2];
		int ry = tout[b2]; 
//		cerr << lx << ' ' << rx << ' ' << ly << ' ' << ry << '\n';
		evs.emplace_back(lx, ly, ry, i, 0);
		evs.emplace_back(rx, ly, ry, i, -1);
	}
	for (auto x : buses)
	{
		evs.emplace_back(tin[x.first], tin[x.second], 0, -1, 1);
		evs.emplace_back(tin[x.second], tin[x.first], 0, -1, 1);
//		cerr << tin[x.first] << ' ' << tin[x.second] << '\n';
	}
	sort(evs.begin(), evs.end());
	it cur;
	vector<int> ans1(q);
	for (auto x : evs)
	{
		if (x.type == 1)
			cur.add(x.l, 1);
		if (x.type == -1)
			ans1[x.id] += cur.get(x.l, x.r);
		if (x.type == 0)
			ans1[x.id] -= cur.get(x.l, x.r);
	}
	for (int i = 0; i < q; ++i)
	{
		if (ans1[i] > 0 && !bad[i])
			--ansich[i];
		cout << ansich[i] << '\n';
	}
}