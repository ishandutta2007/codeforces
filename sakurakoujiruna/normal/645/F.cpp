#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e6 + 11;
using vi = vector <int>;
using ll = long long;
const ll Mod = (ll)1e9 + 7;

vi divs[N];
int p[N], phi[N];

ll fac[N], inv[N];
ll comb(ll n, ll m) {
	if(n < m) return 0;
	return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int cnt[N];

int main() {
	for(int i = 1; i < N; i ++)
		for(int j = i; j < N; j += i)
			divs[j].push_back(i);
	iota(p, p + N, 0);
	iota(phi, phi + N, 0);
	for(int i = 2; i < N; i ++) if(p[i] == i)
		for(int j = i; j < N; j += i) {
			p[j] = i;
			phi[j] -= phi[j] / i;
		}
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(int i = 2; i < N; i ++) {
		fac[i] = fac[i - 1] * i % Mod;
		inv[i] = inv[i - 1] * inv[i] % Mod;
	}

	ios :: sync_with_stdio(false);
	int n, k, q; cin >> n >> k >> q;

	ll sum = 0;
	auto solve = [&](int n) {
		for(int d : divs[n]) {
			sum += phi[d] * comb(cnt[d], k - 1);
			sum %= Mod;
		}
		for(int d : divs[n])
			cnt[d] ++;
	};
	while(n --) {
		int x; cin >> x;
		solve(x);
	}
	while(q --) {
		int x; cin >> x;
		solve(x);
		cout << sum << '\n';
	}
	return 0;
}