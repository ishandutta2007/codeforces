#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

vector<int> es[N];
bool ua[N], ub[N];
int tme;
int tin[N], tout[N], pr[N];

void dfs(int v, int p = -1) {
	tin[v] = ++tme;
	pr[v] = p;
	for (int w: es[v]) {
		if (w == p) continue;
		dfs(w, v);
	}
	tout[v] = ++tme;
}

bool isPar(int p, int v) {
	return (tin[p] < tin[v] && tout[p] > tout[v]);
}

int getNum(int v, char type) {
	cout << type << " " << v + 1 << endl;
	int x;
	cin >> x;
	return x - 1;
}

void solve() {
	int n;
	tme = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		es[i].clear();
		ua[i] = ub[i] = false;
		tin[i] = tout[i] = pr[i] = -1;
	}

	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	dfs(0);

	int sz1, top = -1;
	cin >> sz1;
	for (int i = 0; i < sz1; i++) {
		int x;
		cin >> x;
		x--;
		ua[x] = true;
		if (top == -1 || tin[x] < tin[top]) top = x;
	}

	int sz2;
	cin >> sz2;
	int v;
	for (int i = 0; i < sz2; i++) {
		cin >> v;
		v--;
		ub[v] = true;
	}

	int heTop = getNum(top, 'A');
	if (ub[heTop]) {
		cout << "C " << top + 1 << endl;
		return;
	}

	int w = getNum(v, 'B');
	if (!isPar(top, w)) {
		cout << "C -1" << endl;
		return;
	}

	while (w != -1 && !ua[w]) {
		w = pr[w];
	}

	if (w == -1) {
		cout << "C -1" << endl;
		return;
	}

	int kk = getNum(w, 'A');
	if (ub[kk]) cout << "C " << w + 1 << endl;
	else cout << "C -1" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	//tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}