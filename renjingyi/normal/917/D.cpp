#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 105;
const long long mod = 1e9 + 7;
long long power(const long long &a, const long long &k)
{
	long long ans = 1, x = a % mod;
	for(long long i = k; i; i >>= 1, (x *= x) %= mod)
		if(i & 1)
			(ans *= x) %= mod;
	return ans;
}
struct Edge
{
	int to, next;
}edges[maxn << 1];
int te = 1;
int points[maxn];
void adde(const int &a, const int &b)
{
	te ++;
	edges[te].to = b;
	edges[te].next = points[a];
	points[a] = te;
}
long long dp[maxn][maxn][maxn];
long long tmp[maxn][maxn];
int t[maxn];
int n;
void work(const int &p, const int &fa)
{
	dp[p][0][1] = 1;
	t[p] = 1;
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa)
		{
			int to = edges[e].to;
			work(to, p);
			for(int i = 0; i <= t[p] + t[to]; i ++)
				for(int j = 0; j <= t[p] + t[to]; j ++)
					tmp[i][j] = 0;
			for(int a = 0; a <= t[p]; a ++)
				for(int b = 0; b <= t[p] - a; b ++)
					if(dp[p][a][b])
						for(int c = 0; c <= t[to]; c ++)
							for(int d = 0; d <= t[to] - c; d ++)
								if(dp[to][c][d])
								{
									(tmp[a + c][b + d] += dp[p][a][b] * dp[to][c][d]) %= mod;
									(tmp[a + c + d - 1][b] += dp[p][a][b] * dp[to][c][d] % mod * n * d) %= mod;
								}
			t[p] += t[to];
			for(int i = 0; i <= t[p]; i ++)
				for(int j = 0; j <= t[p]; j ++)
					dp[p][i][j] = tmp[i][j];
		}
}
long long pre[maxn];
long long fac[maxn], invfac[maxn];
long long calc(const int &n, const int &k)
{
	if(n < k || k < 0)
		return 0;
	return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	invfac[n] = power(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i --)
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		cin >> a >> b;
		adde(a, b);
		adde(b, a);
	}
	work(1, 0);
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j <= n; j ++)
			if(dp[1][i][j])
				(pre[i + j - 1] += dp[1][i][j] * n * j) %= mod;
	long long mul = power(n * n, mod - 2);
	for(int i = 0; i < n; i ++)
		(pre[i] *= mul) %= mod;
	for(int i = n - 1; i >= 0; i --)
		for(int j = i + 1; j < n; j ++)
			(pre[i] += mod - pre[j] * calc(j, i) % mod) %= mod;
	for(int i = 0; i < n; i ++)
		cout << pre[i] << " ";
	cout << endl;
	
	return 0;
}