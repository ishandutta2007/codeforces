#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node { vector<pii> outs; }; // (dest, edge index)

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	int L = 2e5;
	int M = 4e5;
	vector<Node> g(M);
	rep(i,0,N) {
		int x, y;
		cin >> x >> y; --x, --y;
		g[x].outs.emplace_back(L + y, i);
		g[L + y].outs.emplace_back(x, i);
	}
	vi unm;
	rep(i,0,M) {
		if (sz(g[i].outs) % 2 != 0)
			unm.push_back(i);
	}
	int ind = N;
	rep(i,0,sz(unm)/2) {
		int a = unm[i];
		int b = unm[i + sz(unm)/2];
		g[a].outs.emplace_back(b, ind);
		g[b].outs.emplace_back(a, ind++);
	}

	vi eu(ind);
	vector<vector<pii>::iterator> its;
	trav(n, g)
		its.push_back(n.outs.begin());
	vi s(M);
	iota(all(s), 0);
	while(!s.empty()) {
		int x = s.back();
		auto& it = its[x], end = g[x].outs.end();
		while(it != end && eu[it->second]) it++;
		if(it == end) { s.pop_back(); }
		else { s.push_back(it->first); eu[it->second] = (x < it->first) + 1; }
	}

	rep(i,0,N) {
		cout << (eu[i] == 1 ? 'r' : 'b');
	}
	cout << endl;
}