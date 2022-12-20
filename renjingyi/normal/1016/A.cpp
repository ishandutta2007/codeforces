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
	int n, m;
	cin >> n >> m;
	int now = 0;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		int cnt = 0;
		if(x >= m - now)
		{
			x -= m - now;
			cnt ++;
			cnt += x / m;
			x %= m;
			now = x;
		}
		else
			now += x;
		cout << cnt << " ";
	}
	cout << endl;
	
	return 0;
}