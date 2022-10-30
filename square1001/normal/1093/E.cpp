#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
class fenwicktree {
private:
	int sz;
	vector<int> val;
public:
	fenwicktree() : sz(0), val(vector<int>()) {};
	fenwicktree(int sz_) : sz(sz_), val(vector<int>(sz_ + 1, 0)) {};
	void add(int pos, int delta) {
		for (int i = pos + 1; i <= sz; i += i & (-i)) {
			val[i] += delta;
		}
	}
	int sum(int pos) {
		int ans = 0;
		for (int i = pos; i >= 1; i -= i & (-i)) {
			ans += val[i];
		}
		return ans;
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	vector<int> ip(N), A(N);
	for (int i = 0; i < N; ++i) {
		int buf;
		cin >> buf;
		ip[--buf] = i;
	}
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[i] = ip[--A[i]];
	}
	int sz = 1;
	while (sz < N) sz *= 2;
	vector<vector<int> > segcand(N + 1);
	function<void(int, int)> pushcand = [&](int x, int y) {
		for (int i = x + 1; i <= N; i += i & (-i)) {
			segcand[i].push_back(y);
		}
	};
	for (int i = 0; i < N; ++i) {
		pushcand(i, A[i]);
	}
	vector<int> tp(Q), va(Q), vb(Q), vc(Q), vd(Q);
	vector<int> cur = A;
	for (int i = 0; i < Q; ++i) {
		cin >> tp[i] >> va[i] >> vb[i];
		if (tp[i] == 1) {
			cin >> vc[i] >> vd[i];
			--va[i], --vc[i];
		}
		else {
			--va[i], --vb[i];
			swap(cur[va[i]], cur[vb[i]]);
			pushcand(va[i], cur[va[i]]);
			pushcand(vb[i], cur[vb[i]]);
		}
	}
	for (int i = 1; i <= N; ++i) {
		sort(segcand[i].begin(), segcand[i].end());
		segcand[i].erase(unique(segcand[i].begin(), segcand[i].end()), segcand[i].end());
	}
	vector<fenwicktree> seg(N + 1);
	for (int i = 1; i <= N; ++i) {
		seg[i] = fenwicktree(segcand[i].size());
	}
	function<void(int, int, int)> add = [&](int x, int y, int delta) {
		for (int i = x + 1; i <= N; i += i & (-i)) {
			int ptr = lower_bound(segcand[i].begin(), segcand[i].end(), y) - segcand[i].begin();
			seg[i].add(ptr, delta);
		}
	};
	function<int(int, int)> sum = [&](int x, int y) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & (-i)) {
			int ptr = lower_bound(segcand[i].begin(), segcand[i].end(), y) - segcand[i].begin();
			ans += seg[i].sum(ptr);
		}
		return ans;
	};
	for (int i = 0; i < N; ++i) {
		add(i, A[i], 1);
	}
	for (int i = 0; i < Q; ++i) {
		if (tp[i] == 2) {
			add(va[i], A[va[i]], -1);
			add(vb[i], A[vb[i]], -1);
			swap(A[va[i]], A[vb[i]]);
			add(va[i], A[va[i]], 1);
			add(vb[i], A[vb[i]], 1);
		}
		else {
			int ans1 = sum(vc[i], va[i]);
			int ans2 = sum(vd[i], vb[i]);
			int ans3 = sum(vc[i], vb[i]);
			int ans4 = sum(vd[i], va[i]);
			cout << ans1 + ans2 - ans3 - ans4 << '\n';
		}
	}
	return 0;
}