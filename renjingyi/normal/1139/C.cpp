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
const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
long long power(const long long &a, const long long &k)
{
	long long ans = 1, x = a % mod;
	for(long long i = k; i; i >>= 1, (x *= x) %= mod)
		if(i & 1)
			(ans *= x) %= mod;
	return ans;
}
int par[maxn], t[maxn];
int getp(const int &x)
{
	if(par[x] == x)
		return x;
	return par[x] = getp(par[x]);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
	{
		par[i] = i;
		t[i] = 1;
	}
	for(int i = 1; i < n; i ++)
	{
		int u, v, x;
		cin >> u >> v >> x;
		if(x == 0)
		{
			if(getp(u) == getp(v))
				continue;
			t[par[v]] += t[par[u]];
			par[par[u]] = par[v];
		}
	}
	long long ans = power(n, k);
	for(int i = 1; i <= n; i ++)
		if(getp(i) == i)
			(ans += mod - power(t[i], k)) %= mod;
	cout << ans << endl;
	
	return 0;
}