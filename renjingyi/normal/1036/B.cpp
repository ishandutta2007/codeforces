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
	int q;
	cin >> q;
	for(int i = 1; i <= q; i ++)
	{
		long long n, m, k;
		cin >> n >> m >> k;
		if(n < m)
			swap(n, m);
		if(k < max(n, m))
			cout << -1 << endl;
		else
		{
			if((~n & 1) && (~m & 1))
			{
				if(k & 1)
					k -= 2;
				cout << k << endl;
			}
			else if((n & 1) && (m & 1))
			{
				if(~k & 1)
					k -= 2;
				cout << k << endl;
			}
			else
				cout << k - 1 << endl;
		}
	}
	
	return 0;
}