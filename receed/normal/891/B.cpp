#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	map<int, int> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			ans[a[i].second] = a[0].first;
		else
			ans[a[i].second] = a[i + 1].first;
	}
	for (int i : ans)
		cout << i << ' ';
}