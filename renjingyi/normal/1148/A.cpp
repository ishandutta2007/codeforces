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
long long a, b, c;
long long calc()
{
	return 2 * c + (a <= b ? 2 * a : 2 * b + 1);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	long long ans = calc();
	if(b > 0)
	{
		long long now = 1;
		b --;
		ans = max(ans, calc() + now);
	}
	cout << ans << endl;
	
	return 0;
}