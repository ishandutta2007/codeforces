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
long long gcd(const long long &a, const long long &b)
{
	if(!b)
		return a;
	return gcd(b, a % b);
}
int main()
{
	std::ios::sync_with_stdio(false);
	long long n, k, a, b;
	cin >> n >> k >> a >> b;
	long long tot = n * k;
	long long mx = 1, mn = tot;
	for(long long i = 0; i < n; i ++)
	{
		long long now = gcd(tot, abs(i * k + b - a));
		mx = max(mx, tot / now);
		mn = min(mn, tot / now);
		now = gcd(tot, abs((i + 1) * k - b - a));
		mx = max(mx, tot / now);
		mn = min(mn, tot / now);
	}
	cout << mn << " " << mx << endl;
	
	return 0;
}