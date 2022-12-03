#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> i_i;

void dfs(int u, vector<vector<int> >& G, vector<int>& h) {
	for (int v: G[u]) dfs(v, G, h), h[u] = max(h[u], h[v] + 1);
}

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) scanf("%d", &a[i]);
	vector<vector<int> > G(N);
	for (int u = 1; u < N; u++) {
		int p; scanf("%d", &p), p--;
		G[p].pb(u);
	}
	vector<int> h(N);
	dfs(0, G, h);
	int E = 0, O = 0, x = 0;
	map<int, int> even, odd;
	rep(u, N)
		if (h[u] % 2 == 0) E++, x ^= a[u], even[a[u]]++;
		else O++, odd[a[u]]++;
	ll ans = 0;
	for (i_i yk: even) {
		int y = yk.first, k = yk.second;
		ans += (ll)k * odd[y ^ x];
	}
	if (!x) ans += (ll)E * (E - 1) / 2 + (ll)O * (O - 1) / 2;
	cout << ans << endl;
}