#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 301111;
const int M = 16 * N;

struct Node
{
	Node* nxt[26];
	Node() { memset(nxt, 0, sizeof(nxt)); }
}pool[M];
int pid = 0;
Node* root[N];

int c[N];
int cnt[N];
string str;
vector <int> edges[N];

void merge(Node *p, Node *q, int &cnt)
{
	for(int i = 0; i < 26; i ++)
		if(q -> nxt[i] != NULL)
		{
			if(p -> nxt[i] == NULL)
			{
				cnt ++;
				p -> nxt[i] = &pool[pid ++];
			}
			merge(p -> nxt[i], q -> nxt[i], cnt);
		}
}
void dfs(int cur, int last = -1)
{
	cnt[cur] = 0;
	root[cur] = &pool[pid ++];
	for(auto &v : edges[cur])
		if(v != last)
		{
			dfs(v, cur);
			if(cnt[cur] == 0)
			{
				root[cur] = root[v];
				cnt[cur] = cnt[v];
			}
			else
			{
				if(cnt[v] > cnt[cur])
				{
					swap(root[v], root[cur]);
					cnt[cur] = cnt[v];
				}
				merge(root[cur], root[v], cnt[cur]);
			}
		}
	cnt[cur] ++;
	Node *p = &pool[pid ++];
	p -> nxt[str[cur - 1] - 'a'] = root[cur];
	root[cur] = p;
}

int d(Node *p)
{
	int ret = 1;
	for(int i = 0; i < 26; i ++)
		if(p -> nxt[i])
			ret += d(p -> nxt[i]);
	return ret;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	cin >> str;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(1);
	/*
	for(int i = 1; i <= n; i ++)
		cout << i << ' ' << cnt[i] << '\n';
		*/	
	int ans = 0;
	int ans_cnt = 1;
	for(int i = 1; i <= n; i ++)
		if(cnt[i] + c[i] > ans)
		{
			ans = cnt[i] + c[i];
			ans_cnt = 1;
		}
		else if(cnt[i] + c[i] == ans)
			ans_cnt ++;
	cout << ans << '\n';
	cout << ans_cnt << '\n';
	return 0;
}