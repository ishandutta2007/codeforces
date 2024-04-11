#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;
int n, m;

const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 5;
const int N = 4e5 + 7;

int paths_1[2][N], paths_2[2][N];

vector <int> get_dist(vector <vector <int> > &gr, int s, bool inv = false) {
	vector <int> d(n, INF);
	d[s] = 0;
	paths_1[inv][s] = 1;
	paths_2[inv][s] = 1;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		//cout << v << " " << d[v] << "\n";
		for (int u : gr[v]) {
			if (d[u] == INF) {
				d[u] = d[v] + 1;
				q.push(u);
			}
			if (d[u] == d[v] + 1) {
				paths_1[inv][u] = (paths_1[inv][u] + paths_1[inv][v]) % MOD1;
				paths_2[inv][u] = (paths_2[inv][u] + paths_2[inv][v]) % MOD2;
			}
		}
	}
	//cout << "===\n";
	return d;
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector <vector <int> > gr(n), rgr(n);

	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].pb(u);
		rgr[u].pb(v);
	}

	int k;
	cin >> k;
	vector <int> path(k);

	for (int i = 0; i < k; i++) {
		cin >> path[i];
		path[i]--;
	}

	int s = path[0], t = path.back();

	auto dt = get_dist(rgr, t);

	int cnt = 0, added = 0;
	for (int i = 0; i < k - 1; i++) {
		int v = path[i], u = path[i + 1];
		if (dt[u] + 1 != dt[v]) {
			cnt++;
		} else {
			for (int w : gr[v]) {
				if (dt[w] == dt[u] && w != u) {
					added++;
					break;
				}
			}
		}
	}

	cout << cnt << " " << cnt + added << "\n";

}