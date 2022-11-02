#include <iostream>
using namespace std;

typedef long long intl;

intl combine(int n, int m)
{
	intl ans = 1;
	for(int i = n; i > n - m; i --)
		ans *= i;
	for(int i = 1; i <= m; i ++)
		ans /= i;
	return ans;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	intl ans = combine(n, 5) * combine(n, 5);
	for(int i = 1; i <= 5; i ++)
		ans *= i;
	cout << ans << '\n';
}