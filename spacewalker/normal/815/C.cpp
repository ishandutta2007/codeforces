#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1000000000000000;
constexpr int NMAX = 5010;

vector<ll> withoutDiscount[NMAX], withDiscount[NMAX]; // what is min price needed to buy >= k items?

vector<ll> cost, discounted;
vector<vector<int>> anak;

vector<ll> minConvolution(vector<ll> &a, vector<ll> &b) {
	if (a.empty()) return b;
	if (b.empty()) return a;
	vector<ll> ans(int(a.size() + b.size()) - 1, INF);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			ans[i + j] = min(ans[i + j], a[i] + b[j]);
		}
	}
	return ans;
}

void addToChoices(vector<ll> &minCosts, ll v, bool takeRequired) {
	ll pakyawCost = minCosts.back();
	minCosts.push_back(pakyawCost + v);
	for (int i = (int)minCosts.size() - 2; i > 0; --i) {
		if (!takeRequired) minCosts[i] = min(minCosts[i], minCosts[i-1] + v);
		else minCosts[i] = minCosts[i-1] + v;
	}
}

void getDetails(int v) {
	if (anak[v].size() == 0) {
		withoutDiscount[v] = {0, cost[v]};
		withDiscount[v] = {0, discounted[v]};
	} else {
		for (int u : anak[v]) getDetails(u);
		// first, compute withoutDiscount
		for (int u : anak[v]) withoutDiscount[v] = minConvolution(withoutDiscount[u], withoutDiscount[v]);
		addToChoices(withoutDiscount[v], cost[v], false);
		// then, compute withDiscount
		for (int u : anak[v]) withDiscount[v] = minConvolution(withDiscount[v], withDiscount[u]);
		addToChoices(withDiscount[v], discounted[v], true);
		for (int i = 0; i < withDiscount[v].size(); ++i) {
			withDiscount[v][i] = min(withDiscount[v][i], withoutDiscount[v][i]);
		}
	}
//	printf("%d %lu %lu YEET\n", v, withoutDiscount[v].size(), withDiscount[v].size());
}

int main() {
	int n, b; scanf("%d %d", &n, &b);
	cost = discounted = vector<ll>(n);
	anak = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", &cost[i], &discounted[i]);
		discounted[i] = cost[i] - discounted[i];
		if (i > 0) {
			int x; scanf("%d", &x);
			anak[--x].push_back(i);
		}
	}
	getDetails(0);
	for (int i = n; i >= 0; --i) {
		if (withDiscount[0][i] <= b) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}