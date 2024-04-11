#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<bool> kek(10), mem(10);
	int mn1 = 10, mn2 = 10;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		kek[x] = true;
		mn1 = min(mn1, x);
	}
	for (int j = 0; j < m; ++j)
	{
		int x; 
		cin >> x;
		mem[x] = true;
		mn2 = min(mn2, x);
	}
	for (int i = 1; i < 10; ++i)
	{
		if (kek[i] && mem[i])
		{
			cout << i << endl;
			return 0;
		}
	}
	if (mn1 > mn2)
		swap(mn1, mn2);
	cout << mn1 << mn2 << endl;
}