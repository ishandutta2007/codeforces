#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll SIG = 26;

int ind[MAXN], F[MAXN], T[MAXN], q_sz[MAXN],
    par[MAXN], nxt[MAXN][SIG], sz, n;
vector<int> oc[MAXN];
string s;

inline void addTrie(string& s, int x) {
	int v = 0;
	for (char c : s) {
		if (nxt[v][c - 'a']) v = nxt[v][c - 'a'];
		else v = nxt[v][c - 'a'] = ++sz;
	}

	ind[v] = x;
}

inline void buildAho() {
	queue<int> q;
	for (int i = 0; i < SIG; i++)
		if (nxt[0][i])
			q.push(nxt[0][i]);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		par[v] = (ind[F[v]] ? F[v] : par[F[v]]);
	
		for (int i = 0; i < SIG; i++) {
			if (nxt[v][i]) {
				q.push(nxt[v][i]);
				F[nxt[v][i]] = nxt[F[v]][i];
			} else nxt[v][i] = nxt[F[v]][i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> n;
	for (int i = 1; i <= n; i++) {
		string t;
		cin >> T[i] >> t;
		addTrie(t, i);
		q_sz[i] = t.size();
	}

	buildAho();
	int v = 0;
	for (int i = 0; i < int(s.size()); i++) {
		v = nxt[v][s[i] - 'a'];
		debug(i)

		int tv = v;
		while (tv) {
			oc[ind[tv]].push_back(i);
			tv = par[tv];
		}
	}

	for (int i = 1; i <= n; i++) {
		int ans = MAXN;
		for (int j = T[i] - 1; j < int(oc[i].size()); j++)
			ans = min(ans, oc[i][j] - oc[i][j - T[i] + 1]);

		cout << (ans == MAXN ? -1 : ans + q_sz[i]) << endl;
	}	
	return 0;
}