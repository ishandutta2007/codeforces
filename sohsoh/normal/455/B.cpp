// \_()_/
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

const ll MAXN = 1e5 + 10;

bool dp_w[MAXN], dp_l[MAXN];
int C[MAXN][26], sz = 1, n, k;

inline void Insert(string s) {
	int v = 1;
	for (char c : s) {
		int t = c - 'a';
		if (!C[v][t]) C[v][t] = ++sz;
		v = C[v][t];	
	}
}

void dfs(int v) {
	bool c = true;
	for (int i = 0; i < 26; i++) {
		if (C[v][i]) {
			dfs(C[v][i]);
			c = false;
			dp_w[v] |= !dp_w[C[v][i]];
			dp_l[v] |= !dp_l[C[v][i]];
		}
	}

	dp_l[v] |= c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	while (n--) {
		string s;
		cin >> s;
		Insert(s);
	}
	
	dfs(1);
	if (dp_w[1] && dp_l[1]) return cout << "First" << endl, 0;
	if (!dp_w[1]) return cout << "Second" << endl, 0;
	cout << (k & 1 ? "First" : "Second") << endl;
	return 0;
}