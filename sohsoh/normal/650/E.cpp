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

int n, deg[MAXN], par[MAXN], from[MAXN], to[MAXN];
vector<int> T[MAXN];
vector<int> C[MAXN];
set<pll> st;
stack<int> deg1;
bool vis[MAXN];

inline int g(int ind, int v) {
	return from[ind] ^ to[ind] ^ v;
}

inline void f(vector<int>& vec) {
	while (!vec.empty() && (par[from[vec.back()]] == par[to[vec.back()]] || vis[vec.back()]))
		vec.pop_back();
}

inline bool unite(int u, int v) {
	if (par[v] == par[u]) return false;
	v = par[v], u = par[u];
	if (C[v].size() > C[u].size()) swap(v, u);
	
	deg[u] += deg[v];
	deg[v] = 0;
	for (int ind : T[v]) {
		if (!vis[ind] && ((par[from[ind]] == v && par[to[ind]] == u) || (par[from[ind]] == u && par[to[ind]] == v)))
			deg[u] -= 2;
		
		T[u].push_back(ind);
	}

	for (int e : C[v]) {
		par[e] = u;
		C[u].push_back(e);
	}

	if (u <= n && deg[u] == 1) deg1.push(u);
	C[v].clear();
	T[v].clear();
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < 2 * n + 5; i++) {
		C[i].push_back(i);
		par[i] = i;
	}

	for (int i = 1; i < n; i++) {
		cin >> from[i] >> to[i];
		T[from[i]].push_back(i);
		T[to[i]].push_back(i);
		deg[from[i]]++;
		deg[to[i]]++;

		st.insert({from[i], to[i]});
	}

	for (int i = 1; i <= n; i++)
		if (deg[i] == 1)
			deg1.push(i);

	vector<int> vec;
	for (int i = n; i < 2 * n - 1; i++) {
		cin >> from[i] >> to[i];

		if (st.find(pll(from[i], to[i])) != st.end() || st.find(pll(to[i], from[i])) != st.end())
			vec.push_back(i);

		from[i] += n;
		to[i] += n;
		T[from[i]].push_back(i);
		T[to[i]].push_back(i);
	}

	for (int ind : vec) {
		unite(from[ind], to[ind]);
		unite(from[ind] - n, to[ind] - n);
	}

	cout << n - 1 - int(vec.size()) << endl;
	while (!deg1.empty()) {
		int v = deg1.top();
		deg1.pop();
		if (deg[v] != 1) continue;

		f(T[v]);
		int a = from[T[v].back()], b = to[T[v].back()];
		
		if (deg[par[a]] != 1) swap(a, b);
		vis[T[v].back()] = true;
		deg[par[a]]--;
		deg[par[b]]--;

		int u = par[a + n];
		f(T[u]);

		int c = from[T[u].back()] - n, d = to[T[u].back()] - n;
		unite(c, d);
		unite(c + n, d + n);

		cout << a << sep << b << sep << c << sep << d << endl;
		
		deg1.push(par[a]);
		deg1.push(par[b]);
	}
	return 0;
}