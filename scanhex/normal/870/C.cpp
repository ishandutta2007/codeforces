#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		int ans = 0;
		if (n % 2 == 1)
			n -= 9, ++ans;
		if (n % 4 == 2)
			n -= 6, ++ans;
		if (n < 0)
		{
			cout << -1 << endl;
		}
		else
			cout << ans + n / 4 << endl;
	}
}