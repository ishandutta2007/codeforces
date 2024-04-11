#include <bits/stdc++.h>
using namespace std;

int main()
{
	int mx = 0, mn = INT_MAX;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		mx = max(mx, a);
		mn = min(mn, a);
	}
	cout << mx - mn - n + 1 << endl;
}