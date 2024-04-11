// orz ?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int A[MAXN], B[MAXN], C[MAXN], n;
vector<int> adj[MAXN];

void dfs(int v) {
	for (int u : adj[v]) {
		if (!C[u]) {
			C[u] = 3 - C[v];
			dfs(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i] >> B[i];
		adj[A[i]].push_back(B[i]);
		adj[B[i]].push_back(A[i]);
		adj[i << 1].push_back(i << 1 | 1);
		adj[i << 1 | 1].push_back(i << 1);
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (!C[i]) {
			C[i] = 1;
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << C[A[i]] << sep << C[B[i]] << endl;
	return 0;
}