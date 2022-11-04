#include<bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
using LL = long long;
using PI = pair<LL, LL>;
using VI = vector<LL>;
#define endl '\n'
#define sz(x) (int((x).size()))
const int MX = 1005;
const int MOD = 998244353;
const int INF = 1000000007;
int n;
VI adj[MX];
int cnt[MX];
int q[MX], hd, tl;

void sort_DAG() {
	int i, u, v;
	fill_n(cnt, n, 0);
	for (u = 0; u < n; u++) {
		for (i = sz(adj[u]) - 1; i >= 0; i--) {
			v = adj[u][i];
			cnt[v]++;
		}
	}
	hd = tl = 0;
	for (u = 0; u < n; u++) {
		if (!cnt[u]) q[tl++] = u;
	}
	while (hd < tl) {
		u = q[hd++];
		for (i = sz(adj[u]) - 1; i >= 0; i--) {
			v = adj[u][i];
			cnt[v]--;
			if (!cnt[v]) q[tl++] = v;
		}
	}
}

LL a[MX];
vector<PI> dp[MX];
vector<int> con[MX];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T --) {
		int m; cin >> n >> m;
		for (int i = 0; i < n; i ++) {
			adj[i].clear();
			dp[i].clear();
			con[i].clear();
		}
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			if (a[i]) dp[i].push_back({0LL, a[i]});
		}
		for (int i = 0; i < m; i ++) {
			int x, y; cin >> x >> y;
			x --, y --;
			adj[x].push_back(y);
			con[y].push_back(x);
		}
		sort_DAG();
		for (int i = 0; i < n; i ++) {
			int j = q[i];
			for (int v : con[j]) {
				for (PI it : dp[v]) {
					LL l = it.first, r = it.second;
					dp[j].push_back({l + 1, r + 1});
				}
			}
			sort(dp[j].begin(), dp[j].end());
			vector<PI> tp;
			LL L = 0, R = 0;
			int sz = dp[j].size();
			for (int k = 0; k < sz; k ++) {
				LL l = dp[j][k].first;
				LL r = dp[j][k].second;
				
				if (l > R) {
					if (L != R) tp.push_back({L, R});
					L = l;
					R = r;
				} else {
					R += (r - l);
					if (R > MOD) R -= MOD;
				}
			}
			if (L != R) tp.push_back({L, R});
			dp[j].clear();
			dp[j] = tp;
		}
		int en = q[n - 1];
		sort(dp[en].begin(), dp[en].end());
		int sz = dp[en].size();
		LL R = 0;
		if (sz > 0) R = dp[en][sz - 1].second;
		cout << R % MOD << endl;
	}
	return 0;
}