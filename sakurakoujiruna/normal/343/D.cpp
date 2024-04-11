#include <iostream>
#include <vector>
using namespace std;

const int N = 1000011;

vector <int> edges[N];
int anc[N];
int size[N];
int depth[N];
int heavy_child[N];
void dfs1(int cur, int last = -1)
{
	size[cur] = 1;
	for(auto &v : edges[cur])
		if(v != last)
		{
			anc[v] = cur;
			depth[v] = depth[cur] + 1;
			dfs1(v, cur);
			size[cur] += size[v];
		}
	heavy_child[cur] = -1;
	for(auto &v : edges[cur])
		if(v != last)
			if(heavy_child[cur] == -1 || size[v] > size[heavy_child[cur]])
				heavy_child[cur] = v;
}

int top[N];
int nid[N];
void dfs2(int cur, int chain_top, int &cnt, int last = -1)
{
	top[cur] = chain_top;
	nid[cur] = ++cnt;
	if(heavy_child[cur] != -1)
		dfs2(heavy_child[cur], chain_top, cnt, cur);
	for(auto &v : edges[cur])
		if(v != last && v != heavy_child[cur])
			dfs2(v, v, cnt, cur);
}

int in[N], out[N];
void dfs3(int cur, int &cnt, int last = -1)
{
	in[cur] = ++ cnt;
	for(auto &v : edges[cur])
		if(v != last)
			dfs3(v, cnt, cur);
	out[cur] = (++ cnt) + 1;
}

struct SegTree
{
	int l[N << 2], r[N << 2];
	int sm[N << 2];
	SegTree() { }
	void init(int left, int right, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		sm[x] = 0;
		if(left + 1 != right)
		{
			int mid = (left + right) / 2;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
		}
	}
	void change(int pos, int c, int x = 1)
	{
		if(l[x] + 1 == r[x])
			sm[x] = c;
		else
		{
			int mid = (l[x] + r[x]) / 2;
			if(pos < mid)
				change(pos, c, 2 * x);
			else
				change(pos, c, 2 * x + 1);
			sm[x] = max(sm[2 * x], sm[2 * x + 1]);
		}
	}
	int query(int left, int right, int x = 1)
	{
		if(l[x] == left && r[x] == right)
			return sm[x];
		int mid = (l[x] + r[x]) / 2;
		if(right <= mid)
			return query(left, right, 2 * x);
		else if(left >= mid)
			return query(left, right, 2 * x + 1);
		else
			return max(query(left, mid, 2 * x), query(mid, right, 2 * x + 1));
	}
}st[2];

int query(int x)
{
	int ans = 0;
	anc[1] = -1;
	while(x != -1)
	{
		ans = max(ans, st[0].query(nid[top[x]], nid[x] + 1));
		x = anc[top[x]];
	}
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs1(1);
	int cnt = 0;
	dfs2(1, 1, cnt);
	cnt = 0;
	dfs3(1, cnt);
	
	st[0].init(1, n + 1);
	st[1].init(1, 2 * n + 1);

	int q;
	cin >> q;
	for(int i = 1; i <= q; i ++)
	{
		int c, v;
		cin >> c >> v;
		if(c == 1)
			st[0].change(nid[v], i);
		else if(c == 2)
			st[1].change(in[v], i);
		else
		{
			int f = query(v);
			int e = st[1].query(in[v], out[v]);
			if(f > e)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
	
	return 0;
}