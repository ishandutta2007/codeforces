#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("J_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <pair <int, int> > edges;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		edges.push_back({v, u});
	}
	int res = 0;
	vector <int> now(n, 0);
	while (true) {
		vector <vector <int> > used(6, vector <int> (6, 0));
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			int a = now[edges[i].first], b = now[edges[i].second];
			if (a > b) swap(a, b);
			if (!used[a][b]) {
				used[a][b] = true;
				cnt++;
			}
		}
		res = max(res, cnt);
		int pos = n - 1;
		now[pos]++;
		while (pos >= 0 && now[pos] == 6) {
			if (pos) {
				now[pos - 1]++;
			}
			now[pos--] = 0;
		}
		if (pos == -1) {
			break;
		}
	}
	cout << res << "\n";
}