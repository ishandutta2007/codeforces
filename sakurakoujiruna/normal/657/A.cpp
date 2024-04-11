#include <iostream>
#include <numeric>
using namespace std;

const int N = 100011;

int u[N], v[N];
int p[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, d, h;
	cin >> n >> d >> h;
	if(n > 2 && d == 1)
	{
		cout << -1 << '\n';
		return 0;
	}
	if(h < (d + 1) / 2 || h > d)
	{
		cout << -1 << '\n';
		return 0;
	}
	int eid = 0;
	for(int i = 1; i <= d; i ++)
	{
		++ eid;
		u[eid] = i;
		v[eid] = i + 1;
	}
	for(int i = d + 2; i <= n; i ++)
	{
		++ eid;
		u[eid] = d / 2 + 1;
		v[eid] = i;
	}

	iota(p + 1, p + n + 1, 1);
	swap(p[1], p[h + 1]);
	for(int i = 1; i < n; i ++)
		cout << p[u[i]] << ' ' << p[v[i]] << '\n';

	return 0;
}