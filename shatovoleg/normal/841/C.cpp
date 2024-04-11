#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> a(n), b(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i].first;
		b[i].second = i;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> res(n);
	for (int i = 0; i < n; ++i)
		res[b[i].second] = a[n - i - 1].first;
	for (auto x : res)
		cout << x << " ";
	cout << endl;
}