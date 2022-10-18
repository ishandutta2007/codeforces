#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include <string.h>

using namespace std;


typedef long long LL;

int main()
{
	LL lo, hi;
	cin >> lo >> hi;

	set<LL> s;
	for (int len = 1; len <= 60; len++)
	{
		LL m = (1LL<<len)-1;
		for (int b = 0; b < len-1; b++)
		{
			LL x = m & ~(1LL<<b);
			s.insert(x);
		}
	}
	int num = 0;
	for (auto x : s)
	{
		if (lo <= x && x <= hi)
			num++;
	}
	cout << num << endl;
	exit(0);
}