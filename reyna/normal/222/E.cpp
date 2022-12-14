//In the name of God
// Break through! I screamed through my soul!

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int ind[256], nx, adj[52][52], cur[52][52], c[52][52];

void mul(int a[52][52], int b[52][52]) {
	memset(c, 0, sizeof c);
	for (int i = 0; i < 52; i++)
		for (int k = 0; k < 52; k++) if (a[i][k])
			for (int j = 0; j < 52; j++)
				c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % mod;
	memcpy(a, c, sizeof c);
}

void pw(long long base) {
	if (base == 0) return;
	pw(base >> 1);
	mul(cur, cur);
	if (base & 1)
		mul(cur, adj);
}

int main() {
	long long n;
	int m, k;
	cin >> n >> m >> k;
	if (n == 1) {
		cout << m << endl;
		return 0;	
	}
	for (int i = 'a'; i <= 'z'; i++)
		ind[i] = nx++;
	for (int i = 'A'; i <= 'Z'; i++)
		ind[i] = nx++;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			adj[i][j] = 1;
	for (int i = 0; i < k; i++) {
		char u, v; cin >> u >> v;
		adj[ind[u]][ind[v]] = 0;	
	}
	for (int i = 0; i < m; i++)
		cur[i][i] = 1;
	pw(n - 1);
	int res = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			res = (res + cur[i][j]) % mod;
	cout << res << endl;
	return 0;
}