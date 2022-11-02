#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int N = 121;
const double Pi = 4 * atan(1);

int r[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> r[i];
	sort(r + 1, r + n + 1);
	double ans = 0;
	for(int i = n; i >= 1; i -= 2)
		ans += (r[i] * r[i] - r[i - 1] * r[i - 1]) * Pi;
	cout << setprecision(6) << ans << '\n';
	return 0;
}