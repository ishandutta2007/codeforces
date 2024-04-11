#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		int n, k;
		vector<int> v;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) {
			cin >> a[i]; v.emplace_back(a[i]);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		auto id = [&](int x) {
			return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
		};
		int need = n;
		for (int i = 0; i + 1 < n; i ++) {
			if (id(a[i]) + 1 == id(a[i+1])) need --;
		}
		cout << (need<=k?"Yes":"No") << endl;
	}
}