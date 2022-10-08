#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 100010
int n, m, k, l;
int a[105][N], b[N];
vector<int> A[N];
vector<int> B[105];
bool v[N];

int main() {
	cin >> n >> m >> k >> l;
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
		b[i] --;
		B[b[i]].pb(i);
	}
	for (int i = 0; i < m; i ++) {
		int x, y;
		cin >> x >> y;
		x --; y --;
		A[x].pb(y);
		A[y].pb(x);
	}
	for (int c = 0; c < k; c ++) {
		//puts ("WWW");
		queue<int> q;
		memset(v, 0, sizeof v);
		for (auto i : B[c]) {
			q.push(i);
			v[i] = true;
		}
		while (!q.empty()) {
			int x = q.front(); q.pop();
			//printf ("%d %d\n", x, a[c][x]);
			for (auto i : A[x]) 
				if (!v[i]) {
					q.push(i);
					a[c][i] = a[c][x] + 1;
					v[i] = true;
				}
		}
	}
	for (int i = 0; i < n; i ++) {
		vector<int> w;
		for (int c = 0; c < k; c ++)
			w.pb(a[c][i]);
		sort(w.begin(), w.end());
		int s = 0;
		for (int j = 0; j < l; j ++)
			s += w[j];
		printf ("%d%c", s, i == n-1?'\n':' ');
	}
	return 0;
}