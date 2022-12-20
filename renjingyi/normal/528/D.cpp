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
typedef vector<long long> Poly;
const int maxn = 1 << 20;
const long long mod = 998244353;
const long long G = 3;
long long power(const long long &a, const long long &k)
{
	long long ans = 1, x = a % mod;
	for(long long i = k; i; i >>= 1, (x *= x) %= mod)
		if(i & 1)
			(ans *= x) %= mod;
	return ans;
}
int rev[maxn];
long long wn[maxn];
void init(const int &n)
{
	for(int i = 1; i < n; i ++)
		rev[i] = rev[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
	for(int i = 1; (1 << i) <= n; i ++)
		wn[i] = power(G, mod - 1 >> i);
}
void ntt(Poly &x, const int &n, const int &mul)
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
	{
		long long inv = power(n, mod - 2);
		for(int i = 0; i < n; i ++)
			(x[i] *= inv) %= mod;
		for(int i = 1; i < (n >> 1); i ++)
			swap(x[i], x[n - i]);
	}
}
Poly operator*(Poly a, Poly b)
{
	int n = a.size(), m = b.size();
	int len;
	for(len = 1; len < n + m - 1; len <<= 1);
	init(len);
	a.resize(len);
	b.resize(len);
	ntt(a, len, 1);
	ntt(b, len, 1);
	for(int i = 0; i < len; i ++)
		(a[i] *= b[i]) %= mod;
	ntt(a, len, -1);
	a.resize(n + m - 1);
	return a;
}
Poly a, b;
int q[maxn];
long long ans[maxn][4];
const char c[] = {'A', 'T', 'G', 'C'};
int n, m, k;
string s, t;
void match(const int &x)
{
	q[0] = 0;
	for(int i = 1; i <= n; i ++)
		q[i] = q[i - 1] + (s[i - 1] == c[x]);
	a.resize(n);
	b.resize(m);
	for(int i = 1; i <= n; i ++)
		a[i - 1] = q[min(i + k, n)] - q[max(i - k - 1, 0)] > 0;
	for(int i = 0; i < m; i ++)
		b[i] = t[i] == c[x];
	reverse(a.begin(), a.end());
	a = a * b;
	for(int i = 0; i < n; i ++)
		ans[i][x] = a[n - 1 - i];
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	cin >> s >> t;
	for(int i = 0; i < 4; i ++)
		match(i);
	int ret = 0;
	for(int i = 0; i < n; i ++)
	{
		int tot = 0;
		for(int j = 0; j < 4; j ++)
			tot += ans[i][j];
		ret += tot == m;
	}
	cout << ret << endl;
	
	return 0;
}