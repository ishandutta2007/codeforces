#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define pii pair<int, int>
vector<vector<int>> adj(maxn);
vector<vector<int>> into(maxn);

bool ostop[maxn];

int wafter[maxn];
int lafter[maxn];

bool vis[maxn];
bool instack[maxn];
bool cyc = false;
int sc;

void dfs(int u) {
	vis[u] = true;
	instack[u] = true;
	if (cyc) return;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (instack[v]) {
			cyc = true;
			return;
		}
		if (!vis[v]) dfs(v);
	}
	instack[u] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	fill(ostop, ostop+maxn, false);
	fill(wafter, wafter+maxn, -1);
	fill(lafter, lafter+maxn, -1);
	fill(instack, instack+maxn, false);
	queue<pii> events;
	for (int i = 1 ; i <= n; i++) {

		int c;
		cin >> c;
		if (c == 0) {
			events.push(pii(i, 1));
			ostop[i] = true;
		}
		int cur;
		for (int j = 0; j < c; j++) {
			cin >> cur;
			adj[i].push_back(cur);
			into[cur].push_back(i);
		}
	}
	while (events.size() > 0) {
		pii cur = events.front(); events.pop();
		int v = cur.first;
		int tp = cur.second;
		if (tp == 1) {
			for (int i = 0; i < into[v].size(); i++) {
				int u = into[v][i];
				if (wafter[u] == -1) {
					wafter[u] = v;
					events.push(pii(u, 2));
				}
			}
		}
		else if (tp == 2) {
			for (int i = 0; i < into[v].size(); i++) {
				int u = into[v][i];
				
				if (lafter[u] == -1) {
					events.push(pii(u, 1));
					lafter[u] = v;
				}
			}
		}
	}
	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " \t " << wafter[i] << " \t " << lafter[i] << endl;
	// }
	int s;
	cin >> s;
	if (wafter[s] != -1) {
		cout << "Win" << endl;
		int cur = s;
		int tp = 0;
		while (!ostop[cur]) {
			cout << cur << " ";
			if (tp%2 == 0) {
				cur = wafter[cur];
			}
			else cur = lafter[cur];
			tp++;
		}
		cout << cur << endl;
	}
	else {
		sc = s;
		dfs(s);
		if (cyc) cout << "Draw" << endl;
		else cout << "Lose" << endl;
	}

	cin >> s;
}