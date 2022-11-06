#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if

const int INF = 1 << 30;

const int S = 20;
int N, M, K, L;
int ans[S + 5][70005];
map<string, int>	Map;
vector<int>	point[70005];
vector<int>	have[50005];
int	len[70005];
int p[70005], id[70005];
int res[100005];
int prev[70005];
vector< pair<int, int> > query[70005];

char s[50005];

bool	cmp(const int x, const int y)
{
	return point[x].size() > point[y].size();
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	scanf("%s", s + 1);
	N = strlen(s + 1);
	for (int i = 1; i <= N; ++ i)
	{
		string tmp = "";
		for (int j = i; j < i + 4 && j <= N; ++ j)
		{
			tmp += s[j];
			if (!Map.count(tmp))	Map[tmp] = ++ M, len[M] = tmp.length();
			int x = Map[tmp];
			point[x].push_back(i);
			have[i].push_back(x);
		}
	}
	for (int i = 1; i <= M; ++ i)	p[i] = i;
	sort(p + 1, p + M + 1, cmp);
	for (int i = 1; i <= M; ++ i)	id[p[i]] = i;
	memset(ans, 66, sizeof(ans));
	int K = min(M, S);
	for (int t = 1; t <= K; ++ t)
	{
		int x = p[t];
		int last = 0;
		for (int i = 1; i <= N; ++ i)
		{
			for (int j = 0; j < have[i].size(); ++ j)
			{
				int y = have[i][j];
				if (y == x)	last = i;
			}
			for (int j = 0; j < have[i].size(); ++ j)
			{
				int y = have[i][j];
				if (last)	ans[t][y] = min(ans[t][y], max(last + len[x], i + len[y]) - last);
			}
		}
		last = 0;
		for (int i = N; i; -- i)
		{
			for (int j = 0; j < have[i].size(); ++ j)
			{
				int y = have[i][j];
				if (y == x)	last = i;
			}
			for (int j = 0; j < have[i].size(); ++ j)
			{
				int y = have[i][j];
				if (last)	ans[t][y] = min(ans[t][y], max(last + len[x], i + len[y]) - i);
			}
		}
	}
	int Q = read();
	for (int i = 1; i <= Q; ++ i)
	{
		string tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		int x = -1, y = -1;
		if (Map.count(tmp1))	x = Map[tmp1];
		if (Map.count(tmp2))	y = Map[tmp2];
		if (x == -1 || y == -1)
			res[i] = -1;
		elif (id[x] <= K)
			res[i] = ans[id[x]][y];
		elif (id[y] <= K)
			res[i] = ans[id[y]][x];
		else
			query[x].push_back(make_pair(y, i)), query[y].push_back(make_pair(x, i)), res[i] = INF;
	}
	for (int i = 1; i <= N; ++ i)
	{
		for (int j = 0; j < have[i].size(); ++ j)
		{
			int x = have[i][j];
			prev[x] = i;
		}
		for (int j = 0; j < have[i].size(); ++ j)
		{
			int x = have[i][j];
			if (query[x].size())
			{
				for (int k = 0; k < query[x].size(); ++ k)
				{
					int y = query[x][k].first;
					if (prev[y])
					{
						res[query[x][k].second] = min(res[query[x][k].second], max(len[y] + prev[y], len[x] + i) - prev[y]);
					}
				}
			}
		}
	}
	for (int i = 1; i <= Q; ++ i)
	{
		if (res[i] > INF)	res[i] = -1;
		printf("%d\n", res[i]);
	}

	return 0;
}