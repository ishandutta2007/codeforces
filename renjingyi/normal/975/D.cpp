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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<long long, long long> pp;
map<long long, int> cnt1;
map<pp, int> cnt2;
long long calc(const long long &c)
{
	return c * (c - 1) / 2;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	long long a, b;
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i ++)
	{
		long long x, vx, vy;
		cin >> x >> vx >> vy;
		cnt1[vy - a * vx] ++;
		cnt2[mp(vx, vy)] ++;
	}
	long long ans = 0;
	for(map<long long, int>::iterator it = cnt1.begin(); it != cnt1.end(); it ++)
		ans += calc(it->second);
	for(map<pp, int>::iterator it = cnt2.begin(); it != cnt2.end(); it ++)
		ans -= calc(it->second);
	cout << ans * 2 << endl;
	
	return 0;
}