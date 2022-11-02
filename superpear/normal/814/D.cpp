/*
	Codeforces Contest 418 Div 2, Problem D
	2017/6/11
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define m_p make_pair
#define l_b lower_bound
#define p_b push_back
#define w1 first
#define w2 second
#define maxlongint 2147483647
#define biglongint 2139062143

const int maxn = 1005;
const double PI = atan(1) * 4;

int N;
int x[maxn], y[maxn], r[maxn];
vector<int> F[maxn]; // tree structure
bool isroot[maxn];
LL dp[maxn][2][2]; // the DP array of area, not including PI
PIII sc[maxn];

void dfs(int s)
{
	LL area = (LL)r[s] * r[s];
	if (F[s].size() == 0) // leaf
	{
		dp[s][0][0] = -area;
		dp[s][0][1] = dp[s][1][0] = dp[s][1][1] = area;
		return;
	}
	for (int i = 0; i < F[s].size(); i++) dfs(F[s][i]);
	if (s == 0)
	{
		for (int i = 0; i < F[s].size(); i++)
			dp[s][0][0] += dp[F[s][i]][1][1];
		return;
	}
	for (int x = 0; x <= 1; x++)
		for (int y = 0; y <= 1; y++)
		{
			LL first = 0, second = 0; // gain if we put s into first tree or second tree
			if (x == 0) first = -area; else first = area;
			if (y == 0) second = -area; else second = area;
			for (int i = 0; i < F[s].size(); i++)
				first += dp[F[s][i]][1 - x][y],
				second += dp[F[s][i]][x][1 - y];
			dp[s][x][y] = max(first, second);
		}
}

int main()
{
	//freopen("D.in", "r", stdin);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d %d %d", &x[i], &y[i], &r[i]), isroot[i] = true, sc[i] = m_p(r[i], m_p(x[i], y[i]));
	sort(sc + 1, sc + N + 1);
	for (int i = 1; i <= N; i++) x[i] = sc[i].w2.w1, y[i] = sc[i].w2.w2, r[i] = sc[i].w1;
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
		{
			// check whether circle j contains circle j
			LL distsqr = (LL)(x[i] - x[j]) * (x[i] - x[j]) + (LL)(y[i] - y[j]) * (y[i] - y[j]);
			if (distsqr < (LL)(r[i] + r[j]) * (r[i] + r[j])) 
			{
				// j is father of i
				isroot[i] = false;
				F[j].p_b(i);
				break;
			}
		}
	// 0 is the root of everything
	for (int i = 1; i <= N; i++) if (isroot[i]) F[0].p_b(i);

	// dp[u][x][y]: the maximum gain of u's subtree, x/y means the parity of length of path between root and u, in each tree
	// parity excluding u itself
	dfs(0);
	printf("%.10lf\n", dp[0][0][0] * PI);

	return 0;
}