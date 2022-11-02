#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int query(vector<int> x) {
	if (x.empty()) return -1;
	sort(all(x));
	x.resize(unique(all(x)) - x.begin());
	cout << "? " << (int)x.size() << " ";
	for (auto i : x) cout << i << " ";
	cout << endl;
	int ans;
	cin >> ans;
	return ans;
}

vector<int> make_xor(vector<int> a, int n) {
	set<int> fans;
	for (int i = 1; i <= n; i++) {
		fans.insert(i);
	}
	for (auto i : a) {
		fans.erase(i);
	}
	a.clear();
	for (auto i : fans)
		a.push_back(i);
	return a;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(k);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		a[i].resize(x);
		for (auto &j : a[i]) {
			cin >> j;
		}
		sort(all(a[i]));
	}
	vector<int> All(n);
	iota(all(All), 1);
	int mx = query(All);
	int l = 0, r = n;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		vector<int> fq;
		for (int i = l + 1; i <= mid; i++) {
			fq.push_back(i);
		}
		if (query(fq) == mx) {
			r = mid; 
		} else {
			l = mid;
		}
	}
	int pos = r;
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		bool ok = true;
		for (auto j : a[i]) {
			ok &= j != pos;
		}
		if (ok) {
			ans.push_back(mx);
		} else {
			ans.push_back(query(make_xor(a[i], n)));
		}
	}
	cout << "! ";
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
	string s;
	cin >> s;
	assert(s == "Correct");
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}