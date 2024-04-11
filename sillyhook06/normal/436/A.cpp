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

int N, X;
vector< pair<int, int> >	a[2];
bool	visit[2][2005];

inline int work(vector< pair<int, int> > a[], int X)
{
	memset(visit, 0, sizeof(visit));
	for (int i = 0; ; ++ i)
	{
		int mass = 0, id = -1;
		for (int j = 0; j < a[i & 1].size(); ++ j)	if (a[i & 1][j].first <= X && !visit[i & 1][j])
		{
			if (a[i & 1][j].second > mass)
			{
				mass = a[i & 1][j].second;
				id = j;
			}
		}
		if (id == -1)	return i;
		X += mass;
		visit[i & 1][id] = 1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), X = read();
	for (int i = 1; i <= N; ++ i)
	{
		int t = read(), h = read(), m = read();
		a[t].push_back(make_pair(h, m));
	}
	int ans = work(a, X);
	swap(a[0], a[1]);
	ans = max(ans, work(a, X));
	cout << ans << endl;

	return 0;
}