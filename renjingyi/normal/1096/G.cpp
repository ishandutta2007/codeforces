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
const long long mod = 998244353;
const long long G = 3;
const int maxn = 1e6 + 5;
long long ksm(const long long &a, const long long &k)
{
	long long ans = 1;
	for(long long x = a % mod, asd = k; asd; asd >>= 1, (x *= x) %= mod)
		if(asd & 1)
			(ans *= x) %= mod;
	return ans;
}
int rev[maxn << 1];
long long wn[maxn << 1];
void init(const int &n)
{
	for(int i = 1; i < n; i ++)
		rev[i] = rev[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
	for(int i = 1; (1 << i) <= n; i ++)
		wn[i] = ksm(G, (mod - 1) / (1 << i));
}
void ntt(long long *x, const int &n, const int &mul)
{
	for(int i = 1; i < n; i ++)
		if(i < rev[i])
			swap(x[i], x[rev[i]]);
	int cnt = 0;
	for(int i = 1; i < n; i <<= 1)
	{
		long long now = wn[++ cnt];
		for(int j = 0; j < n; j += i << 1)
		{
			long long w = 1;
			for(int k = 0; k < i; k ++)
			{
				long long tmp1 = x[j + k], tmp2 = w * x[j + i + k] % mod;
				x[j + k] = (tmp1 + tmp2) % mod;
				x[j + i + k] = (tmp1 + mod - tmp2) % mod;
				(w *= now) %= mod;
			}
		}
	}
	if(mul < 0)
		for(int i = 1; i < (n >> 1); i ++)
			swap(x[i], x[n - i]);
}
long long a[maxn << 1];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i ++)
	{
		int x;
		cin >> x;
		a[x] = 1;
	}
	int len;
	for(len = 1; len < 9 * n / 2 + 1; len <<= 1);
	init(len);
	ntt(a, len, 1);
	for(int i = 0; i < len; i ++)
		a[i] = ksm(a[i], n >> 1);
	ntt(a, len, -1);
	long long invlen = ksm(len, mod - 2);
	for(int i = 0; i < len; i ++)
		(a[i] *= invlen) %= mod;
	long long ans = 0;
	for(int i = 0; i < 9 * n / 2 + 1; i ++)
		(ans += a[i] * a[i]) %= mod;
	cout << ans << endl;
	
	return 0;
}