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
	int n;
	cin >> n;
	cout << combine(n + 5 - 1, 5) * combine(n + 3 - 1, 3) << '\n';
	return 0;
}