#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int N = 100011;

int l[N], r[N];

double work(int l, int r, int p)
{
	int num = r / p - (l - 1) / p;
	int den = (r - l + 1);
	return (double)num / den;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	for(int i = 0; i < n; i ++)
		cin >> l[i] >> r[i];
	l[n] = l[0];
	r[n] = r[0];

	double ans = 0;
	for(int i = 0; i < n; i ++)
	{
		double p1 = work(l[i], r[i], p);
		double p2 = work(l[i + 1], r[i + 1], p);
		ans += 2000 * (p1 * p2 + p1 * (1 - p2) + (1 - p1) * p2);
	}
	cout << setprecision(15) << ans << '\n';
	return 0;
}