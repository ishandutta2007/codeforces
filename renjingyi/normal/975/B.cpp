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
int a[20];
int tmp[20];
int main()
{
	std::ios::sync_with_stdio(false);
	for(int i = 0; i < 14; i ++)
		cin >> a[i];
	long long ans = 0;
	for(int i = 0; i < 14; i ++)
	{
		for(int j = 0; j < 14; j ++)
			tmp[j] = a[j];
		int now = tmp[i];
		int x = now / 14, y = now % 14;
		tmp[i] = 0;
		for(int j = (i + 1) % 14, cnt = 0; cnt < 14; j = (j + 1) % 14, cnt ++)
		{
			tmp[j] += x;
			if(y)
			{
				tmp[j] ++;
				y --;
			}
		}
		long long tot = 0;
		for(int j = 0; j < 14; j ++)
			if(~tmp[j] & 1)
				tot += tmp[j];
		ans = max(ans, tot);
	}
	cout << ans << endl;
	
	return 0;
}