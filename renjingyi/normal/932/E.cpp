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
const int maxn = 5005;
const long long mod = 1e9 + 7;
long long power(const long long &a, const long long &k)
{
	long long ans = 1, x = a % mod;
	for(long long i = k; i; i >>= 1, (x *= x) %= mod)
		if(i & 1)
			(ans *= x) %= mod;
	return ans;
}
long long s[maxn][maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	s[1][1] = 1;
	for(int i = 2; i <= k; i ++)
		for(int j = 1; j <= i; j ++)
			s[i][j] = ((j > 1 ? s[i - 1][j - 1] : 0) + (j < i ? j * s[i - 1][j] : 0)) % mod;
	long long tmp1 = n, tmp2 = power(2, n - 1);
	long long ans = 0;
	long long inv2 = power(2, mod - 2);
	for(int i = 1; i <= k; i ++)
	{
		(ans += s[k][i] * tmp1 % mod * tmp2) %= mod;
		(tmp1 *= n - i) %= mod;
		(tmp2 *= inv2) %= mod;
	}
	cout << ans << endl;
	
	return 0;
}