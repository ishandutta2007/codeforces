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
pair<long long, long long> get(const long long &x1, const long long &y1, const long long &x2, const long long &y2)
{
	if(x1 > x2 || y1 > y2)
		return make_pair(0, 0);
	long long s = (y2 - y1 + 1) / 2 * (x2 - x1 + 1);
	if(y1 % 2 == y2 % 2)
	{
		s += (x2 - x1 + 1) / 2;
		if((x2 - x1 + 1) % 2 == 1)
			if(y1 % 2 == x1 % 2)
				s ++;
	}
	return make_pair(s, (x2 - x1 + 1) * (y2 - y1 + 1) - s);
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		long long n, m;
		cin >> n >> m;
		long long x1, y1, x2, y2;
		long long x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		long long xx1 = max(x1, x3), yy1 = max(y1, y3), xx2 = min(x2, x4), yy2 = min(y2, y4);
		pair<long long, long long> s1 = get(1, 1, m, n), s2 = get(x1, y1, x2, y2), s3 = get(x3, y3, x4, y4), s4 = get(xx1, yy1, xx2, yy2);
		cout << s1.first + s2.second - s3.first - s4.second << " " << s1.second - s2.second + s3.first + s4.second << endl;
	}
	
	return 0;
}