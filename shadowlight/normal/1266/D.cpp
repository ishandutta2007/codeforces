#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Edge {
	ll v, u, d;
};

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector <ll> sum(n, 0);
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> v >> u >> d;
		v--, u--;
		sum[v] += d;
		sum[u] -= d;
	}
	vector <int> good, bad;
	for (int i = 0; i < n; i++) {
		if (sum[i] > 0) {
			good.push_back(i);
		} else if (sum[i] < 0) {
			bad.push_back(i);
		}
	}
	vector <Edge> res;
	for (int v : good) {
		while (sum[v] > 0) {
			int u = bad.back();
			res.push_back({v, u, min(sum[v], -sum[u])});
			if (sum[v] >= abs(sum[u])) {
				sum[v] += sum[u];
				sum[u] = 0;
				bad.pop_back();
			} else {
				sum[u] += sum[v];
				sum[v] = 0;
			}
		}
	}
	cout << res.size() << "\n";
	for (auto e : res) {
		cout << e.v + 1 << " " << e.u + 1 << " " << e.d << "\n"; 
	}
}