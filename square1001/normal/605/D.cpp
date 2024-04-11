#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N), D(N);
	vector<int> cx = { 0 }, cy = { 0 };
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		cx.push_back(A[i]);
		cy.push_back(B[i]);
		cx.push_back(C[i]);
		cy.push_back(D[i]);
	}
	sort(cx.begin(), cx.end());
	cx.erase(unique(cx.begin(), cx.end()), cx.end());
	sort(cy.begin(), cy.end());
	cy.erase(unique(cy.begin(), cy.end()), cy.end());
	int sx = cx.size(), sy = cy.size();
	for (int i = 0; i < N; ++i) {
		A[i] = lower_bound(cx.begin(), cx.end(), A[i]) - cx.begin();
		B[i] = lower_bound(cy.begin(), cy.end(), B[i]) - cy.begin();
		C[i] = lower_bound(cx.begin(), cx.end(), C[i]) - cx.begin();
		D[i] = lower_bound(cy.begin(), cy.end(), D[i]) - cy.begin();
	}
	int sz = 1;
	while (sz < sx) sz *= 2;
	vector<set<pair<int, int> > > seg(sz * 2);
	for (int i = 0; i < N - 1; ++i) {
		seg[sz + C[i]].insert(make_pair(D[i], i));
	}
	for (int i = sz - 1; i >= 1; --i) {
		seg[i].insert(seg[i * 2].begin(), seg[i * 2].end());
		seg[i].insert(seg[i * 2 + 1].begin(), seg[i * 2 + 1].end());
	}
	function<vector<int>(int, int)> query = [&](int bx, int by) {
		int l = bx + sz, r = sz * 2;
		vector<int> ans;
		while (l != r) {
			if (l & 1) {
				set<pair<int, int> >::iterator it = seg[l].lower_bound(make_pair(by, -1));
				while (it != seg[l].end()) {
					ans.push_back(it->second);
					++it;
				}
				++l;
			}
			if (r & 1) {
				--r;
				set<pair<int, int> >::iterator it = seg[r].lower_bound(make_pair(by, -1));
				while (it != seg[r].end()) {
					ans.push_back(it->second);
					++it;
				}
			}
			l >>= 1;
			r >>= 1;
		}
		for (int i : ans) {
			int pos = C[i] + sz;
			while (pos > 0) {
				seg[pos].erase(make_pair(D[i], i));
				pos >>= 1;
			}
		}
		return ans;
	};
	vector<int> dist(N, N), par(N, -1);
	dist[N - 1] = 0;
	queue<int> que;
	que.push(N - 1);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		vector<int> v = query(A[u], B[u]);
		for (int i : v) {
			dist[i] = dist[u] + 1;
			par[i] = u;
			que.push(i);
		}
	}
	int pos = -1, opt = N;
	for (int i = 0; i < N; ++i) {
		if (A[i] == 0 && B[i] == 0 && opt > dist[i]) {
			pos = i;
			opt = dist[i];
		}
	}
	if (pos == -1) {
		cout << -1 << '\n';
	}
	else {
		cout << opt + 1 << '\n';
		vector<int> ans = { pos };
		while (pos != N - 1) {
			pos = par[pos];
			ans.push_back(pos);
		}
		for (int i = 0; i <= opt; ++i) {
			if (i) cout << ' ';
			cout << ans[i] + 1;
		}
		cout << '\n';
	}
	return 0;
}