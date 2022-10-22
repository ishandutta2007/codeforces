// Sohsoh84 :)))
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll SQ = 350;

int n, m, q, ans[MAXN];
unordered_set<int> adj[MAXN];
vector<int> vec;
bool B[MAXN], online[MAXN];

inline void st_add(int v) {
	vec.push_back(v);
	B[v] = true;
	if (online[v])
		for (int u : adj[v])
			ans[u]--;
}

inline void add(int u, int v) {
	adj[u].insert(v);
	adj[v].insert(u);
	
	if (online[v] && !B[v]) ans[u]++;
	if (online[u] && !B[u]) ans[v]++;

	if (!B[v] && adj[v].size() >= SQ) st_add(v);
	if (!B[u] && adj[u].size() >= SQ) st_add(u);
}

inline void remove(int u, int v) {
	adj[v].erase(u);
	adj[u].erase(v);

	if (online[v] && !B[v]) ans[u]--;
	if (online[u] && !B[u]) ans[v]--;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;

	int o;
	cin >> o;
	while (o--) {
		int v;
		cin >> v;
		online[v] = true;
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		add(u, v);
	}

	while (q--) {
		char c;
		cin >> c;

		if (c == 'O') {
			int v;
			cin >> v;
			online[v] = true;

			if (!B[v]) 
				for (int u : adj[v])
					ans[u]++;
		} else if (c == 'F') {
			int v;
			cin >> v;
			online[v] = false;

			if (!B[v])
				for (int u : adj[v])
					ans[u]--;
		} else if (c == 'A') {
			int u, v;
			cin >> u >> v;
			add(u, v);
		} else if (c == 'D') {
			int u, v;
			cin >> u >> v;
			remove(u, v);
		} else {
			int v, b = 0;
			cin >> v; 

			for (int u : vec)
				if (online[u] && adj[v].find(u) != adj[v].end())
					b++;
			cout << ans[v] + b << endl;
		}
	}
	return 0;
}