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
long long sqr(const long long &v)
{
	return v * v;
}
int main()
{
	std::ios::sync_with_stdio(false);
	long long n, c1, c2;
	cin >> n >> c1 >> c2;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i ++)
		cnt += s[i] == '1';
	long long ans = 1e18;
	for(int i = 1; i <= cnt; i ++)
	{
		int t = (n - i) / i, s = n - i - i * t;
		long long now = c1 * i + sqr(t) * (i - s) * c2 + sqr(t + 1) * s * c2;
		ans = min(ans, now);
	}
	cout << ans << endl;
	
	return 0;
}