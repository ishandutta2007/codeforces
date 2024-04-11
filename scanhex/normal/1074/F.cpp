#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
using ll = long long;

const int lg = 18;
const int N = 1 << lg;

pair<int, int> t[2 * N];
int psh[2 * N];
struct it
{
	it()
	{
		fill(t + N, t + 2 * N, make_pair(0, 1));
		for (int i = N - 1; i > 0; --i)
			update1(i);
	}
	void push1(int u)
	{
		psh[2 * u] += psh[u];
		psh[2 * u + 1] += psh[u];
		t[2 * u].first += psh[u];
		t[2 * u + 1].first += psh[u];
		psh[u] = 0;
	}
	void push(int u)
	{
		 for (int i = lg; i > 0; --i)
		 {
			 int x = u >> i;
			 push1(x);
		 }
	}
	void update1(int u)
	{
		t[u].first = max(t[2 * u].first, t[2 * u + 1].first);
		t[u].second = 0;
		if (t[2 * u].first == t[u].first)
			t[u].second += t[2 * u].second;
		if (t[2 * u + 1].first == t[u].first)
			t[u].second += t[2 * u + 1].second;
	}
	void update(int x)
	{
		while (x > 1)
			update1(x >> 1), x >>= 1;
	}
	void apply(int x, int val)
	{
		t[x].first += val;
		psh[x] += val;
	}
	void add(int l, int r, int val)
	{
//		cerr << "add " << l << ' ' << r << ' ' << val << '\n';
		 l += N;
		 r += N;
		 int l1 = l, r1 = r;
		 push(l);
		 push(r - 1);
		 while (l < r)
		 {
			 if (l & 1)
				 apply(l++, val);
			 if (r & 1)
				 apply(--r, val);
			 l >>= 1, r >>= 1;
		 }
		 push(l1);
		 push(r1 - 1);
		 update(l1);
		 update(r1 - 1);
	}
	pair<int, int> merge(pair<int, int> a, pair<int, int> b)
	{
		if (a.first != b.first)
			return max(a, b);
		return {a.first, a.second + b.second};
	}
	pair<int, int> get(int l, int r)
	{
		l += N;
		r += N;
		push(l);
		push(r - 1);
		pair<int, int> ans = {-1, 0};
		while (l < r)
		{
			 if (l & 1)
				 ans = merge(ans, t[l++]);
			 if (r & 1)
				 ans = merge(ans, t[--r]);
			 l >>= 1, r >>= 1;
		}
		return ans;
	}
};

vector<int> gt[N];

#define time aetnuh
int tin[N];
int tout[N];
int de[N];
int par[N];
int ups[N][lg];
int time = 0;

void init(int u, int p)
{
	par[u] = p;
	tin[u] = time++;
	for (auto& v : gt[u])
		if (v != p)
			de[v] = de[u] + 1, init(v, u);
	tout[u] = time;
}

int n;

it myit;

void add(int u, int v, int mul)
{
	if (tin[v] <= tin[u] && tout[u] <= tout[v])
		swap(u, v);
	myit.add(tin[v], tout[v], mul);
	if (tin[u] <= tin[v] && tout[v] <= tout[u])
	{
		myit.add(0, n, mul);
		int mem = v;
		for (int i = lg - 1; i >= 0; --i)
			if (de[mem] - (1 << i) >= de[u] + 1)
				mem = ups[mem][i];
		myit.add(tin[mem], tout[mem], -mul);
	}
	else
		myit.add(tin[u], tout[u], mul);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; ++i)
	{
		 int a, b;
		 cin >> a >> b;
		 --a, --b;
		 gt[a].push_back(b);
		 gt[b].push_back(a);
	}
	init(0, -1);
	par[0] = 0;
	for (int i = 0; i < n; ++i)
		ups[i][0] = par[i];
	for (int j = 0; j + 1 < lg; ++j)
		for (int i = 0; i < n; ++i)
			ups[i][j + 1] = ups[ups[i][j]][j];
	set<pair<int, int>> st;
	while (q--)
	{
		int u, v;
		cin >> u >> v;
		if (u < v)
			swap(u, v);

		--u, --v;
		auto p = make_pair(u - 1, v - 1);
		if (!st.count(p))
		{
			add(u, v, 1);
			st.insert(p);
		}
		else
		{
			add(u, v, -1);
			st.erase(p);
		}
		auto p1 = myit.get(0, n);
		int ans = p1.second;
		if (p1.first < (int)st.size())
			ans = 0;
		cout << ans << '\n';
	}

	return 0;
}