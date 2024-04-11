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
const int maxn = 1e6 + 5;
long long ksm(const long long &a, const long long &k)
{
	long long ans = 1;
	for(long long x = a % mod, asd = k; asd; asd >>= 1, (x *= x) %= mod)
		if(asd & 1)
			(ans *= x) %= mod;
	return ans;
}
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
	int n;
	cin >> n;
	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	invfac[n] = ksm(fac[n], mod - 2);
	for(int i = n - 1; i >= 0; i --)
		invfac[i] = invfac[i + 1] * (i + 1) % mod;
	long long ans = n * fac[n] % mod;
	for(int i = 1; i < n; i ++)
		(ans += mod - calc(n, i) * fac[n - i] % mod) %= mod;
	cout << ans << endl;
	
	return 0;
}