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

bool dfs(int v, int pr, int depth, const vector<vector<int>> &es) {
	if (depth == 0) return ((int)es[v].size() == 1);
	if ((int)es[v].size() + (int)(pr == -1) < 4) return false;
	for (int w: es[v]) {
		if (w == pr) continue;
		if (!dfs(w, v, depth - 1, es)) return false;
	}
	return true;
}

void solve() {
	int n, dd;
	cin >> n >> dd;
	vector<vector<int>> es(n);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	int lst = 0;
	vector<int> d(n, -1), pr(n, -1);
	for (int iq = 0; iq < 2; iq++) {
		queue<int> q;
		for (int i = 0; i < n; i++) {
			d[i] = pr[i] = -1;
		}
		d[lst] = 0;
		q.push(lst);
		while (!q.empty()) {
			lst = q.front();
			q.pop();
			for (int v: es[lst]) {
				if (d[v] == -1) {
					d[v] = d[lst] + 1;
					pr[v] = lst;
					q.push(v);
				}
			}
		}
	}

	int v = lst;
	if (d[v] % 2 == 1) {
		cout << "No\n";
		return;
	}

	int depth = d[v] / 2;
	for (int i = 0; i < depth; i++) {
		v = pr[v];
	}

	if (dfs(v, -1, depth, es) && depth == dd) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}