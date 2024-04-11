#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

const int MX = 200005;

int f[MX], g[MX], rlt[MX];

#define MOD 998244353

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	int sum = 0, step = 0;
	for (step = 0; ; step ++) {
		sum += (k + step);
		if (sum >= n) break;
	}
	f[0] = 1;
	for (int i = 0; i <= step; i ++) {
		for (int j = 0; j <= n; j ++) {
			if (j - (k + i) >= 0) (g[j] += f[j - (k + i)] + g[j - (k + i)]) %= MOD;
		}
		for (int j = 0; j <= n; j ++) f[j] = g[j], g[j] = 0;
		for (int j = 0; j <= n; j ++) (rlt[j] += f[j]) %= MOD;
	}
	for (int i = 1; i <= n; i ++) cout << rlt[i] << ' ';cout << endl;
	
	
}