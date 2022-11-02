#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const long double Pi = 4 * atanl(1);
const long double Eps = 1e-17;
int sgn(long double a, long double b = 0.0)
{
	a -= b;
	if(a > Eps)
		return 1;
	if(a < -Eps)
		return -1;
	return 0;
}

const int N = 101111;
pair <long double, int> a[N];

void update(long double na, int nu, int nv, long double &ma, int &u, int &v)
{
	if(sgn(na, ma) < 0)
	{
		ma = na;
		u = nu;
		v = nv;
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		long double x, y;
		cin >> x >> y;
		a[i].first = atan2l(y, x);
		if(sgn(a[i].first) < 0)
			a[i].first += 2 * Pi;
		a[i].second = i;
	}
	
	sort(a, a + n);
	long double ma = 2 * Pi;
	int u, v;
	a[n] = a[0];
	a[n].first += 2 * Pi;
	for(int i = 0; i < n; i ++)
		update(fabsl(a[i].first - a[i + 1].first), a[i].second, a[i + 1].second, ma, u, v);
	cout << u + 1 << ' ' << v + 1 << '\n';
	return 0;
}