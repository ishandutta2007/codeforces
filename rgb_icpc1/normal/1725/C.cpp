#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define sz(x) (int)(x.size())
#define F first
#define S second
#define endl '\n'
#define all(x) x.begin(), x.end()
using LL = long long;
using PI = pair<int, int>;
const int N = 1000005;
LL D[N];
LL sum[N];
set <LL> s;
#define mod 998244353

LL f[N], g[N], inv[N];
void init () {
	f[0] = 1;
	for (int i = 1; i < N; i ++) f[i] = f[i - 1] * i % mod;
	g[0] = g[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i < N; i ++) {
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
		g[i] = g[i - 1] * inv[i] % mod;
	}
}

LL calc (int n, int c) {
	LL rlt = f[n] * g[c] % mod;
	return rlt * g[n - c] % mod;
}

LL modexp (LL a, LL n) {
	LL rlt = 1;
	for (; n; n /= 2) {
		if (n & 1) rlt = rlt * a % mod;
		a = a * a % mod;
	}
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	init ();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		cin >> D[i];
		if (!i) sum[i] = D[i];
		else sum[i] = sum[i - 1] + D[i];
		s.insert(sum[i]);
	}
	int cnt = 0;
	if (sum[n - 1] & 1) {
		LL rlt = modexp(m, n);
		cout << rlt << endl;
		return 0;
	}
	for (int i = 0; i < n; i ++) {
		if (s.count(sum[i] + sum[n - 1] / 2)) cnt ++;
	}
	LL rlt = 0;
	LL v = 1;
	for (int i = 0; i <= min (m, cnt); i ++) {
		LL add = calc (cnt, i) * modexp(m - i - 1, cnt - i) % mod;
		add = add * modexp(m - i, n - i * 2 - (cnt - i)) % mod;
		add = add * v % mod;
		v = v * (m - i) % mod;
		rlt = (rlt + add) % mod;
	}
	cout << rlt << endl;
	return 0;
}