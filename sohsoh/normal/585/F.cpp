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

const ll MAXN = 50000 + 10;
const ll MAXD = 50;
const ll SIG = 10;
const ll MOD = 1e9 + 7;

int nxt[MAXN][SIG], sz, F[MAXN], d;
ll dp[MAXD][MAXN];
bool T[MAXN];
string s, x, y;

inline void addTrie(string s) {
	int v = 0;
	for (char c : s) {
		if (nxt[v][c - '0']) v = nxt[v][c - '0'];
		else v = nxt[v][c - '0'] = ++sz;
	}

	T[v] = true;
}

inline void buildAho() {
	queue<int> q;
	for (int i = 0; i < SIG; i++)
		if (nxt[0][i])
			q.push(nxt[0][i]);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		T[v] |= T[F[v]];

		for (int i = 0; i < SIG; i++) {
			if (nxt[v][i]) {
				F[nxt[v][i]] = nxt[F[v]][i];
				q.push(nxt[v][i]);
			} else nxt[v][i] = nxt[F[v]][i];
		}
	}

	for (int i = 0; i <= sz; i++)
		if (T[i])
			for (int j = 0; j < SIG; j++)
				nxt[i][j] = i;
}

inline bool AC(string s) {
	int v = 0;
	for (char c : s)
		v = nxt[v][c - '0'];
	return T[v];
}

inline ll calc(string s) {
	int v = 0, cnt = s.size();
	ll ans = 0;

	for (char c : s) {
		cnt--;
		for (int i = 0; i < (c - '0'); i++)
			ans += dp[cnt][nxt[v][i]];
		v = nxt[v][c - '0'];
	}

	return ans % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s >> x >> y;
	d = x.size();

	for (int i = 0; i < int(s.size()) - d / 2 + 1; i++) {
		string tmp;
		for (int j = i; j < i + d / 2; j++)
			tmp.push_back(s[j]);
		addTrie(tmp);
	}


	buildAho();
	for (int i = 0; i <= sz; i++)
		if (T[i])
			dp[0][i] = 1;

	for (int i = 1; i <= d; i++)
		for (int v = 0; v <= sz; v++)
			for (int j = 0; j < SIG; j++)
				dp[i][v] = (dp[i][v] + dp[i - 1][nxt[v][j]]) % MOD;

	cout << (calc(y) - calc(x) + AC(y) + MOD) % MOD << endl;
	return 0;
}