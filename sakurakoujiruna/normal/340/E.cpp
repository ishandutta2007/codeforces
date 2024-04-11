#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll Mod = (ll)1e9 + 7;

const int N = 4011;
ll fac[N], inv[N];
int p[N];
bool v[N];

int main() {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(int i = 2; i < N; i ++) {
		fac[i] = fac[i - 1] * i % Mod;
		inv[i] = inv[i - 1] * inv[i] % Mod;
	}
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> p[i];
		v[p[i]] = true;
	}
	int a = 0, b = 0;
	for(int i = 1; i <= n; i ++) if(!v[i]) {
		if(p[i] != -1) a ++;
		else b ++;
	}
	ll ans = 0;
	for(int k = 0; k <= b; k ++) {
		int sgn = ((b - k) & 1) ? -1 : 1;
		ans += sgn * fac[a + k] * fac[b] % Mod *
			inv[k] % Mod * inv[b - k] % Mod;
		ans %= Mod;
	}
	cout << (ans + Mod) % Mod << '\n';
	return 0;
}