#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int LOGN = 30;

int n;
vector <ll> a;
vector <vector <int> > gr;
vector <vector <int> > binup;
vector <vector <ll> > g;

void dfs(int v, int p) {
	binup[v][0] = p;
	if (p != -1) {
		g[v][0] = a[p];
	}
	for (int i = 1; i < LOGN; i++) {
		if (binup[v][i - 1] == -1) break;
		binup[v][i] = binup[binup[v][i - 1]][i - 1];
		g[v][i] = __gcd(g[binup[v][i - 1]][i - 1], g[v][i - 1]);
	}
	for (int u : gr[v]) {
		if (u == p) continue;
		dfs(u, v);
	}
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);;
	cin >> n;
	a.resize(n);
	gr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		gr[v].push_back(u);
		gr[u].push_back(v);
	}

	binup.resize(n, vector <int> (LOGN, -1));
	g.resize(n, vector <ll> (LOGN, 0));
	dfs(0, -1);


	ll res = 0;

	for (int vv = 0; vv < n; vv++) {
		ll now = a[vv];
		int v = vv;
		while (true) {
			int cnt = 1;
			for (int i = LOGN - 1; i >= 0; i--) {
				if (binup[v][i] == -1) continue;
				if (__gcd(g[v][i], now) != now) continue;
				cnt += (1 << i);
				v = binup[v][i];
			}
			res = (res + cnt * now) % (int) (1e9 + 7);
			//cout << vv << " " << now << " " << cnt << "\n";
			if (v == 0) break;
			v = binup[v][0];
			now = __gcd(now, a[v]);
		}
	}
	cout << res << "\n";

}