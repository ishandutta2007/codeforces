#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(0));

vector<int> get(int l, int r) {
	vector<int> ans;
	for (int i = l; i <= r; i++) {
		ans.push_back(i);
	}
	return ans;
}

int query(vector<int> a, vector<int> b) {
	assert(a.size() == b.size());
	cout << "? " << a.size() << " " << b.size() << endl;
	for (auto i : a) cout << i + 1 << " ";
	cout << endl;
	for (auto i : b) cout << i + 1 << " ";
	cout << endl;
	string ans;
	cin >> ans;
	if (ans == "FIRST") return 1;
	if (ans == "EQUAL") return 0;
	if (ans == "SECOND") return -1;
	assert(false);
}

void out_ans(int ans) {
	cout << "! " << ans + 1 << endl;
}

void solve() {
	int n, k;
	cin >> n >> k;
	bool ok = false;
	for (int i = 0; i < 30; i++) {
		int pos = rnd() % (n - 1) + 1;
		ok |= query({0}, {pos}) == -1;
	}
	if (ok) {
		out_ans(0);
		return;
	} 
	int sz = 1;
	while (sz * 2 <= n) {
		if (query(get(0, sz - 1), get(sz, sz * 2 - 1)) == 0) {
			sz *= 2;
		} else {
			break;
		}
	}
	int l = sz - 1, r = min(n, sz * 2);
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (query(get(0, mid - sz), get(sz, mid)) == 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	out_ans(r);
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}