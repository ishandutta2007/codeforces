/*
* Problem: 
* Author: Leo Yu
* Time: 
* State: SOLVED
* Memo: 
*/
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

const int	MOD = 1000000007;
int N, M, K, root, S;
int fail[205], trans[205][25], value[205];
int Q[205];
int a[205], b[205];
LL	f0[205][505][2][2], f1[205][505][2][2];

inline void	update(LL &x, LL y)
{
	x = (x + y) % MOD;
}

inline LL	work(int a[])
{
	int L = a[0];
	memset(f0, 0, sizeof(f0));
	f0[root][0][1][1] = 1;
	for (int i = 1; i <= L; ++ i)
	{
		memset(f1, 0, sizeof(f1));
		for (int x = root; x <= S; ++ x)
		for (int k = 0; k <= K; ++ k)
		for (int z = 0; z < 2; ++ z)
		for (int s = 0; s < 2; ++ s)	if (f0[x][k][z][s])
		{
			for (int c = 0; c < M; ++ c)
			{
				if (c > a[i] && s)	break;
				if (z && !c)	update(f1[root][k][z][s & (c == a[i])], f0[x][k][z][s]);
				elif (k + value[trans[x][c]] <= K)	update(f1[trans[x][c]][k + value[trans[x][c]]][0][s & (c == a[i])], f0[x][k][z][s]);
			}
		}
		memcpy(f0, f1, sizeof(f0));
	}
	LL	ans = 0;
	for (int x = root; x <= S; ++ x)
	for (int k = 0; k <= K; ++ k)
	for (int z = 0; z < 2; ++ z)
	for (int s = 0; s < 2; ++ s)
		update(ans, f0[x][k][z][s]);
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif

	N = read(), M = read(), K = read();
	a[0] = read();
	for (int i = 1; i <= a[0]; ++ i)	a[i] = read();
	
	int n = a[0];
	a[n] --;
	for (int i = n; a[i] < 0; -- i)	a[i] += M, a[i - 1] --;
	while (n && !a[1])
	{
		for (int i = 2; i <= n; ++ i)	a[i - 1] = a[i];
		n --;
	}
	a[0] = n;
	
	b[0] = read();
	for (int i = 1; i <= b[0]; ++ i)	b[i] = read();
	
	root = 1;
	fail[1] = 0, fail[0] = 0;
	for (int i = 0; i < M; ++ i)	trans[0][i] = 1;
	S = 1;
	
	for (int i = 1; i <= N; ++ i)
	{
		int len = read();
		int x = root;
		for (int j = 1; j <= len; ++ j)
		{
			int c = read();
			if (!trans[x][c])
			{
				trans[x][c] = ++ S;
				memset(trans[S], 0, sizeof(trans[S]));
				value[S] = 0;
			}
			x = trans[x][c];
		}
		value[x] += read();
	}
	
	Q[1] = root;
	for (int l = 1, r = 1; l <= r; ++ l)
	{
		int x = Q[l];
		for (int i = 0; i < M; ++ i)
			if (trans[x][i])
			{
				int y = trans[x][i];
				fail[y] = trans[fail[x]][i];
				Q[++ r] = y;
			}
			else	trans[x][i] = trans[fail[x]][i];
		value[x] += value[fail[x]];
	}
	
	cout << (work(b) - work(a) + MOD) % MOD << endl;

	return 0;
}