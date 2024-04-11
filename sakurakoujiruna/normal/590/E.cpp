#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
#include <cassert>
using namespace std;

const int N = 10011111;
const int M = 768;

//int last[M];
//vector <int> edges[N];
//bitset <M> vis[N];
//vector <int> q[N];
//vector <int> q_last[N];

bool g_edge[M][M];
vector <int> g[M];

struct AC_automaton
{
	struct Node
	{
		Node *fail;
		Node *s_fail;
		Node *nxt[2];
		int id;
		int sid;
		Node() { }
		void init(int id)
		{
			this -> id = id;
			sid = -1;
			fail = NULL;
			nxt[0] = nxt[1] = NULL;
		}
	}node[N], *root;
	int node_id;
	AC_automaton() { }
	void init()
	{
		root = &node[0];
		node[0].init(0);
		node_id = 1;
	}

	void insert(string &s, int sid)
	{
		Node *p = root;
		for(int i = 0; i < s.size(); i ++)
		{
			int tmp = s[i] - 'a';
			if(p -> nxt[tmp] == NULL)
			{
				node[node_id].init(node_id);
				p -> nxt[tmp] = &node[node_id];
				node_id ++;
			}
			p = p -> nxt[tmp];
			//vis[p -> id][sid] = 1;
			//q[p -> id].push_back(sid);
		}
		//q_last[p -> id].push_back(sid);
		p -> sid = sid;
	}

	void build()
	{
		root -> fail = root;
		root -> s_fail = root;
		queue <Node*> que;
		que.push(root);
		while(!que.empty())
		{
			Node *p = que.front();
			que.pop();

			for(int i = 0; i < 2; i ++)
				if(p -> nxt[i] != NULL)
				{
					Node *q = p -> fail;
					while(q != root && q -> nxt[i] == NULL)
						q = q -> fail;
					if(q -> nxt[i] != NULL && p != q)
						p -> nxt[i] -> fail = q -> nxt[i];
					else
						p -> nxt[i] -> fail = root;
					if(p -> nxt[i] -> fail -> sid != -1)
						p -> nxt[i] -> s_fail = p -> nxt[i] -> fail;
					else
						p -> nxt[i] -> s_fail = p -> nxt[i] -> fail -> s_fail;
					que.push(p -> nxt[i]);
				}
		}
	}

	void go(string &str, int sid)
	{
		Node *p = root;
		for(int i = 0; i < str.size(); i ++)
		{
			int tmp = str[i] - 'a';
			p = p -> nxt[tmp];
			//assert(p -> s_fail != NULL);
			if(p -> s_fail -> sid != -1)
				g_edge[sid][p -> s_fail -> sid] = true;
			if(p -> sid != -1)
				g_edge[sid][p -> sid] = true;
		}
	}
}ac;

string str[M];
/*
void dfs(int cur, int last)
{
	for(int i = 0; i < edges[cur].size(); i ++)
	{
		int v = edges[cur][i];
		if(v == last)
			continue;
		dfs(v, cur);
		vis[cur] |= vis[v];
	}
}
*/
/*
bitset <M> tmp;
bitset <M> gg[M];
void dfs(int cur, int last)
{
	for(int i = 0; i < q_last[cur].size(); i ++)
		tmp[q_last[cur][i]] = 1;
	for(int i = 0; i < q[cur].size(); i ++)
		gg[q[cur][i]] |= tmp;

	for(int i = 0; i < edges[cur].size(); i ++)
	{
		int v = edges[cur][i];
		if(v == last)
			continue;
		dfs(v, cur);
	}

	for(int i = 0; i < q_last[cur].size(); i ++)
		tmp[q_last[cur][i]] = 0;
}
*/
int nxt[M];

int from[M];
int use[M];
bool match(int cur)
{
	for(int i = 0; i < g[cur].size(); i ++)
	{
		int v = g[cur][i];
		if(!use[v])
		{
			use[v] = true;
			if(from[v] == -1 || match(from[v]))
			{
				from[v] = cur;
				return true;
			}
		}
	}
	return false;
}

int hungary(int n)
{
	int ret = 0;
	memset(from, -1, sizeof(from));
	for(int i = 0; i < n; i ++)
	{
		memset(use, 0, sizeof(use));
		if(match(i))
			ret ++;
	}
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	ac.init();
	for(int i = 0; i < n; i ++)
	{
		cin >> str[i];
		ac.insert(str[i], i);
	}
	ac.build();
	//dfs(0, -1);

	/*
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(i != j && vis[last[i]][j] == 1)
			{
				g[i].push_back(j);
				g_edge[i][j] = true;
			}
	*/

	/*
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(i != j && gg[j][i])
			{
				g[i].push_back(j);
				g_edge[i][j] = true;
			}
	*/
	
	for(int i = 0; i < n; i ++)
		ac.go(str[i], i);
	
	for(int k = 0; k < n; k ++)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				g_edge[i][j] = g_edge[i][j] || (g_edge[i][k] && g_edge[k][j]);

	int g_size = 0;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
			if(i != j && g_edge[i][j])
			{
				g[i].push_back(j);
				g_size ++;
			}
	/*
	if(n == 100 && str[0][0] == 'b')
		cout << g_size << '\n';
	*/
	int ans = hungary(n);

	memset(nxt, -1, sizeof(nxt));
	for(int i = 0; i < n; i ++)
		if(from[i] != -1)
			nxt[from[i]] = i;

	vector <int> vec;
	for(int i = 0; i < n; i ++)
		if(from[i] == -1)
			vec.push_back(i);

	while(true)
	{
		bool flag = false;
		for(int i = 0; i < vec.size(); i ++)
		{
			for(int j = 0; j < vec.size(); j ++)
				if(i != j && g_edge[vec[i]][vec[j]])
				{
					vec[i] = nxt[vec[i]];
					assert(vec[i] != -1);
					flag = true;
					break;
				}
			if(flag)
				break;
		}

		if(!flag)
			break;
	}

	//cout << vec.size() << '\n';
	cout << n - ans << '\n';
	for(int i = 0; i < vec.size(); i ++)
		cout << vec[i] + 1 << ' ';
	cout << '\n';

	return 0;
}