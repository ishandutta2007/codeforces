#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const ll INF = LLONG_MAX / 10;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

int main() {
	int N; cin >> N;
	vector<vector<int>> G(N);
	for (int u = 1; u < N; u++) {
		int p; cin >> p; p--;
		G[p].pb(u);
	}
	vector<bool> leaf(N);
	rep(u, N) leaf[u] = G[u].empty();
	rep(u, N) if (!leaf[u]) {
		int cnt = 0;
		for (int v: G[u]) if (leaf[v]) cnt++;
		if (cnt < 3) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}