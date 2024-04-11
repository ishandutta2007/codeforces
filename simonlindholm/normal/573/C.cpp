#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool solve(int N) {
	vector<vi> ed(N);
	rep(i,0,N-1) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	if (N == 1) return true;

	vector<int> leaves;
	rep(i,0,N) {
		if (sz(ed[i]) == 1) leaves.push_back(i);
	}
	vi dead(N);
	while (!leaves.empty()) {
		int i = leaves.back();
		leaves.pop_back();
		int j = ed[i][0];
		if (ed[j].size() == 2) {
			if (ed[j][1] != i) swap(ed[j][0], ed[j][1]);
			assert(ed[j][1] == i);
			ed[j].pop_back();
			ed[i].pop_back();
			dead[i] = 1;
			leaves.push_back(j);
		}
	}

	vi isleaf(N);
	rep(i,0,N) isleaf[i] = ed[i].size() == 1;

	rep(i,0,N) {
		if (dead[i]) continue;
		int nleaf = 0;
		vi ned;
		trav(j, ed[i]) {
			if (isleaf[j] && ++nleaf <= 2)
				dead[j] = 1;
			else
				ned.push_back(j);
		}
		ed[i] = move(ned);
	}

	rep(i,0,N) {
		if (dead[i]) continue;
		int cnt = 0;
		trav(j, ed[i]) {
			if (ed[j].size() != 1) cnt++;
		}
		if (cnt > 2) return false;
	}
	return true;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	cout << (solve(N) ? "Yes" : "No") << endl;
}