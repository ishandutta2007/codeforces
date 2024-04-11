#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
const int Mod = (int)1e9 + 7;

int f[N], g[N];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		if(i & 1)
			f[i] = 1 + g[i - 1];
		else
			g[i] = 1 + f[i - 1];
		f[i] = (f[i - 1] + f[i]) % Mod;
		g[i] = (g[i - 1] + g[i]) % Mod;
	}
	cout << (f[n] + g[n]) % Mod << '\n';
	return 0;
}