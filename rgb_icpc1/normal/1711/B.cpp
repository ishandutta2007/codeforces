#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MX = 200005;

#define endl '\n'

int Tc, N, M, u[MX], v[MX], a[MX], sz[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i ++) cin >> a[i], sz[i] = 0;
		for (int i = 0; i < m; i ++) {
			cin >> u[i] >> v[i];
			sz[u[i]] ++;
			sz[v[i]] ++;
		}
		int rlt = 1000000;
		for (int i = 1; i <= n; i ++) if (sz[i] % 2 == 1) rlt = min(a[i], rlt);
		for (int i = 0; i < m; i ++) {
			if (sz[v[i]] % 2 == 0 && sz[u[i]] % 2 == 0) {
				rlt = min(rlt, a[u[i]] + a[v[i]]);
			} 
		}
		
		if (m % 2== 0) {
			cout << 0 << endl;
			continue;
		}
		else cout << rlt << endl;
	}
	return 0;
}