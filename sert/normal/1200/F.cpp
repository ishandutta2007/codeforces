#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = (int)1e9 + 41;
const int MD = 2520;
const int N = 1000;

int getCode(int v, int k) {
	return v * MD + k;
}

int getV(int code) {
	return code / MD;
}

int nxt[N * MD];
int len[N * MD];
int num_path;
int step[N * MD];
int cycle_len;
vector<int> path;
int k[N];

void getLen(int v) {
	if (len[v] != -1) return;
	if (step[v] != -1) {
		set<int> s;
		for (int i = step[v]; i < num_path; i++) s.insert(getV(path[i]));
		len[v] = cycle_len = s.size();
		return;
	}	
	step[v] = num_path;

	if (v == nxt[v]) {
		len[v] = cycle_len = 1;
	} else {
		path.push_back(v);
		num_path++;
		getLen(nxt[v]);
		if (cycle_len == -1) len[v] = len[nxt[v]];
		else len[v] = cycle_len;
		num_path--;
	}
}

void solve() {
	for (int i = 0; i < N * MD; i++) {
		nxt[i] = -1;
		len[i] = -1;
		step[i] = -1;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		k[i] = (k[i] % MD + MD) % MD;
	}
	
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector<int> v(m);
		for (int j = 0; j < m; j++) {
			cin >> v[j];
			v[j]--;
		}
		for (int x = 0; x < MD; x++) {
			int y = (x + k[i]) % MD;
			int code = getCode(i, x);
			nxt[code] = getCode(v[y % m], y);			
		}
	}

	for (int i = 0; i < n * MD; i++) {
		cycle_len = -1;
		num_path = 0;
		path.clear();
		getLen(i);
	}

	int q;
	cin >> q;
	while (q--) {
		int v, k;
		cin >> v >> k;
		k = (k % MD + MD) % MD;

		cout << len[getCode(v - 1, k)] << "\n";
	}
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}