#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const int AC_size = 26;
const int oo = 1e9;
typedef struct Node
{
	int p;
	Node *next[AC_size], *fail;
	Node() : p(0), next(), fail(0) {}
}*pnode;
Node node[maxn];
int cnt = 0;
pnode nNode(const pnode &root = 0)
{
	cnt ++;
	node[cnt].p = cnt;
	node[cnt].fail = root;
	return &node[cnt];
}
pnode root = 0;
int insert(const string &s)
{
	pnode now = root;
	for(int i = 0; i < s.size(); i ++)
	{
		int x = s[i] - 'a';
		if(!now->next[x])
			now->next[x] = nNode(root);
		now = now->next[x];
	}
	return now->p;
}
int add[maxn];
void set_fail()
{
	static queue<pnode> q;
	q.push(root);
	while(!q.empty())
	{
		pnode now = q.front();
		q.pop();
		if(now != root)
			add[now->p] += add[now->fail->p];
		for(int i = 0; i < AC_size; i ++)
		{
			if(now->next[i])
			{
				now->next[i]->fail = now == root ? root : now->fail->next[i];
				q.push(now->next[i]);
			}
			else
				now->next[i] = now == root ? root : now->fail->next[i];
		}
	}
}
int dp[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	string c, s, t;
	cin >> c >> s >> t;
	root = nNode();
	add[insert(s)] ++;
	add[insert(t)] --;
	set_fail();
	int n = c.size();
	for(int i = 0; i <= n; i ++)
		for(int j = 1; j <= cnt; j ++)
			dp[i][j] = -oo;
	dp[0][1] = 0;
	for(int i = 0; i < n; i ++)
		for(int j = 1; j <= cnt; j ++)
		{
			if(c[i] == '*')
			{
				for(int k = 0; k < AC_size; k ++)
				{
					int to = node[j].next[k]->p;
					dp[i + 1][to] = max(dp[i + 1][to], dp[i][j] + add[to]);
				}
			}
			else
			{
				int to = node[j].next[c[i] - 'a']->p;
				dp[i + 1][to] = max(dp[i + 1][to], dp[i][j] + add[to]);
			}
		}
	int ans = -oo;
	for(int i = 1; i <= cnt; i ++)
		ans = max(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}