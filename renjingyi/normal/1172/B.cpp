#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 998244353;
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
long long dp[maxn];
long long fac[maxn];
int n;
void work(const int &p, const int &fa)
{
	int t = 0;
	dp[p] = 1;
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa)
		{
			work(edges[e].to, p);
			t ++;
			(dp[p] *= dp[edges[e].to]) %= mod;
		}
	(dp[p] *= p == 1 ? fac[t] * n % mod : fac[t + 1]) %= mod;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		cin >> a >> b;
		adde(a, b);
		adde(b, a);
	}
	work(1, 0);
	cout << dp[1] << endl;
	
	return 0;
}