#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX / 2;

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int> > G(N);
	vector<int> d(N);
	while (M--) {
		int u, v; scanf("%d%d", &u, &v);
		u--, v--;
		G[v].pb(u);
		d[u]++;
	}
	priority_queue<int> q;
	rep(u, N) if (!d[u]) q.push(u);
	vector<int> label(N);
	rep(t, N) {
		int u = q.top(); q.pop();
		label[u] = N - t;
		for (int v: G[u]) {
			d[v]--;
			if (!d[v]) q.push(v);
		}
	}
	rep(u, N) printf("%d ", label[u]);
	cout << endl;
}