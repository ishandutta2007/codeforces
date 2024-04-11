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
const int maxn = 2e5 + 5;
const long long mod = 998244353;
long long power(const long long &a, const long long &k)
{
	long long ans = 1, x = a % mod;
	for(long long i = k; i; i >>= 1, (x *= x) %= mod)
		if(i & 1)
			(ans *= x) %= mod;
	return ans;
}
long long a[maxn];
long long f0[maxn], f1[maxn], f2[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	long long n, k;
	cin >> n >> k;
	f0[0] = 1;
	f1[0] = 0;
	f2[0] = k * (k - 1) % mod;
	for(int i = 1; i <= n; i ++)
	{
		f0[i] = f0[i - 1] * (k - 1) % mod;
		f1[i] = f2[i - 1];
		f2[i] = (f1[i - 1] * (k - 1) + f2[i - 1] * (k - 2)) % mod;
	}
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	int last = 0, cnt = 0;
	long long ans = 1, mul1 = power(k, mod - 2), mul2 = power(k * (k - 1), mod - 2);
	for(int i = 0; i <= n; i ++)
	{
		(f1[i] *= mul1) %= mod;
		(f2[i] *= mul2) %= mod;
	}
	for(int i = 1; i <= n; i += 2)
	{
		if(a[i] > -1)
		{
			if(last == 0)
				(ans *= f0[cnt]) %= mod;
			else if(last == a[i])
				(ans *= f1[cnt]) %= mod;
			else
				(ans *= f2[cnt]) %= mod;
			last = a[i];
			cnt = 0;
		}
		else
			cnt ++;
	}
	if(last == 0)
		(ans *= cnt ? k * f0[cnt - 1] % mod : 1) %= mod;
	else
		(ans *= f0[cnt]) %= mod;
	last = cnt = 0;
	for(int i = 2; i <= n; i += 2)
	{
		if(a[i] > -1)
		{
			if(last == 0)
				(ans *= f0[cnt]) %= mod;
			else if(last == a[i])
				(ans *= f1[cnt]) %= mod;
			else
				(ans *= f2[cnt]) %= mod;
			last = a[i];
			cnt = 0;
		}
		else
			cnt ++;
	}
	if(last == 0)
		(ans *= cnt ? k * f0[cnt - 1] % mod : 1) %= mod;
	else
		(ans *= f0[cnt]) %= mod;
	cout << ans << endl;
	
	return 0;
}