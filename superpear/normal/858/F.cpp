#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<double, double> PDD;

const int maxlongint = 2147483647;
const int biglongint = 2139062143;

#define LL long long
#define ULL unsigned long long
#define w1 first
#define w2 second
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

const int maxn = 500005;
int N, M;
int x[maxn], y[maxn], depth[maxn], use[maxn], father[maxn];
vector<PIII> ans;
PII ls[maxn];
vector<PII> f[maxn];

void dfs(int s, int fa, int cur_depth)
{
	father[s] = fa;
	depth[s] = cur_depth;
	for (int i = 0; i < f[s].size(); i++)
		if (depth[f[s][i].w1] == 0)
			dfs(f[s][i].w1, s, cur_depth + 1);
}

PIII travel(int edge1, int edge2)
{
	int x1 = x[edge1], y1 = y[edge1];
	int x2 = x[edge2], y2 = y[edge2];
	if (x1 == x2)
		return m_p(y1, m_p(x2, y2));
	if (x1 == y2)
		return m_p(y1, m_p(y2, x2));
	if (y1 == x2)
		return m_p(x1, m_p(x2, y2));
	if (y1 == y2)
		return m_p(x1, m_p(y2, x2));
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
		f[x[i]].p_b(m_p(y[i], i));
		f[y[i]].p_b(m_p(x[i], i));
	}
	memset(depth, 0, sizeof(depth));
	memset(use, 0, sizeof(use)); // edge used
	memset(father, 0, sizeof(father));

	ans.clear();
	for (int i = 1; i <= N; i++)
		if (depth[i] == 0)
			dfs(i, 0, 1);
	for (int i = 1; i <= N; i++)
		ls[i] = m_p(-depth[i], i);
	sort(ls + 1, ls + N + 1);
	for (int ic = 1; ic <= N; ic++)
	{
		int s = ls[ic].w2;
		int tmp = -1;
		for (int i = 0; i < f[s].size(); i++)
		{
			int sc = f[s][i].w1;
			if (use[f[s][i].w2] == 1) continue;
			if (depth[sc] < depth[s]) continue;
			use[f[s][i].w2] = 1;
			if (tmp == -1)
				tmp = f[s][i].w2;
			else
			{
				ans.p_b(travel(tmp, f[s][i].w2));
				tmp = -1;
			}
		}
		if (tmp != -1)
		{
			for (int i = 0; i < f[s].size(); i++)
				if (f[s][i].w1 == father[s])
				{
					use[f[s][i].w2] = 1;
					ans.p_b(travel(tmp, f[s][i].w2));
					break;
				}
		}
	}

	printf("%lu\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d %d\n", ans[i].w1, ans[i].w2.w1, ans[i].w2.w2);
	return 0;
}