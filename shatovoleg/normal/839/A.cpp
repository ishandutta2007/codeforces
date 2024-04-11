#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, cur = 0, sm = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		sm += v;
		int z = min(8, sm);
		cur += z;
		sm -= z;
		if (cur >= k)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}