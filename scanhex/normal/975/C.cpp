#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	typedef long long nagai;
	vector<nagai> a(n), k(q);
	for (auto& x : a)
		cin >> x;
	for (auto& x : k)
		cin >> x;
	vector<nagai> pref(n + 1);
	for (int i = 0; i < n; ++i)
		pref[i + 1] = pref[i] + a[i];
	nagai curcnt = 0;
	for (int i = 0; i < q; ++i)
	{
		curcnt += k[i];
		int a = pref.end() - upper_bound(pref.begin(), pref.end(), curcnt);
		if (a == 0)
			a = n, curcnt = 0;
		cout << a << '\n';
	}
}