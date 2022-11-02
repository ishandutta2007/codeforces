#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
class data_structure {
private:
	int H, W;
	vector<int> par, szx, szy;
	vector<long long> num_points;
	vector<vector<pair<int, int> > > ops;
	int root(int x) {
		if (x == par[x]) return x;
		ops.back().push_back(make_pair(x, par[x]));
		return par[x] = root(par[x]);
	}
	void link(int va, int vb) {
		va = root(va);
		vb = root(vb);
		if (va == vb) return;
		if (szx[va] + szy[va] < szx[vb] + szy[vb]) {
			swap(va, vb);
		}
		num_points.back() -= 1LL * szx[va] * szy[va];
		num_points.back() -= 1LL * szx[vb] * szy[vb];
		num_points.back() += 1LL * (szx[va] + szx[vb]) * (szy[va] + szy[vb]);
		ops.back().push_back(make_pair(vb, par[vb]));
		ops.back().push_back(make_pair(H + W + va, szx[va]));
		ops.back().push_back(make_pair(H + W + vb, szx[vb]));
		ops.back().push_back(make_pair(H * 2 + W * 2 + va, szy[va]));
		ops.back().push_back(make_pair(H * 2 + W * 2 + vb, szy[vb]));
		par[vb] = va;
		szx[va] += szx[vb]; szx[vb] = 0;
		szy[va] += szy[vb]; szy[vb] = 0;
	}
public:
	data_structure() : H(0), W(0), par(), szx(), szy(), num_points({ 0 }), ops() {};
	data_structure(int H_, int W_) : H(H_), W(W_), par(H_ + W_), szx(H_ + W_), szy(H_ + W_), num_points({ 0 }), ops() {
		for (int i = 0; i < H + W; ++i) {
			par[i] = i;
			if (i < H) szx[i] = 1;
			else szy[i] = 1;
		}
	}
	void add_point(int x, int y) {
		ops.push_back(vector<pair<int, int> >());
		num_points.push_back(num_points.back());
		link(x, H + y);
	}
	void revert() {
		int sz = ops.back().size();
		for (int i = sz - 1; i >= 0; --i) {
			pair<int, int> p = ops.back()[i];
			if (p.first < H + W) par[p.first] = p.second;
			else if (p.first < H * 2 + W * 2) szx[p.first - H - W] = p.second;
			else szy[p.first - H * 2 - W * 2] = p.second;
		}
		ops.pop_back();
		num_points.pop_back();
	}
	long long get() {
		return num_points.back();
	}
};
int main() {
	// step #1. input phase
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	vector<int> cx(X), cy(Y);
	sort(cx.begin(), cx.end()); cx.erase(unique(cx.begin(), cx.end()), cx.end());
	sort(cy.begin(), cy.end()); cy.erase(unique(cy.begin(), cy.end()), cy.end());
	for (int i = 0; i < N; ++i) {
		X[i] = lower_bound(cx.begin(), cx.end(), X[i]) - cx.begin();
		Y[i] = lower_bound(cy.begin(), cy.end(), Y[i]) - cy.begin();
	}
	// step #2. construct segment tree of operatios
	int rank = 0;
	while ((1 << rank) < N) ++rank;
	vector<vector<pair<int, int> > > addpoint(2 << rank);
	map<pair<int, int>, int> pointset;
	for (int i = 0; i < N; ++i) {
		if (pointset.find(make_pair(X[i], Y[i])) == pointset.end()) {
			pointset[make_pair(X[i], Y[i])] = i;
		}
		else {
			int l = pointset[make_pair(X[i], Y[i])], r = i;
			l += (1 << rank), r += (1 << rank);
			while (l != r) {
				if (l & 1) addpoint[l++].push_back(make_pair(X[i], Y[i]));
				if (r & 1) addpoint[--r].push_back(make_pair(X[i], Y[i]));
				l >>= 1; r >>= 1;
			}
			pointset.erase(make_pair(X[i], Y[i]));
		}
	}
	for (pair<pair<int, int>, int> i : pointset) {
		int l = i.second, r = N;
		l += (1 << rank), r += (1 << rank);
		while (l != r) {
			if (l & 1) addpoint[l++].push_back(make_pair(i.first.first, i.first.second));
			if (r & 1) addpoint[--r].push_back(make_pair(i.first.first, i.first.second));
			l >>= 1; r >>= 1;
		}
	}
	// step #3. calculate the answers
	data_structure ds(cx.size(), cy.size());
	vector<long long> ans(N);
	function<void(int, int, int)> solve = [&](int l, int r, int k) {
		for (pair<int, int> i : addpoint[k]) {
			ds.add_point(i.first, i.second);
		}
		if (r - l == 1) {
			if (l < N) {
				ans[l] = ds.get();
			}
		}
		else {
			solve(l, (l + r) >> 1, k * 2);
			solve((l + r) >> 1, r, k * 2 + 1);
		}
		for (pair<int, int> i : addpoint[k]) {
			ds.revert();
		}
	};
	solve(0, 1 << rank, 1);
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << (i != N - 1 ? ' ' : '\n');
	}
	return 0;
}