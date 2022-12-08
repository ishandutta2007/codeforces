#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<i64, i64>;

void solve() {
	i64 n, m;
	std::cin >> n >> m;
	std::vector<i64> x(n), y(n), z(n);
	for (int i = 0; i < n; ++i) {
		z[i] = i;
	}
	std::map<i64, i64> pre, suf;
	std::priority_queue<pii, std::vector<pii>, std::greater<>> ql, qr;
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i];
		qr.emplace(x[i] - y[i], i);
		pre[x[i]] = -1e16;
		suf[x[i]] = -1e16;
	}
	std::sort(z.begin(), z.end(), [&](i64 a, i64 b) {
		return x[a] != x[b] ? x[a] < x[b] : a < b;
	});
	i64 suml = 0, sumr = 0, posl = 0, posr = 0, cntl = 0, cntr = 0;
	for (int i = 0; i < n; ++i) {
		while (!ql.empty() && ql.top().first <= x[z[i]]) {
			int d = ql.top().second;
			ql.pop();
			posl -= x[d];
			suml -= y[d];
			--cntl;
		}
		while (!qr.empty() && qr.top().first <= x[z[i]]) {
			int d = qr.top().second;
			qr.pop();
			posr += x[d];
			sumr += y[d];
			++cntr;
		}
		posr -= x[z[i]];
		posl += x[z[i]];
		sumr -= y[z[i]];
		suml += y[z[i]];
		--cntr;
		++cntl;
		ql.emplace(x[z[i]] + y[z[i]], z[i]);
		i64 val = suml - (cntl * x[z[i]] - posl) + sumr - (posr - cntr * x[z[i]]);
		if (val > m) pre[x[z[i]]] = suf[x[z[i]]] = val - m;
	}
	if (pre.empty()) {
		for (int i = 0; i < n; ++i) {
			std::cout << '1';
		}
		std::cout << '\n';
		return;
	}
	for (auto it1 = pre.begin(), it2 = ++pre.begin(); it2 != pre.end(); ++it1, ++it2) {
		it2->second = std::max(it2->second, it1->second + it2->first - it1->first);
	}
	for (auto it1 = suf.rbegin(), it2 = ++suf.rbegin(); it2 != suf.rend(); ++it1, ++it2) {
		it2->second = std::max(it2->second, it1->second + it1->first - it2->first);
	}
	for (int i = 0; i < n; ++i) {
		if (y[i] >= std::max(pre[x[i]], suf[x[i]])) std::cout << '1';
		else std::cout << '0';
	}
	std::cout << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}