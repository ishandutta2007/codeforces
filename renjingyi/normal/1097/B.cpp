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
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	bool ok = 0;
	for(int i = 0; i < (1 << n); i ++)
	{
		int now = 0;
		for(int j = 0; j < n; j ++)
			now += ((i >> j) & 1 ? 1 : -1) * a[j];
		if(now % 360 == 0)
			ok = 1;
	}
	cout << (ok ? "YES" : "NO") << endl;
	
	return 0;
}