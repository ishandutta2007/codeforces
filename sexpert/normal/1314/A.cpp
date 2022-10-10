#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

map<int, vector<int>> guys;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), t(n);
	for(auto &x : a)
		cin >> x;
	for(auto &x : t)
		cin >> x;
	set<int> active;
	for(int i = 0; i < n; i++) {
		guys[a[i]].push_back(t[i]);
		active.insert(a[i]);
	}
	active.insert(INT_MAX);

	int cur = 0;
	ll ans = 0, sum = 0;
	multiset<int, greater<int>> pending;

	for(auto ac : active) {
		int d = ac - cur;
		cur = ac;
		while(pending.size() && d > 0) {
			sum -= *(pending.begin());
			pending.erase(pending.begin());
			ans += sum;
			d--;
		}
		for(auto x : guys[ac]) {
			pending.insert(x);
			sum += x;
		}
	}
	cout << ans << '\n';
}