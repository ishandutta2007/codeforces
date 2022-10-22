#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int LOGN = 60;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector <ll> a;
	vector <int> cnt(LOGN, 0);
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (!x) continue;
		a.push_back(x);
		for (int j = 0; j < LOGN; j++) {
			if ((1LL << j) & x) {
				cnt[j]++;
			}
		}
	}
	n = a.size();
	for (int i = 0; i < LOGN; i++) {
		if (cnt[i] >= 3) {
			cout << "3\n";
			return 0;
		}
	}
	assert(n <= 3 * LOGN);
	int res = n + 1;
	vector <vector <bool> > gr(n, vector <bool> (n));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((a[i] & a[j]) != 0) {
				gr[i][j] = 1;
				gr[j][i] = 1;
			}
		}
	}
	for (int s = 0; s < n; s++) {
		vector <int> dist(n, n + 1);
		vector <int> pr(n, -1);
		dist[s] = 0;
		queue <int> q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int u = 0; u < n; u++) {
				if (dist[u] == n + 1 && gr[v][u]) {
					dist[u] = dist[v] + 1;
					pr[u] = v;
					q.push(u);
				}
			}
		}
		for (int v = 0; v < n; v++) {
			for (int u = 0; u < n; u++) {
				if (!gr[v][u] || pr[v] == u || pr[u] == v) continue;
				res = min(res, dist[v] + dist[u] + 1);
			}
		}
	}
	cout << (res == n + 1 ? -1 : res) << "\n";
}