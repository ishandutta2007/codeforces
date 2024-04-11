#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
    return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
    o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

const int MAXN = 103;
int p[MAXN];
bool path[MAXN];
vector<int> v[MAXN];

int mx, who, k;

void dfs(int x, int poz) {
	if (poz >= k)
		return;
	if (poz > mx) {
		mx = poz;
		who = x;
	}
	for (auto it:v[x])
		dfs(it, poz + 1);
}

void dfs2(int x, bool on_path) {
	cout << x << ' ';
	if (!on_path) {
		k--;
		if (k == 0)
			return;
	}
	for (auto it:v[x]) {
		if (!path[it] && k != 0) {
			dfs2(it, false);
			cout << x << ' ';
		}
	}
	for (auto it:v[x]) {
		if (path[it])
			dfs2(it, true);
	}
}

void solve() {
	int n;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		v[p[i]].emplace_back(i);
	}

	mx = who = -1;
	dfs(1, 0);

	cout << 2 * (k - 1) - mx << '\n';
	while (who != 1) {
		path[who] = true;
		who = p[who];
	}
	path[1] = true;
	k -= mx + 1;

	dfs2(1, true);
	cout << '\n';

	for (int i = 1; i <= n; i++) {
		path[i] = false;
		v[i].clear();
	}
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int z;
    cin >> z;
    while (z--) {
    	solve();
    }
    return 0;
}