#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 101111;

vector <int> edges[N];

int last[N];
vector <int> c[N];
vector <int> ed[N];

struct AC_automaton
{
	struct Node
	{
		Node *nxt[26];
		Node *fail;
		int id;
		Node() { }
		void init(int id)
		{
			this -> id = id;
			fail = NULL;
			memset(nxt, 0, sizeof(nxt));
		}
	}node[N], *root;
	int node_cnt;
	AC_automaton() { }

	void init()
	{
		node[0].init(0);
		root = &node[0];
		node_cnt = 1;
	}
	void insert(string &s, int sid)
	{
		Node *p = root;
		for(int i = 0; i < s.size(); i ++)
		{
			int tmp = s[i] - 'a';
			if(p -> nxt[tmp] == NULL)
			{
				node[node_cnt].init(node_cnt);
				p -> nxt[tmp] = &node[node_cnt ++];
			}
			p = p -> nxt[tmp];
			c[p -> id].push_back(sid);
		}
		last[sid] = p -> id;
		ed[p -> id].push_back(sid);
	}
	void build()
	{
		root -> fail = root;
		queue <Node*> que;
		que.push(root);
		while(!que.empty())
		{
			Node *p = que.front();
			que.pop();
			if(p != root)
				edges[p -> fail -> id].push_back(p -> id);
			for(int i = 0; i < 26; i ++)
				if(p -> nxt[i] != NULL)
				{
					Node *q = p -> fail;
					while(q != root && q -> nxt[i] == NULL)
						q = q -> fail;
					if(q -> nxt[i] != NULL && p != q)
						p -> nxt[i] -> fail = q -> nxt[i];
					else
						p -> nxt[i] -> fail = root;
					que.push(p -> nxt[i]);
				}
		}
	}
}ac;

struct Query
{
	int l, r;
	long long ans;
	int pos;
	Query() { }
	Query(int l, int r, int pos) : l(l), r(r), pos(pos) { ans = 0; }
};

const int Block = 320;
struct Sqrt_array
{
	int a[N];
	int tot[N / Block + 5];
	Sqrt_array() { }
	void init()
	{
		memset(a, 0, sizeof(a));
		memset(tot, 0, sizeof(tot));
	}
	void change(int pos, int c)
	{
		int bs = pos / Block;
		for(int i = bs + 1; i < N / Block + 5; i ++)
			tot[i] += c;
		for(int i = pos; i < (bs + 1) * Block; i ++)
			a[i] += c;
	}
	int query(int pos)
	{
		return a[pos] + tot[pos / Block];
	}
}sa;

long long ans[N];
int size[N];
vector <Query> queries[N];

long long sum[N];
int dfs1(int cur, int x)
{
	int cnt = 0;
	for(int i = 0; i < c[cur].size(); i ++)
		if(c[cur][i] == x)
			cnt ++;
	for(int i = 0; i < edges[cur].size(); i ++)
		cnt += dfs1(edges[cur][i], x);
	for(int i = 0; i < ed[cur].size(); i ++)
		sum[ed[cur][i]] += cnt;
	return cnt;
}

void dfs2(int cur)
{
	for(int i = 0; i < ed[cur].size(); i ++)
		sa.change(ed[cur][i], 1);
	for(int i = 0; i < c[cur].size(); i ++)
		if(size[c[cur][i]] <= Block)
			for(int j = 0; j < queries[c[cur][i]].size(); j ++)
				queries[c[cur][i]][j].ans += sa.query(queries[c[cur][i]][j].r) - sa.query(queries[c[cur][i]][j].l - 1);
	for(int i = 0; i < edges[cur].size(); i ++)
		dfs2(edges[cur][i]);
	for(int i = 0; i < ed[cur].size(); i ++)
		sa.change(ed[cur][i], -1);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	ac.init();
	for(int i = 1; i <= n; i ++)
	{
		string str;
		cin >> str;
		size[i] = str.size();
		ac.insert(str, i);
	}
	ac.build();
	for(int i = 1; i <= q; i ++)
	{
		int l, r, k;
		cin >> l >> r >> k;
		queries[k].push_back(Query(l, r, i));
	}

	for(int i = 1; i <= n; i ++)
		if(size[i] > Block)
		{
			memset(sum, 0, sizeof(sum));
			dfs1(0, i);
			for(int i = 1; i <= n; i ++)
				sum[i] += sum[i - 1];
			for(int j = 0; j < queries[i].size(); j ++)
				queries[i][j].ans = sum[queries[i][j].r] - sum[queries[i][j].l - 1];
		}

	sa.init();
	dfs2(0);

	for(int i = 1; i <= n; i ++)
		for(int j = 0; j < queries[i].size(); j ++)
			ans[queries[i][j].pos] = queries[i][j].ans;
	for(int i = 1; i <= q; i ++)
		cout << ans[i] << '\n';
	return 0;
}