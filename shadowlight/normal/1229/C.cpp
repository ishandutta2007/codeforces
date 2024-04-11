#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2e5 + 7;
const int SQ = sqrt(N);

vector <vector <pair <int, int> > > ing, outg;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	ing.resize(n);
	outg.resize(n);

	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		if (v < u) swap(v, u);
		outg[v].push_back({u, ing[u].size()});
		ing[u].push_back({v, outg[v].size() - 1});
	}
	ll res = 0;
	for (int v = 0; v < n; v++) {
		res += ing[v].size() * (ll) outg[v].size();
	}
	cout << res << "\n";

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int v;
		cin >> v;
		v--;
		res -= ing[v].size() * (ll) outg[v].size();
		for (int i = 0; i < (int) ing[v].size(); i++) {
			auto e = ing[v][i];
			int u = e.first, id = e.second;
			res -= ing[u].size() * (ll) outg[u].size();
			//assert(outg[u].size());
			auto e1 = outg[u].back();
			if (id != (int) outg[u].size() - 1) {
				swap(outg[u].back(), outg[u][id]);
				ing[e1.first][e1.second].second = id; 
			}
			outg[u].pop_back(); 
			outg[v].push_back({u, ing[u].size()});
			ing[u].push_back({v, outg[v].size() - 1});
			res += ing[u].size() * (ll) outg[u].size();
		}
		ing[v].clear();
		cout << res << "\n";
	}

}