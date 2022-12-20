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
long long a[maxn], h[maxn];
long long tmp[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		h[i] = h[i - 1] + a[i];
	}
	h[n + 1] = 1e16;
	for(int i = 1; i <= n; i ++)
		tmp[i] = a[i];
	long long now = 0;
	for(int i = 1; i <= q; i ++)
	{
		long long k;
		cin >> k;
		int l = 1, r = n + 1;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(h[mid] > k + now)
				r = mid;
			else
				l = mid + 1;
		}
		if(l > n)
		{
			cout << n << endl;
			now = 0;
		}
		else
		{
			cout << n - l + 1 << endl;
			now += k;
		}
	}
	
	return 0;
}