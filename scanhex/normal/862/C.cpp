#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	int n, x;
	cin >> n >> x;
	if (x == 0)
	{
		if (n == 1)
		{
			cout << "YES" << endl;
			cout << 0 << endl;
			return 0;
		}
		if (n == 2)
		{
			cout << "NO" << endl;
			return 0;
		}
		if (n == 3)
		{
			cout << "YES" << endl << "1 2 3\n";
			return 0;
		}
	}
	if (x == 1)
	{
		if (n == 1)
		{
			cout << "YES\n1\n";
			return 0;
		}
		if (n == 2)
		{
			cout << "YES\n0 1\n";
			return 0;
		}
		if (n == 3)
		{
			cout << "YES\n0 2 3\n";
			return 0;
		}
	}
	if (n == 1)
	{
		cout << "YES" << endl;
		cout << x << endl;
		return 0;
	}
	int mn = 1e5 + 100;
	int ans = x;
	int rest = n % 2 == 1 ? 1 : 2;
	n -= rest;
	vector<int> a;
	for (int i = mn; i < mn + n; ++i)
	{
		ans ^= i;
		a.push_back(i);
	}
	if (rest == 1)
		a.push_back(ans);
	else
	{
		if (ans == 0)
		{
			a.pop_back();
			a.pop_back();
			a.push_back(1);
			a.push_back(6);
			a.push_back(12);
			a.push_back(10);
		}
		else
			a.push_back(0), a.push_back(ans);
	}
	cout << "YES" << endl;
	for (int x : a)
		cout << x << ' ';
	cout << endl;

}