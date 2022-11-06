#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long LL;

using namespace std;

const int MAXN = 100000 + 9, INF = 1000000000;

LL n;

int sum(LL x)
{
	int res = 0;
	while(x)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	LL cur = 0;
	cin >> n;
	while(cur * 10 + 9 <= n)
	{
		cur = cur * 10 + 9;
	}
	cout << sum(cur) + sum(n - cur);
	
	return 0;
}