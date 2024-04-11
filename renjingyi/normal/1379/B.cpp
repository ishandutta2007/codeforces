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
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		long long l, r, m;
		cin >> l >> r >> m;
		bool get = 0;
		for(long long i = l; i <= r; i ++)
		{
			long long n = m / i;
			if(n && m - n * i <= r - l)
			{
				cout << i << " " << m - n * i + l << " " << l << endl;
				get = 1;
				break;
			}
			if((n + 1) * i - m <= r - l)
			{
				cout << i << " " << l << " " << (n + 1) * i - m + l << endl;
				get = 1;
				break;
			}
		}
	}
	
	return 0;
}