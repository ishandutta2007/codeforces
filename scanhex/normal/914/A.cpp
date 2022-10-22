#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x ;
	int mx = -1000000000;
	for (int x : a)
	{
		int a = 0;
		while (a * a < x)
			++a;
		if (a * a > x)
			mx = max(mx, x);
	}
	cout << mx << endl;
}