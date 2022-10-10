#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long ans = 0;
	while(n--)
	{
		long long x, y;
		cin >> x >> y;
		ans = max(ans, x + y);
	}
	cout << ans << endl;
}