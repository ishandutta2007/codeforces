#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<set<int> > G(N);
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i]; --A[i];
		G[A[i]].insert(i);
	}
	vector<map<int, long long> > bit(N + 1);
	function<void(int, int, long long)> add = [&](int x, int y, long long delta) {
		for (int i = x + 1; i <= N; i += i & (-i)) {
			for (int j = y + 1; j <= N; j += j & (-j)) {
				bit[i][j] += delta;
			}
		}
	};
	function<long long(int, int)> sum = [&](int x, int y) {
		long long ans = 0;
		for (int i = x; i >= 1; i -= i & (-i)) {
			for (int j = y; j >= 1; j -= j & (-j)) {
				ans += bit[i][j];
			}
		}
		return ans;
	};
	function<void(int, int, long long)> toggle_segment = [&](int l, int r, long long delta) {
		add(N - l - 1, r - 1, delta);
	};
	function<long long(int, int)> get_score = [&](int l, int r) {
		return sum(N - l, r);
	};
	for (int i = 0; i < N; ++i) {
		for (int j : G[i]) {
			set<int>::iterator it = G[i].lower_bound(j + 1);
			if (it != G[i].end()) {
				toggle_segment(j, *it + 1, *it - j);
			}
		}
	}
	for (int i = 0; i < Q; ++i) {
		int tp, x, y;
		cin >> tp >> x >> y, --x;
		if (tp == 1) {
			--y;
			G[A[x]].erase(x);
			set<int>::iterator it = G[A[x]].lower_bound(x);
			int l = -1, r = -1;
			if (it != G[A[x]].end()) {
				r = *it;
				toggle_segment(x, r + 1, -(r - x));
			}
			if (it != G[A[x]].begin()) {
				--it;
				l = *it;
				toggle_segment(l, x + 1, -(x - l));
			}
			if (l != -1 && r != -1) {
				toggle_segment(l, r + 1, r - l);
			}
			A[x] = y;
			it = G[A[x]].lower_bound(x);
			l = -1, r = -1;
			if (it != G[A[x]].end()) {
				r = *it;
				toggle_segment(x, *it + 1, *it - x);
			}
			if (it != G[A[x]].begin()) {
				--it;
				l = *it;
				toggle_segment(*it, x + 1, x - *it);
			}
			if (l != -1 && r != -1) {
				toggle_segment(l, r + 1, -(r - l));
			}
			G[A[x]].insert(x);
		}
		if (tp == 2) {
			long long ans = get_score(x, y);
			cout << ans << '\n';
		}
	}
	return 0;
}