#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<int, int>;
const int N = 1000005;
const int MOD = 998244353;

int n;
int rt[N], cnt[N];
int rlt;

void init() {
	for (int u = 0; u < n; u++) {
		rt[u] = u;
		cnt[u] = 1;
	}
}

int find_rt(int u) {
	int v, w;
	for (w = u; w != rt[w]; w = rt[w]);
	for (; u != w; u = v) {
		v = rt[u];
		rt[u] = w;
	}
	return w;
}

void merge(int u, int v) {
	u = find_rt(u);
	v = find_rt(v);
	if (cnt[u] < cnt[v]) swap(u, v);
	rt[v] = u;
	rlt = 1ll * cnt[u] * cnt[v] % MOD * rlt % MOD;
	rlt = 1ll * cnt[u] * cnt[v] % MOD * rlt % MOD;
	cnt[u] += cnt[v];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	init();
	rlt = 1;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v; u--; v--;
		merge(u, v);
	}
	for (int i = 1; i < n; i++) rlt = 1ll * rlt * (2 * i - 1) % MOD;
	cout << rlt << endl;
	
	return 0;
}