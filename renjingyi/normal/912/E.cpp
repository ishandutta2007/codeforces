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
typedef unsigned long long ull;
const ull oo = 1e18;
const ull limit1 = 3e17, limit2 = 5e16;
bool test(const ull &a, const int &p)
{
	if(a > limit1 && p > 4)
		return 0;
	if(a > limit2 && p > 20)
		return 0;
	return a * p <= oo;
}
map<ull, bool> ok1, ok2;
ull calc(const ull &mid)
{
	ull ret = 0;
	map<ull, bool>::iterator pos = ok2.begin();
	ull cnt = 0;
	for(map<ull, bool>::reverse_iterator it = ok1.rbegin(); it != ok1.rend(); it ++)
	{
		for(; pos != ok2.end() && it->first * pos->first <= mid; pos ++)
			cnt ++;
		ret += cnt;
		if(ret > oo)
			break;
	}
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ok1[1] = ok2[1] = 1;
	for(int i = 1; i <= n; i ++)
	{
		int p;
		cin >> p;
		if(ok1.size() <= ok2.size())
		{
			for(map<ull, bool>::iterator it = ok1.begin(); it != ok1.end(); it ++)
				if(test(it->first, p))
					ok1[it->first * p] = 1;
		}
		else
		{
			for(map<ull, bool>::iterator it = ok2.begin(); it != ok2.end(); it ++)
				if(test(it->first, p))
					ok2[it->first * p] = 1;
		}
	}
	ull k;
	cin >> k;
	ull l = 1, r = oo;
	while(l < r)
	{
		ull mid = l + r >> 1;
		if(calc(mid) >= k)
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	
	return 0;
}