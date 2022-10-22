#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int n;
	cin >> n;

	ll sum = 0;

	vector <pair <int, int>> w(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i].x;
		sum += w[i].x;
		w[i].y = i;
	}
	sort(all(w));

	vector <int> deg(n, 0);
	for (int i = 1; i < n; ++i) {
		int v, u;
		cin >> v >> u;
		--v, --u;
		deg[v]++;
		deg[u]++;
	}

	cout << sum << " ";
	while (w.size()) {
		if (deg[w.back().y] == 1) {
			w.pop_back();
		} else {
			--deg[w.back().y];
			sum += w.back().x;
			cout << sum << " ";
		}
	}
	cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		solve();
	}

}