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
const int maxn = 1e5 + 5;
int a[maxn];
bool appear[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k, l;
	cin >> n >> k >> l;
	for(int i = 1; i <= n * k; i ++)
		cin >> a[i];
	sort(a + 1, a + n * k + 1);
	int pos = upper_bound(a + 1, a + n * k + 1, a[1] + l) - a - 1;
	if(pos < n)
	{
		cout << 0 << endl;
		return 0;
	}
	int tmp = n * k;
	long long tot = 0;
	bool mark = 0;
	for(int i = 1; i <= n; i ++)
	{
		int now = 1e9;
		if(mark)
		{
			for(int j = 1; j <= k; j ++)
				now = a[tmp --];
		}
		else
		{
			for(int j = 1; j < k; j ++)
			{
				if(appear[tmp])
				{
					tmp --;
					j --;
					continue;
				}
				if(tmp == pos)
				{
					j --;
					mark = 1;
				}
				now = a[tmp --];
			}
			appear[pos] = 1;
			now = min(now, a[pos --]);
		}
		tot += now;
	}
	cout << tot << endl;
	
	return 0;
}