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
	ll N;
	ll S;
	cin >> N >> S;
	if (N * (N+1) / 2 < S) {
		cout << "No" << endl;
		return 0;
	}
	if (S < 2*N-1) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	if (S == N*(N+1) / 2) {
		rep(i,1,N) cout << i << ' ';
		cout << endl;
		return 0;
	}

	auto mins = [&](int lim) -> ll {
		// smallest S that can be created
		int depth = 1;
		ll count = 1;
		ll rem = N;
		ll res = 0;
		while (rem) {
			ll c = min(rem, count);
			rem -= c;
			res += c * depth;
			count *= lim;
			depth++;
		}
		return res;
	};

	auto mins2 = [&](int lim) -> void {
		// smallest S that can be created
		int depth = 1;
		ll count = 1;
		ll rem = N;
		ll res = 0;
		vector<int> par(N);
		vector<vi> depthNodes;
		depthNodes.emplace_back();
		int ati = 0;
		while (rem) {
			ll c = min(rem, count);
			rem -= c;
			res += c * depth;
			depthNodes.emplace_back();
			vi& prevLayer = depthNodes[depthNodes.size() - 2];
			vi& curLayer = depthNodes.back();
			if (depth == 1) {
				rep(i,ati,ati+c) {
					par[i] = -2;
					curLayer.push_back(i);
				}
			} else {
				ll upmod = 0;
				int upi = 0;
				rep(i,ati,ati+c) {
					// cerr << i << ' ' << upi << ' ' << lim << endl;
					par[i] = prevLayer[upi];
					upmod++;
					if (upmod == lim) {
						upmod = 0;
						upi++;
					}
					curLayer.push_back(i);
				}
			}
			ati += (int)c;

			count *= lim;
			depth++;
		}

		/*
		rep(i,1,N) cout << par[i]+1 << ' ';
		cout << endl;
		cout << res << ' ' << S << endl;
		*/

		int chainNode = depthNodes.back()[0];
		int nextChainDepth = depth;
		for (int d = sz(depthNodes)-1; d >= 0 && res < S; d--) {
			while (sz(depthNodes[d]) > 1 && res < S) {
				int x = depthNodes[d].back();
				depthNodes[d].pop_back();
				if (res + (nextChainDepth - d) <= S) {
					res += (nextChainDepth - d);
					par[x] = chainNode;
					// cerr << "reparent " << x << ' ' << chainNode << endl;
					depthNodes.emplace_back();
					depthNodes.back().push_back(x);
					nextChainDepth++;
					chainNode = x;
				} else {
					// res + (d2 - d) = S
					int d2 = (int)(S - res + d) - 1;

					// cerr << "want depth " << d2 << " for node " << x+1 << endl;

					int y = depthNodes[d2].back();
					par[x] = y;
					res = S;
				}
			}
		}

		vector<vi> chs(N);
		rep(i,1,N) chs[par[i]].push_back(i);
		vector<pii> stack = {pii(0, 1)};
		ll sumd = 0;
		int reachable = 0;
		while (!stack.empty()) {
			auto pa = stack.back();
			int dep = pa.second;
			reachable++;
			sumd += dep;
			int x = pa.first;
			stack.pop_back();
			trav(y, chs[x]) stack.push_back(pii(y, dep+1));
		}
		assert(reachable == N);
		assert(sumd == S);

		rep(i,1,N) cout << par[i]+1 << ' ';
		cout << endl;
	};

	auto works = [&](int lim) -> bool {
		return mins(lim) <= S;
	};

	int lo = 1, hi = (int)N;
	assert(works(hi));
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (works(mid)) hi = mid;
		else lo = mid;
	}

	mins2(hi);
	exit(0);
}