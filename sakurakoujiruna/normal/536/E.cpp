#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100011;
const int M = 20;

int f[N];

struct Seg
{
	int len;
	bool all;
	int l, r;
	int sum;
	Seg() { }
	Seg(int len, bool all, int l, int r, int sum) : len(len), all(all), l(l), r(r), sum(sum) { }
	Seg reverse()
	{
		Seg res = *this;
		swap(res.l, res.r);
		return res;
	}
	Seg merge(const Seg &rhs)
	{
		Seg res(len + rhs.len, false, 0, 0, sum + rhs.sum);
		if(all && rhs.all)
			res.all = true;
		else if(all)
		{
			res.l = len + rhs.l;
			res.r = rhs.r;
		}
		else if(rhs.all)
		{
			res.l = l;
			res.r = r + rhs.len;
		}
		else
		{
			res.l = l;
			res.r = rhs.r;
			res.sum += f[r + rhs.l];
		}
		return res;
	}
	int ans()
	{
		if(all)
			return f[len];
		return sum + f[l] + f[r];
	}
};

struct SegTree
{
	int l[N << 2];
	int r[N << 2];
	Seg seg[N << 2];
	SegTree() { }
	void init(int left, int right, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		seg[x] = Seg(right - left, false, 0, 0, 0);
		if(left + 1 < right)
		{
			int mid = (left + right) / 2;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
		}
	}
	void change(int pos, int x = 1)
	{
		if(l[x] + 1 == r[x])
			seg[x] = Seg(1, true, 0, 0, 0);
		else
		{
			int mid = (l[x] + r[x]) / 2;
			if(pos < mid)
				change(pos, 2 * x);
			else
				change(pos, 2 * x + 1);
			seg[x] = seg[2 * x].merge(seg[2 * x + 1]);
		}
	}
	Seg query(int left, int right, int x = 1)
	{
		if(l[x] == left && r[x] == right)
			return seg[x];
		int mid = (l[x] + r[x]) / 2;
		if(right <= mid)
			return query(left, right, 2 * x);
		else if(left >= mid)
			return query(left, right, 2 * x + 1);
		return query(left, mid, 2 * x).merge(query(mid, right, 2 * x + 1));
	}
}st;

vector <pair <int, int> > edges[N];
int ew[N];
int size[N];
int depth[N];
int heavy_child[N];
int anc[N][M];
#define v first
#define w second
void dfs1(int cur, int last = -1)
{
	size[cur] = 1;
	for(auto &p : edges[cur])
		if(p.v != last)
		{
			ew[p.v] = p.w;
			depth[p.v] = depth[cur] + 1;
			anc[p.v][0] = cur;
			dfs1(p.v, cur);
			size[cur] += size[p.v];
		}
	heavy_child[cur] = -1;
	for(auto &p : edges[cur])
		if(p.v != last)
			if(heavy_child[cur] == -1 || size[p.v] > size[heavy_child[cur]])
				heavy_child[cur] = p.v;
}

int top[N];
int nid[N];
void dfs2(int cur, int chain_top, int &cnt, int last = -1)
{
	top[cur] = chain_top;
	nid[cur] = ++ cnt;
	if(heavy_child[cur] != -1)
		dfs2(heavy_child[cur], chain_top, cnt, cur);
	for(auto &p : edges[cur])
		if(p.v != last && p.v != heavy_child[cur])
			dfs2(p.v, p.v, cnt, cur);
}
#undef v
#undef w

int lca(int u, int v)
{
	if(depth[u] > depth[v])
		swap(u, v);
	for(int i = M - 1; i >= 0; i --)
		if(depth[anc[v][i]] >= depth[u])
			v = anc[v][i];
	if(u == v)
		return u;
	for(int i = M - 1; i >= 0; i --)
		if(anc[u][i] != anc[v][i])
		{
			u = anc[u][i];
			v = anc[v][i];
		}
	return anc[u][0];
}

int ans[N];
struct Event
{
	int type; // 0: change, 1: query
	int par1; // w
	int par2; // 0: node, 1: qid
	Event(int type, int par1, int par2) : type(type), par1(par1), par2(par2) { }
	bool operator <(const Event &rhs) const
	{
		if(par1 == rhs.par1)
			return type < rhs.type;
		return par1 > rhs.par1;
	}
};

int u[N], v[N], l[N];

Seg query(int down, int up)
{
	//cout << down << ' ' << up << '\n';
	bool first = true;
	Seg res;
	while(down != up)
		if(depth[top[down]] > depth[up])
		{
			if(first)
			{
				first = false;
				res = st.query(nid[top[down]], nid[down] + 1);
			}
			else
				res = st.query(nid[top[down]], nid[down] + 1).merge(res);
			down = anc[top[down]][0];
		}
		else
		{
			int tmp = down;
			for(int i = M - 1; i >= 0; i --)
				if(depth[anc[tmp][i]] > depth[up])
					tmp = anc[tmp][i];
			if(first)
			{
				first = false;
				res = st.query(nid[tmp], nid[down] + 1);
			}
			else
				res = st.query(nid[tmp], nid[down] + 1).merge(res);
			down = anc[tmp][0];
		}
	return res;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i < n; i ++)
		cin >> f[i];
	for(int i = 1; i < n; i ++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}
	dfs1(1);
	int cnt = 0;
	dfs2(1, 1, cnt);
	anc[1][0] = 1;
	for(int j = 1; j < M; j ++)
		for(int i = 1; i <= n; i ++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	st.init(1, n + 1);

	vector <Event> events;
	for(int i = 2; i <= n; i ++)
		events.push_back(Event(0, ew[i], i));
	for(int i = 0; i < q; i ++)
	{
		cin >> u[i] >> v[i] >> l[i];
		events.push_back(Event(1, l[i], i));
	}
	sort(events.begin(), events.end());

	for(auto &eve : events)
		if(eve.type == 0)
			st.change(nid[eve.par2]);
		else
		{
			//cout << "------\n";
			int qid = eve.par2;
			//cout << qid << '\n';
			int up = lca(u[qid], v[qid]);
			if(up == u[qid])
				ans[qid] = query(v[qid], up).ans();
			else if(up == v[qid])
				ans[qid] = query(u[qid], up).ans();
			else
				ans[qid] = (query(u[qid], up).reverse().merge(query(v[qid], up))).ans();
		}
	for(int i = 0; i < q; i ++)
		cout << ans[i] << '\n';
	return 0;
}