#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1000000000;

struct LinearFunc {
	ll m, b;
	LinearFunc() {}
	LinearFunc(ll m, ll b) : m(m), b(b) {}
	ll evalAt(ll x) {
		return m * x + b;
	}
};

const bool operator < (LinearFunc a, LinearFunc b) {
	return make_pair(a.m, a.b) < make_pair(b.m, b.b);
}

int main() {
	int n; scanf("%d", &n);
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
	vector<ll> optVal(n);
	vector<pair<ll, LinearFunc>> lineStack;
	lineStack.emplace_back(-INF, LinearFunc(b[0], 0));
	// fucking magic i don't know
	for (int i = 1; i < n; ++i) {
		// evaluate optVal
		// get the best line
		int optIdx = distance(begin(lineStack), upper_bound(begin(lineStack), end(lineStack), make_pair(a[i], LinearFunc()))) - 1;
		optVal[i] = lineStack[optIdx].second.evalAt(a[i]);
		// add optVal to the lineStack
		LinearFunc cLine(b[i], optVal[i]);
		while (lineStack.back().second.evalAt(lineStack.back().first) >= cLine.evalAt(lineStack.back().first)) {
			lineStack.pop_back();
		}
		// find the first point such that cLine is optimal
		ll lo = -1, hi = 2000000000;
		while (lo < hi) {
			ll mid = lo + (hi - lo) / 2;
			if (cLine.evalAt(mid) <= lineStack.back().second.evalAt(mid)) hi = mid;
			else lo = mid + 1;
		}
		lineStack.emplace_back(lo, cLine);
	}
	printf("%lld\n", optVal[n-1]);
	return 0;
}