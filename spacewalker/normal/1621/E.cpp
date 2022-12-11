#include <bits/stdc++.h>

using namespace std;
constexpr int VMAX = 100010;
using ll = long long;

struct MinPrefTree {
	int al, ar;
	int rsum, mpfsum;
	MinPrefTree *left, *right;
	void combine() {
		rsum = left->rsum + right->rsum;
		// MPFSUM is actually the min suffix sum
		mpfsum = min(right->mpfsum, left->mpfsum + right->rsum);
	}
	MinPrefTree(int i, int j) : al(i), ar(j), rsum(0), mpfsum(0),
		left(nullptr), right(nullptr) {
		if (i != j) {
			int k = (i + j) / 2;
			left = new MinPrefTree(i, k);
			right = new MinPrefTree(k + 1, j);
		}
	}
	~MinPrefTree() {
		if (left) {
			delete left;
			delete right;
		}
	}
	void addPoint(int i, int v) {
		if (i < al || ar < i) return;
		else if (al == ar) {
			rsum += v;
			mpfsum += v;
		} else {
			left->addPoint(i, v);
			right->addPoint(i, v);
			combine();
		}
	}
};

ll iceil(ll n, ll d) {
	return n/d + (n % d ? 1 : 0);
}

void solve() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int>> groups(m);
	vector<int> teachAge(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &teachAge[i]);
	}
	for (int i = 0; i < m; ++i) {
		int k; scanf("%d", &k);
		vector<int> cgrp(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &cgrp[j]);
		}
		groups[i] = cgrp;
	} 
	// Coord compress because wtf problem
	vector<int> pts;
	for (int ta : teachAge) pts.push_back(ta);
	vector<ll> gsum(m);
	for (int i = 0; i < m; ++i) {
		for (int ca : groups[i]) gsum[i] += ca;
	}
	for (int i = 0; i < m; ++i) {
		pts.push_back(iceil(gsum[i], groups[i].size()));
		for (int ca : groups[i]) pts.push_back(iceil(gsum[i] - ca, (int)groups[i].size() - 1));
	}
	sort(begin(pts), end(pts));
	pts.erase(unique(begin(pts), end(pts)), end(pts));
	auto comp = [&] (int i) {
		return distance(begin(pts), lower_bound(begin(pts), end(pts), i));
	};

	MinPrefTree bruh(0, pts.size());
	for (int ta : teachAge) {
		bruh.addPoint(comp(ta), 1);
	}
	for (int i = 0; i < m; ++i) {
		bruh.addPoint(comp(iceil(gsum[i], groups[i].size())), -1);
	}
	for (int i = 0; i < m; ++i) {
		bruh.addPoint(comp(iceil(gsum[i], groups[i].size())), 1);
		for (int ca : groups[i]) {
			bruh.addPoint(comp(iceil(gsum[i] - ca, (int)groups[i].size() - 1)), -1);
			printf("%d", bruh.mpfsum >= 0 ? 1 : 0);
			bruh.addPoint(comp(iceil(gsum[i] - ca, (int)groups[i].size() - 1)), 1);
		}
		bruh.addPoint(comp(iceil(gsum[i], groups[i].size())), -1);
	}
	printf("\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		solve();
	}
}