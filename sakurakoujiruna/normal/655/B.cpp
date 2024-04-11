#include <iostream>
using namespace std;

typedef long long intl;

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	if(k > n / 2)
		k = n / 2;
	intl ans = 0;
	for(int i = 1; i <= k; i ++)
		ans += 1 + (n - 2 * i) * 2;
	cout << ans << '\n';
	return 0;
}