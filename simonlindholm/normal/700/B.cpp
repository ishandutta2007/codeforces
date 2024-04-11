#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

int N, K;
struct Node {
	bool isMarked = false;
	int nmarked;
	vi children;
};
vector<Node> nodes;

vector<vi> ed;
void dfs(int at, int par) {
	nodes[at].children.reserve(ed[at].size());
	trav(x, ed[at]) {
		if (x == par) continue;
		nodes[at].children.push_back(x);
		dfs(x, at);
		nodes[at].nmarked += nodes[x].nmarked;
	}
	nodes[at].nmarked += nodes[at].isMarked;
}

ll res = 0;

void dfs2(int at, int wantedExcess) {
	Node& n = nodes[at];
	assert(n.nmarked >= wantedExcess);
	vector<pii> req;
	req.reserve(n.children.size() + 1);
	if (n.isMarked)
		req.emplace_back(1, -1);
	rep(i,0,sz(n.children)) {
		int x = n.children[i];
		req.emplace_back(nodes[x].nmarked, i);
	}
	if (req.empty()) return;
	sort(all(req));
	reverse(all(req));

	res += wantedExcess;

	int rem = req[0].first - wantedExcess;
	if (rem * 2 > (n.nmarked - wantedExcess)) {
		assert(req[0].second != -1);
		int others = n.nmarked - req[0].first + wantedExcess;
		assert(others < req[0].first);
		rep(i,0,sz(n.children)) {
			int x = n.children[i];
			if (i == req[0].second) {
				dfs2(x, others);
			}
			else {
				dfs2(x, nodes[x].nmarked);
			}
		}
	}
	else {
		// then pair everything up
		trav(x, n.children) {
			dfs2(x, nodes[x].nmarked);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	cin >> N >> K;
	ed.resize(N);
	nodes.resize(N);
	rep(i,0,2*K) {
		int v;
		cin >> v;
		--v;
		nodes[v].isMarked = 1;
	}
	rep(i,0,N-1) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	dfs(0, -1);
	dfs2(0, 0);
	cout << res << endl;

	exit(0);
}