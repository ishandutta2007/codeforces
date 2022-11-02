#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
class segtree {
private:
	int sz;
	vector<int> seg;
public:
	segtree() : sz(0), seg(vector<int>()) {};
	segtree(int sz_) {
		sz = 1;
		while (sz < sz_) sz *= 2;
		seg.resize(sz * 2);
	}
	void update(int pos, int val) {
		pos += sz;
		seg[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
		}
	}
	int rangemin(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return -inf;
		if (a <= l && r <= b) return seg[k];
		int lc = rangemin(a, b, k * 2, l, (l + r) >> 1);
		int rc = rangemin(a, b, k * 2 + 1, (l + r) >> 1, r);
		return max(lc, rc);
	}
	int rangemin(int a, int b) {
		return rangemin(a, b, 1, 0, sz);
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Q;
	cin >> Q;
	while (Q--) {
		int N;
		cin >> N;
		vector<int> A(N), B(N);
		for (int i = 0; i < N; ++i) cin >> A[i], --A[i];
		for (int i = 0; i < N; ++i) cin >> B[i], --B[i];
		vector<vector<int> > G(N);
		segtree seg(N);
		for (int i = 0; i < N; ++i) {
			G[A[i]].push_back(i);
			seg.update(i, A[i]);
		}
		bool ok = true;
		for (int i = N - 1; i >= 0; --i) {
			if (G[B[i]].empty()) {
				ok = false;
				break;
			}
			int pos = G[B[i]].back();
			G[B[i]].pop_back();
			if (seg.rangemin(pos, N) > B[i]) {
				ok = false;
				break;
			}
			seg.update(pos, -1);
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}