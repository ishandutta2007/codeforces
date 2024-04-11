#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1000000007;

static vector<vector<pii> > ed;
static vi cols;
static ll res = 1;
void dfs(int a, int col = 0) {
	if (cols[a] == -1)
		cols[a] = col;
	else {
		if (cols[a] != col)
			res = 0;
		return;
	}
	trav(pa, ed[a]) {
		int to = pa.first, c = pa.second;
		int col2 = col;
		if (c == 0) col2 = !col2;
		dfs(to, col2);
	}
}

int main() {
	cin.sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	ed.resize(N);
	cols.assign(N, -1);
	rep(i,0,M) {
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		ed[a].emplace_back(b, c);
		ed[b].emplace_back(a, c);
	}
	rep(i,0,N) {
		if (cols[i] != -1)
			continue;
		dfs(i);
		res *= 2;
		res %= mod;
	}
	if (res & 1) res += mod;
	res /= 2;
	cout << res << endl;
}