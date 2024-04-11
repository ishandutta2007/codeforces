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

const ll MAXN = 750 + 10;
const ll MAXC = 1e7 + 10;
const ll SIG = 2;

// d2, try

int n, nxt[MAXC][SIG], F[MAXC], sz, R[MAXC], t, match[MAXN << 1], G[MAXC];
vector<int> E[MAXN << 1];
string S[MAXN];
bool mark[MAXN << 1], M[MAXN][MAXN];


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
		if (nxt[0][i]) q.push(nxt[0][i]);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (!G[v]) G[v] = G[F[v]];

		for (int i = 0; i < SIG; i++) {
			if (nxt[v][i]) {
				F[nxt[v][i]] = nxt[F[v]][i];
				q.push(nxt[v][i]);
			} else nxt[v][i] = nxt[F[v]][i];
		}
	}
}

bool try_kuhn(int u){
	mark[u] = true;
	for (auto v : E[u]) {
		if (!match[v] || (!mark[match[v]] && try_kuhn(match[v]))) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}

	return false;
}

inline void antichain() {
	int k = 0;
	for (int u = 1; u <= n; u++) {
		memset(mark, false, sizeof mark);
		k += try_kuhn(u);
	}

	cout << n - k << endl;
	vector<deque<int>> C;

	for (int v = 1; v <= n; v++) {
		if (!match[v + n]) {
			int u = v;
			C.push_back({u});
			while (match[u]) {
				u = match[u] - n;
				C.back().push_back(u);
			}	
		}
	}


	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < (int) C.size(); i++) {
			for (int j = 0; j < (int) C.size(); j++) {
				if (M[C[i].front()][C[j].front()]) {
					C[i].pop_front();
					flag = true;
				}
			}
		}
	}

	for (int i = 0; i < (int) C.size(); i++)
		cout << C[i].front() << sep;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> S[i];
		int x = addTrie(S[i]);
		R[x] = i;
		G[x] = x;
	}

	buildAho();

	for (int i = 1; i <= n; i++) {
		int v = 0;
		for (char c : S[i]) {
			v = nxt[v][c - 'a'];
			
			int u = v;
			while (G[u]) {
				int t = G[u];
				if (M[R[t]][i]) break;
				if (R[t] != i) {
					E[R[t]].push_back(i + n);
					E[i + n].push_back(R[t]);
					M[R[t]][i] = true;
				}	

				u = F[t];
			}
		}
	}

	antichain();
	return 0; 
}