#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e7 + 11;
const int Mod = (int)1e9 + 7;

using ll = long long;

ll sum = 0;
int u[N];
int a[N], cnt[N];
int p[N], pow2[N];

map <int, int> mp;
void dfs(map <int, int> :: iterator it, int d, int acc) {
	if(it == mp.end()) {
		sum -= u[d] * pow2[cnt[d]];
		cnt[d] += acc;
		sum += u[d] * pow2[cnt[d]];
		sum %= Mod;
	} else {
		for(int i = 0; i <= it -> second; i ++) {
			dfs(next(it), d, acc);
			d *= it -> first;
		}
	}
}

void change(int n, int acc) {
	mp.clear();
	for(; n > 1; n /= p[n])
		mp[p[n]] ++;
	dfs(mp.begin(), 1, acc);
}

int main() {
	iota(p, p + N, 0); u[1] = 1;
	for(int i = 2; i < N; i ++) if(p[i] == i) {
		for(int j = i; j < N; j += i) p[j] = i;
	}
	for(int i = 2; i < N; i ++)
		if(p[i] == p[i / p[i]])
			u[i] = 0;
		else u[i] = -u[i / p[i]];
	pow2[0] = 1;
	for(int i = 1; i < N; i ++)
		pow2[i] = pow2[i - 1] * 2 % Mod;

	int n; scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	int acc = 0;
	for(int i = 0; i < n; i ++) {
		acc ++;
		if(i == n - 1 || a[i] != a[i + 1]) {
			change(a[i], acc);
			acc = 0;
		}
	}

	ll ans = 0; acc = 0;
	for(int i = 0; i < n; i ++) {
		acc ++;
		if(i == n - 1 || a[i] != a[i + 1]) {
			change(a[i], -1);

			vector <int> v;
			for(int t = a[i]; t > 1; t /= p[t]) {
				if(p[t] != p[t / p[t]])
					v.push_back(p[t]);
			}
			int m = v.size();

			ll tmp = (pow2[n - 1] - 1 - sum) % Mod;
			for(int k = 1; k < (1 << m); k ++) {
				int sgn = (__builtin_popcount(k) & 1) ? -1 : 1;
				int d = 1;
				for(int j = 0; j < m; j ++)
					if((k >> j) & 1) d *= v[j];
				tmp += sgn * (pow2[cnt[d]] - 1);
				tmp %= Mod;
			}
			ans += acc * tmp;
			ans %= Mod;

			change(a[i], 1);
			acc = 0;
		}
	}

	cout << (ans % Mod + Mod) % Mod << '\n';
	return 0;
}