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
int a[105];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	n >>= 1;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 1e9;
	int now = 0;
	for(int i = 1; i <= n; i ++)
		now += abs(a[i] - (2 * i - 1));
	ans = min(ans, now);
	now = 0;
	for(int i = 1; i <= n; i ++)
		now += abs(a[i] - 2 * i);
	ans = min(ans, now);
	cout << ans << endl;
	
	return 0;
}