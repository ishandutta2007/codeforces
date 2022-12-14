#include <bits/stdc++.h>
using namespace std;

int n, l = 0, r = 1000000001, mid;
string lst, in;

int main()
{
	cin >> n;
	cout << "0 233" << endl;
	cin >> in;
	lst = in;
	bool flag = true;
	for (int i = 1; i < n; i++)
	{
		mid = l + r >> 1;
		cout << mid << ' ' << 233 << endl;
		cin >> in;
		if (in == lst) l = mid;
		else r = mid;
	}
	cout << l << ' ' << 0 << ' ' << (r == 1000000001 ? r - 1 : r) << ' ' << 466 << endl;
	return 0;
}