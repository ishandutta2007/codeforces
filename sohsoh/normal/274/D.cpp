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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, t, C[MAXN];
vector<int> adj[MAXN];
vector<pll> T;
stack<int> st;

void dfs(int v) {
	C[v] = 1;
	for (int u : adj[v]) {
		if (C[u] == 0) dfs(u);
		else if (C[u] == 1) {
			cout << -1 << endl;
			exit(0);
		}
	}

	C[v] = 2;
	st.push(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	t = m;

	for (int i = 0; i < n; i++) {
		T.clear();
		t++;
		for (int j = 1; j <= m; j++) {
			int x;
			cin >> x;
			if (x < 0) continue;
			T.push_back({x, j});
		}

		sort(all(T));
		for (int i = 0; i < T.size(); i++) {
			if (i == 0 || T[i].X != T[i - 1].X) {
				for (int j = i; j < T.size(); j++) {
					adj[t].push_back(T[j].Y);
					if (j < T.size() && T[j].X != T[j + 1].X) break;
				}
			}	
					
			if (i == T.size() || T[i].X != T[i + 1].X) {
				t++;
				for (int j = i; j >= 0; j--) {
					adj[T[j].Y].push_back(t);
					if (j > 0 && T[j].X != T[j - 1].X) break;
				}
			}
		}
	}

	for (int i = 1; i <= t; i++) 
		if (C[i] == 0)
			dfs(i);
	while (!st.empty()) {
		int v = st.top();
		st.pop();
		if (v <= m) cout << v << sep;
	}

	cout << endl;
	return 0;
}