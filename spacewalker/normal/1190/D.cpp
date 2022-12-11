#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void forceComp(ll x, map<ll, int> &comp) {
	if (comp.count(x) == 0) {
		int ita = comp.size();
		comp[x] = ita;
	}
}

ll countSubRange(ll x) {
	return x * (x + 1) / 2;
}

ll countBreachPairs(vector<int> &pts, ll first, ll last) {
//	printf("counting breach layer ");
//	for (ll x : pts) printf("%lld ", x);
//	printf("\n");
//	printf("range %lld %lld\n", first, last);
	ll n = last - first + 1;
	ll ans = countSubRange(n);
	for (int i = 0; i + 1 < pts.size(); ++i) {
		ll diff = pts[i + 1] - pts[i] - 1;
		if (diff < 0) continue;
		ans -= countSubRange(diff);
	}
	ans -= (countSubRange(pts.front() - first) + countSubRange(last - pts.back()));
//	printf("res %lld\n", ans);
	return ans;
}

struct fenwick {
	int n;
	vector<int> tree;
	fenwick(int n): n(n), tree(n + 1, 0) {}
	int LSB(int i) {return (i & (-i));}
	void add(int i, int v) {
		for (int ci = i + 1; ci <= n; ci += LSB(ci)) {
			tree[ci] += v;
		}
	}
	int getPrefix(int i) {
		int ans = 0;
		for (int ci = i + 1; ci > 0; ci -= LSB(ci)) {
			ans += tree[ci];
		}
		return ans;
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<pair<ll, ll>> pts(n);
	for (int i = 0; i < n; ++i) scanf("%lld %lld", &pts[i].first, &pts[i].second);
	map<ll, int> ycomp, xcomp;
	set<ll> xcds, ycds;
	for (int i = 0; i < n; ++i) {
		xcds.insert(pts[i].first);
		ycds.insert(pts[i].second);
	}
	for (ll x : xcds) {
		int ita = xcomp.size();
		xcomp[x] = ita;
	}
	for (ll y : ycds) {
		int ita = ycomp.size();
		ycomp[y] = ita;
	}
	int yLayers = ycomp.size();
	vector<vector<ll>> byyl(yLayers);
	for (auto pp : pts) {
		byyl[ycomp[pp.second]].push_back(xcomp[pp.first]);
//		printf("%lld %lld compressed %d %d\n", pp.first, pp.second, xcomp[pp.first], ycomp[pp.second]);
	}
	for (int i = 0; i < yLayers; ++i) sort(begin(byyl[i]), end(byyl[i]));
	vector<vector<int>> posByX(yLayers);
	vector<int> distXC(yLayers);
	vector<bool> isPresent(xcomp.size(), false);
	fenwick cfing(xcomp.size());
	set<int> posX;
	for (int i = yLayers - 1; i >= 0; --i) {
		for (int xc : byyl[i]) {
			if (isPresent[xc]) continue;
			cfing.add(xc, 1);
			posX.insert(xc);
			isPresent[xc] = true;
		}
		distXC[i] = posX.size();
		for (int xc : byyl[i]) {
			posByX[i].push_back(cfing.getPrefix(xc) - 1);
		}
	}
	ll ans = 0;
	for (int i = yLayers - 1; i >= 0; --i) {
		ans += countBreachPairs(posByX[i], 0, distXC[i] - 1);
	}
	printf("%lld\n", ans);
	return 0;
}