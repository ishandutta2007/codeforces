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

vector<string> vec;
int n, m, T[MAXN];
set<int> poss[MAXN];
string M[MAXN];

inline bool bad(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

inline bool fuck(string& a, string& b) {
	int n = a.size(), m = b.size();
	for (int i = 0; i < n - m + 1; i++) {
		bool flag = true;
		if (i > 0 && bad(a[i - 1])) continue;
		if (i < n - m && bad(a[i + m])) continue;

		for (int j = i; j < i + m; j++) {
			if (a[j] != b[j - i]) {
				flag = false;
				break;
			}
		}
		
		if (flag) return true;
	}

	return false;
}

void dfs(int v) {
	T[v] = *poss[v].begin();
	if (v < m - 1) {
		poss[v + 1].erase(T[v]);
		if (T[v + 1] < 0 && poss[v + 1].size() == 1)
			dfs(v + 1);
	} 

	if (v) {
		poss[v - 1].erase(T[v]);
		if (T[v - 1] < 0 && poss[v - 1].size() == 1)
			dfs(v - 1);
	}
}

inline int solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vec.push_back(s);
	}

	cin >> m;
	string tmp;
	getline(cin, tmp);
	for (int i = 0; i < m; i++) {
		string s;
		getline(cin, s);

		string username, message;
		int ind = -1;
		for (int i = 0; i < int(s.size()); i++) {
			if (s[i] == ':') {
				ind = i;
				break;
			}
		}

		username = s.substr(0, ind);
		message = s.substr(ind + 1);
		T[i] = -1;

		if (username == "?") {
			for (int j = 0; j < n; j++)
				poss[i].insert(j);
		} else {
			int ind = find(all(vec), username) - vec.begin();
			poss[i].insert(ind);
		}

		for (int j = 0; j < n; j++)
			if (fuck(message, vec[j]))
				poss[i].erase(j);
		M[i] = message;
	}

	for (int i = 0; i < m; i++) {
		if (T[i] < 0 && poss[i].size() == 1)
			dfs(i);
	}

	for (int i = 0; i < m; i++) {
		if (poss[i].size() == 0) return cout << "Impossible" << endl, 0;
		T[i] = *poss[i].begin();
		poss[i + 1].erase(T[i]);
		if (i && T[i] == T[i - 1]) return cout << "Impossible" << endl, 0;
	}

	for (int i = 0; i < m; i++) {
		cout << vec[T[i]] << ":" << M[i] << endl;
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		vec.clear();
		for (int i = 0; i < max(n, m) + 10; i++) {
			poss[i].clear();
			M[i].clear();
			T[i] = -1;
		}

		solve();
	}
	return 0;
}