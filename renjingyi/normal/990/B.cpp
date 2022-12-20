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
int a[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	int tmp = 1;
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(; tmp <= n && a[tmp] <= a[i] + k; tmp ++);
		if(a[tmp - 1] <= a[i])
			ans ++;
	}
	cout << ans << endl;
	
	return 0;
}