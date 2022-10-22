#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
const int N = 1007;
 
int n;
vector <vector <int> > gr;
 
vector <bool> used;
int col[N];
int sz[N];
int pr[N];
 
int nowc = 0;
 
void dfs(int v, int p) {
	sz[v] = 1;
	pr[v] = p;
	col[v] = nowc;
	for (int u : gr[v]) {
		if (used[u] || u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
}
 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	gr.resize(n);
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].pb(u);
		gr[u].pb(v);
	}
	used.resize(n, false);
 
	int c = 0;
 
	while (true) {
		nowc++;
		dfs(c, -1);
		int all_sz = sz[c];
		if (all_sz == 1) {
			cout << "! " << c + 1 << endl;
			return 0;
		}
		int v = -1;
		for (int i = 0; i < n; i++) {
			if (col[i] != nowc) continue;
			int a = sz[i], b = all_sz - a;
			if (a >= 2 && b >= 2) {
				v = i;
				break;
			}
		}
		if (v == -1) {
			vector <int> tet;
			int root = c;
			for (int i = 0; i < n; i++) {
				if (col[i] != nowc || i == c) continue;
				if (sz[i] != 1) {
					root = i;
				} else {
					tet.pb(i);
				}
			}
			if (root != c) {
				tet.push_back(c);
			}
			for (int i = 0; i < (int) tet.size() - 1; i += 2) {
				cout << "? " << tet[i] + 1 << " " << tet[i + 1] + 1 << endl;
				int x;
				cin >> x;
				x--;
				if (x != root) {
					cout << "! " << x + 1 << endl;
					return 0;
				}
			}
			if (tet.size() % 2) {
				cout << "? " << tet.back() + 1 << " " << root + 1 << endl;
				int x;
				cin >> x;
				cout << "! " << x << endl;
				return 0;
			} else {
				cout << "! " << root + 1 << endl;
				return 0;
			}
		}
		assert(v != c);
		cout << "? " << v + 1 << " " << pr[v] + 1 << endl;
		int x;
		cin >> x;
		x--;
		if (x == v) {
			used[pr[v]] = true;
			c = v;
		} else {
			used[v] = true;
			c = pr[v];
		}
 
	}
 
}