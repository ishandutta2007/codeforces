#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	ll N, C, D;
	cin >> N >> C >> D;
	typedef pair<ll, ll> pll;
	vector<pll> di[2];

	const ll inf = 1LL << 60;

	ll bestC = -inf;
	ll bestD = -inf;
	rep(i,0,N) {
		ll val, cost;
		char type;
		cin >> val >> cost >> type;
		if (type == 'C') {
			if (cost <= C) bestC = max(bestC, val);
			di[0].emplace_back(cost, val);
		}
		else {
			if (cost <= D) bestD = max(bestD, val);
			di[1].emplace_back(cost, val);
		}
	}

	ll res = bestC + bestD;

	rep(t,0,2) {
		ll avail = (t == 0 ? C : D);
		sort(all(di[t]));
		pll bestVal = {-inf, -1LL}, secBestVal = {-inf, -1LL};
		vector<pair<ll, pair<pll, pll>>> bests;
		trav(pa, di[t]) {
			swap(pa.first, pa.second);
			if (pa > bestVal) secBestVal = bestVal, bestVal = pa;
			else if (pa > secBestVal) secBestVal = pa;
			bests.push_back({pa.second, {bestVal, secBestVal}});
		}

		trav(pa, di[t]) {
			ll co = pa.second, va = pa.first;
			if (co > avail) continue;
			pair<ll, pair<pll, pll>> search{avail - co, {{inf, inf}, {inf, inf}}};
			auto it = upper_bound(all(bests), search);
			if (it == bests.begin()) continue;
			--it;
			auto pa2 = it->second;
			auto pa3 = (pa2.first == pa ? pa2.second : pa2.first);
			res = max(res, va + pa3.first);
		}
	}

	if (res < 0) cout << 0 << endl;
	else cout << res << endl;

	exit(0);
}