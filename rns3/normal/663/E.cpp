#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int n, m;
const int N = 21, M = (int) 1e5 + 100;
char a[N][M];
int col[M];

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", a[i] );
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			col[i] |= ( (int) (a[j][i] - '0') << j);
	}
}

const int MAX_HALF = 10;
const int INF = (int) 1e9 + 100;
const int MASK = (1 << (N - MAX_HALF) );
int dp[N + 2][N + 2][MASK * 2];
int cntOnes[1 << MAX_HALF];
int answer = INF;
int ans;

void init()
{
	for (int i = 0; i < (1 << MAX_HALF); i++)
		cntOnes[i] = __builtin_popcount(i);
}

void brute(int t, int pos)
{
//	eprintf("t = %d, pos = %d\n", t, pos);
	if (pos == n)
	{
//		eprintf("\n");
		ans = 0;
		for (int i = 0; i <= n; i++)
		{
			int x = dp[t][i][0];
//			eprintf("i = %d, x = %d\n", i, x);
//			eprintf("add = %d\n", min(i, n - i) * x);
			ans += min(i, n - i) * x;
		}
		answer = min(ans, answer);
		return;
	}
	for (int i = 0; i <= pos; i++)
		for (int mask = 0; mask < (1 << (n - pos) ); mask++)
		{
			dp[t + 1][i + (mask & 1) ][mask >> 1] += dp[t][i][mask];
		}
	brute(t + 1, pos + 1);
	for (int i = 0; i <= pos; i++)
		for (int mask = 0; mask < (1 << (n - pos) ); mask++)
		{
			dp[t + 1][i + (mask & 1) ][mask >> 1] = 0;
		}
	
	for (int i = 0; i <= pos; i++)
		for (int mask = 0; mask < (1 << (n - pos) ); mask++)
		{
			dp[t + 1][i + ( (mask & 1) ^ 1)][mask >> 1] += dp[t][i][mask];
		}
	brute(t + 1, pos + 1);
	for (int i = 0; i <= pos; i++)
		for (int mask = 0; mask < (1 << (n - pos) ); mask++)
		{
			dp[t + 1][i + ( (mask & 1) ^ 1) ][mask >> 1] = 0;
		}
}

void solve()
{
	init();

//	for (int i = 0; i < m; i++)
//		eprintf("%d\n", col[i] );

	int half = min(MAX_HALF, n);
	int mask = (1 << half) - 1;
	for (int i = ( (mask + 1) >> 1); i <= mask; i++)
	{
		for (int j = 0; j < m; j++)
			dp[0][cntOnes[ (col[j] & mask) ^ i] ][col[j] >> half]++;
		
		brute(0, half);

		for (int j = 0; j < m; j++)
		{
			dp[0][cntOnes[ (col[j] & mask) ^ i] ][col[j] >> half] = 0;
		}
	}
	printf("%d\n", answer);
}



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	read();
	solve();



	return 0;
}