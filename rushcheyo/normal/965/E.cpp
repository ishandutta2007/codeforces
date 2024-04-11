#include <cstdio>
#include <queue>

int n, ch[100001][26], tot, dep[100001];
char s[100001];
bool ed[100001];
std::priority_queue<int> *q[100001];

void dfs(int u)
{
	int son = 0;
	for (int i = 0; i < 26; i++)
		if (ch[u][i])
		{
			dep[ch[u][i]] = dep[u] + 1;
			dfs(ch[u][i]);
			if (!son || q[ch[u][i]]->size() > q[son]->size())
				son = ch[u][i];
		}
	if (son)
	{
		q[u] = q[son];
		for (int i = 0; i < 26; i++)
			if (ch[u][i] && ch[u][i] != son)
				while (!q[ch[u][i]]->empty())
					q[u]->push(q[ch[u][i]]->top()), q[ch[u][i]]->pop();
	}
	else
		q[u] = new std::priority_queue<int>;
	if (u)
	{
		q[u]->push(dep[u]);
		if (!ed[u])
			q[u]->pop();
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		int u = 0;
		for (int i = 0; s[i]; i++)
		{
			if (!ch[u][s[i] - 'a'])
				ch[u][s[i] - 'a'] = ++tot;
			u = ch[u][s[i] - 'a'];
		}
		ed[u] = true;
	}
	dfs(0);
	int ans = 0;
	while (!q[0]->empty())
		ans += q[0]->top(), q[0]->pop();
	printf("%d\n", ans);
	return 0;
}