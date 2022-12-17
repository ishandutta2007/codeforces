#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 1001000;
const int mod = 1e9 + 7;
long long power(long long x, long long k)
{
	long long ans = 1;
	while(k)
	{
		if(k & 1)
			(ans *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return ans;
}
int n;
long long fac[maxn], inv[maxn];
void init()
{
	fac[0] = fac[1] = 1;
	for(int i = 2; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	inv[n] = power(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i --)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long C(int x, int y)
{
	if(x < y || y < 0)
		return 0;
	return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int v[maxn], rk[maxn] = {0};
long long get(int l, int r, int mx)
{
	int j = mx + 1;
	while(!rk[j])
		j ++;
	//cout << l << " " << r << " " << mx << " " << j << " " << rk[j] << endl;
	if(j == n + 1)
		return C(n - mx, l - 1);
	if(l <= rk[j] && rk[j] <= r)
		return 0;
	//cout << l << " " << r << " " << mx << " " << j << " " << rk[j] << endl;
	if(rk[j] < l)
	{
		int diff = (j - mx) - (l - rk[j]);
		if(diff < 0)
			return 0;
		return C(j - mx - 1, l - rk[j] - 1) * get(rk[j], r + diff, j) % mod;
	}
	else
	{
		int diff = (j - mx) - (rk[j] - r);
		if(diff < 0)
			return 0;
		return C(j - mx - 1, rk[j] - r - 1) * get(l - diff, rk[j], j) % mod;
	}
}
int main()
{
//	freopen("cinema.in", "r", stdin);
//	freopen("cinema.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	cin >> n;
	init();
	for(int i = 1; i <= n; i ++)
	{
		cin >> v[i];
		rk[v[i]] = i;
	}
	rk[n + 1] = n + 1;
	/*
	for(int i = 1; i <= n; i ++)
		cout << rk[i] << " ";
	cout << endl;
	*/
	if(rk[1])
		cout << get(rk[1], rk[1], 1) << endl;
	else
	{
		long long ans = 0;
		int j = 2;
		while(!rk[j])
			j ++;
		if(j == n + 1)
		{
			cout << power(2, n - 1) << endl;
			return 0;
		}
		if(rk[j] > 1)
			ans += get(rk[j] - 1, rk[j] - 1, 1);
		//cout << ans << endl;
		if(rk[j] < n)
			(ans += get(rk[j] + 1, rk[j] + 1, 1)) %= mod;
		cout << ans * power(2, j - 2) % mod << endl;
		
	}
	return 0;
}
/*
5
0 2 0 0 5 
*/