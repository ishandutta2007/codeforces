#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	unordered_set<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.insert(a[i]);
	}
	sort(a.begin(), a.end());
	map<int,int> sums;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			sums[a[i]+a[j]]++;
		}
	}
	int res = 0;
	for (auto p : sums) {
		res = max(res, p.second);
	}
	cout << res << endl;
	exit(0);
}