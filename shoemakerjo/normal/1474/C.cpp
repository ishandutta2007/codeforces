#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int maxn = 1010;

// int a[maxn];
// 
// bool rem[maxn];

void solve() {
	int n;
	cin >> n;
	n *= 2;
	vector<int> a;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		a.push_back(cur);
	}
	sort(a.begin(), a.end());

	multiset<int> nums;

	for (int i = 0; i < n-1; i++) {

		// cout << "trying " << i << endl;

		nums.clear();
		for (int j = 0; j < n-1; j++) {
			nums.insert(a[j]);
		}
		int x = a[n-1]+a[i];
		int ox = x;
		nums.erase(nums.find(a[i]));
		vector<pii> res;
		bool ok = true;
		x = a[n-1];
		res.push_back(pii(a[n-1], a[i]));
		for (int j = n-2; j >= 0; j--) {
			if (nums.find(a[j]) == nums.end()) continue;
			int cdiff = x - a[j];
			nums.erase(nums.find(a[j]));
			if (nums.find(cdiff) != nums.end()) {
				x = a[j];
				nums.erase(nums.find(cdiff));
				res.push_back(pii(a[j], cdiff));
			}
			else {
				ok = false;
				break;
			}

		}

		if (ok) {
			cout << "YES" << endl;
			cout << ox << endl;
			for (pii vp : res) cout << vp.first << " " << vp.second << endl;
			return;
		}

	}
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) solve();
}