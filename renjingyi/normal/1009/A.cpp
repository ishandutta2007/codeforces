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
const int maxn = 1005;
int a[1005], c[1005];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	for(int i = 1; i <= m; i ++)
		cin >> a[i];
	int cnt = 0;
	int pos = 1;
	for(int i = 1; i <= n; i ++)
		if(pos <= m && a[pos] >= c[i])
		{
			cnt ++;
			pos ++;
		}
	cout << cnt << endl;
	
	return 0;
}