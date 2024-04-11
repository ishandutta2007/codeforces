#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll SIG = 26;

int n, I[MAXN], ans, nxt[MAXN][SIG], sz, F[MAXN],
    T[MAXN], tin[MAXN], tout[MAXN], t, L[MAXN], L2[MAXN], cnt[MAXN];
vector<int> adj[MAXN];
string S[MAXN];

inline int addTrie(string& s) {
	int v = 0;
	for (char c : s) {
		if (nxt[v][c - 'a']) v = nxt[v][c - 'a'];
		else v = nxt[v][c - 'a'] = ++sz;
	}

	return v;
}

inline void buildAho() {
	queue<int> q;
	for (int i = 0; i < SIG; i++)
		if (nxt[0][i])
			q.push(nxt[0][i]);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		adj[F[v]].push_back(v);

		for (int i = 0; i < SIG; i++) {
			if (nxt[v][i]) {
				F[nxt[v][i]] = nxt[F[v]][i];
				q.push(nxt[v][i]);
			} else nxt[v][i] = nxt[F[v]][i];
		}
	}
}

void dfs(int v, int lst) {
	tin[v] = ++t;

	L2[v] = lst;
	if (T[v]) lst = v;
	L[v] = lst;

	for (int u : adj[v])
		dfs(u, lst);

	tout[v] = t;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
		I[i] = addTrie(S[i]);
		T[I[i]] = i;
	}

	buildAho();
	dfs(0, 0);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		map<int, int> mp;
		vector<pll> vec;
		vector<int> tin_vec;

		int v = 0, r = 0;
		for (char c : S[i]) {
			r++;
			v = nxt[v][c - 'a'];
			tin_vec.push_back(tin[v]);

			int par = 0;
			if (L[v] == I[i] && L2[v]) par = L2[v]; //
			else if (L[v] && L[v] != I[i]) par = L[v];
			else continue;

			par = T[par];	
			
			int l = r - int(S[par].size()) + 1;
			while (!vec.empty() && l <= vec.back().Y) cnt[vec.back().X]--, vec.pop_back();
			vec.push_back({I[par], l});
			cnt[I[par]]++;
		} 

		sort(all(vec));
		sort(all(tin_vec));
		for (int i = 0; i < int(vec.size()); i++) {
			if (i && vec[i - 1].X == vec[i].X) continue;
		
			int v = vec[i].X;
		//	debug(T[v])
			if (upper_bound(all(tin_vec), tout[vec[i].X]) - lower_bound(all(tin_vec), tin[vec[i].X]) == cnt[vec[i].X])
				ans++;
			cnt[vec[i].X] = 0;
		}
	}

	cout << ans << endl;
	return 0;
}