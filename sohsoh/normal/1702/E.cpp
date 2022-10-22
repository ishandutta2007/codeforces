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

int cnt[MAXN], n, col[MAXN];
bool flag;
vector<int> adj[MAXN];

void dfs(int v) {
	for (int u : adj[v]) {
		flag &= (col[u] != col[v]);
		if (!col[u]) {
			col[u] = 3 - col[v];
			dfs(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cnt[i] = col[i] = 0;
			adj[i].clear();
		}

		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			cnt[a]++;
			cnt[b]++;

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		flag = true;
		for (int i = 1; i <= n; i++)
			flag &= (cnt[i] == 2);


		for (int i = 1; i <= n; i++) {
			if (!col[i]) {
				col[i] = 1;
				dfs(i);
			}
		}

		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}