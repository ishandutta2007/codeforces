#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	if (k >= 3)
	{
		cout << *max_element(a.begin(), a.end()) << endl;
		return 0;
	}
	if (k == 1)
	{
		cout << *min_element(a.begin(), a.end()) << endl;
		return 0;
	}
	vector<int> pref(n), suff(n);
	pref[0] = a[0];
	suff[n - 1] = a[n - 1];
	for (int i = 0; i < n - 1; ++i)
		pref[i + 1] = min(pref[i], a[i + 1]);
	for (int i = n - 1; i > 0; --i)
		suff[i - 1] = min(suff[i], a[i - 1]);
	int mx = -2e9;
	for (int i = 0; i < n - 1; ++i)
	{
		mx = max(mx, max(pref[i], suff[i + 1]));
	}
	cout << mx << endl;
}