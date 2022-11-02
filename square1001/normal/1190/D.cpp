#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
	vector<int> cx = X, cy = Y;
	sort(cx.begin(), cx.end());
	cx.erase(unique(cx.begin(), cx.end()), cx.end());
	sort(cy.begin(), cy.end());
	cy.erase(unique(cy.begin(), cy.end()), cy.end());
	for (int i = 0; i < N; ++i) {
		X[i] = lower_bound(cx.begin(), cx.end(), X[i]) - cx.begin();
		Y[i] = lower_bound(cy.begin(), cy.end(), Y[i]) - cy.begin();
	}
	vector<vector<int> > d(cy.size());
	for (int i = 0; i < N; ++i) {
		d[cy.size() - Y[i] - 1].push_back(X[i]);
	}
	vector<int> rec(cx.size()), bit(cx.size() + 1);
	function<void(int, int)> add = [&](int pos, int val) {
		for (int i = pos + 1; i <= cx.size(); i += i & (-i)) {
			bit[i] += val;
		}
	};
	function<int(int)> sum = [&](int pos) {
		int ans = 0;
		for (int i = pos; i >= 1; i -= i & (-i)) {
			ans += bit[i];
		}
		return ans;
	};
	function<int(int, int)> rangesum = [&](int l, int r) {
		return sum(r) - sum(l);
	};
	function<long long(int)> calc = [&](int num) {
		return 1LL * num * (num + 1) / 2;
	};
	long long ans = 0;
	for (vector<int> v : d) {
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i) {
			if (rec[v[i]] != 1) {
				add(v[i], 1);
				rec[v[i]] = 1;
			}
		}
		ans += calc(rangesum(0, cx.size()));
		for (int i = 0; i <= v.size(); ++i) {
			int l = 0, r = cx.size();
			if (i >= 1) l = v[i - 1] + 1;
			if (i < v.size()) r = v[i];
			ans -= calc(rangesum(l, r));
		}
	}
	cout << ans << endl;
	return 0;
}