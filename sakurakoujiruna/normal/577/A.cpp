#include <iostream>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;

	int ans = 0;
	for(int d = 1; d * d <= x; d ++)
		if(x % d == 0 && d <= n && x / d <= n)
		{
			ans += 2;
			if(d * d == x)
				ans --;
		}
	cout << ans << '\n';
	return 0;
}