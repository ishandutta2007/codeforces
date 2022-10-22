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

const ll MAXN = 8e5 + 10;

int C[MAXN][26], sz = 1, n;
ll ans = 0;
vector<int> V1[MAXN], V2[MAXN];
vector<pll> ans_v;

inline void Merge(vector<int>& a, vector<int>& b) {
	if (b.size() < a.size()) {
		for (int e : b)
		       a.push_back(e);
	} else {
		for (int e : a) 
			b.push_back(e);
		a.swap(b);	
	}

	b.clear();
}

inline void Insert(string s, int d, int ind) {
	int v = 1;
	for (char c : s) {
		c -= 'a';
		if (!C[v][int(c)]) C[v][int(c)] = ++sz;
		v = C[v][int(c)];
	}

	if (d > 0) V2[v].push_back(ind);
	else V1[v].push_back(ind);
}

inline void dfs(int v) {
	for (int u = 0; u < 26; u++) {
		if (C[v][u]) {
			dfs(C[v][u]);
			Merge(V1[v], V1[C[v][u]]);
			Merge(V2[v], V2[C[v][u]]);
		}
	}

	while (V1[v].size() && V2[v].size()) {
		ans_v.push_back({V1[v].back(), V2[v].back()});
		V1[v].pop_back();
		V2[v].pop_back();
	}
	
	ans -= V2[v].size();	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Insert(s, -1, i + 1);
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		Insert(s, 1, i + 1);
		ans += s.size();
	}
	
	vector<int> t = {1, 2, 3}, t2 = {3, 4};
	Merge(t, t2);
	dfs(1);
	cout << ans << endl;
	for (pll e : ans_v) cout << e.X << sep << e.Y << endl;
	return 0;
}