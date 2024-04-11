#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	set<int> x;
	set<int> y;
	for (int i = 0; i < n; ++i)
	{
		int a, b; cin >> a >> b; x.insert(a); y.insert(b);
	}
	if (x.size() == 2 && y.size() == 2)
	{
		auto it = x.begin();
		auto it1 = y.begin();
		cout << (*it - *++it) * (*it1 - *++it1) << endl;
	}
	else
		cout << -1 << endl;
}