#include <bits/stdc++.h>

using namespace std;
const int N = 6e5 + 5;
int a[N], b[N];
map<int, int> mp;
vector<int> g[N];

const int mod = 998244353;

long long inv[N];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[N], ifac[N];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

long long C(int n, int m) { return n < m ? 0 : fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		mp[a[i]], mp[b[i]];
	}
	int cnt = 0;
	for (auto &i: mp) i.second = ++cnt;
	for (int i = 1; i <= n; ++i) a[i] = mp[a[i]], b[i] = mp[b[i]], g[a[i]].push_back(i);
	priority_queue<int, vector<int>, greater<int>> q;
	long long ans = 0;
	for (int i = 1; i <= cnt; ++i) {
		while (!q.empty() && q.top() < i) q.pop();
		for (int j: g[i]) {
			ans = (ans + C((int) q.size(), k - 1)) % mod;
			q.push(b[j]);
		}
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	invWork();
	facWork();
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}