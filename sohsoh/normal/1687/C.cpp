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

set<int> st;
vector<int> adj[MAXN];
ll L[MAXN], R[MAXN], D[MAXN], n, m;

inline int solve() {
	st.clear();
	for (int i = 0; i < max(n, m) + 10; i++) {
		adj[i].clear();
		L[i] = R[i] = D[i] = 0;
	}

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> D[i];
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		D[i] -= x;
		D[i] += D[i - 1];
	
		if (D[i]) st.insert(i);
	}

	queue<int> q;
	for (int i = 1; i <= m; i++) {
		cin >> L[i] >> R[i];
		adj[L[i]].push_back(i);
		adj[R[i]].push_back(i);

		if (D[L[i] - 1] == 0 && D[R[i]] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int ind = q.front();
		q.pop();

		int l = L[ind], r = R[ind];
		auto it = st.lower_bound(l);

		while (it != st.end() && *it <= r) {
			int x = *it;
			D[x] = 0;
			for (int e : adj[x])
				if (D[L[e] - 1] == 0 && D[R[e]] == 0)
					q.push(e);

			for (int e : adj[x + 1])
				if (D[L[e] - 1] == 0 && D[R[e]] == 0)
					q.push(e);
			it = st.erase(it);
		}
	}

	cout << (st.empty() ? "YES" : "NO") << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}