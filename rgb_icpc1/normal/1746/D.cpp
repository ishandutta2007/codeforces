#include <bits/stdc++.h>
using namespace std;

template<typename hd, typename tl> void chkmin(hd& a, tl b) { if(b < a) a = b; }
template<typename hd, typename tl> void chkmax(hd& a, tl b) { if(a < b) a = b; }
#define pb push_back
#define pob pop_back
#define endl '\n'
using LL = long long;
using PI = pair<LL, LL>;
using VI = vector<LL>;
const LL MX = 1000005;
LL a[MX];

vector <LL> adj[MX];
LL s[MX];
map <LL, LL> dp[MX];
LL p[MX];

LL calc (LL u, LL k) {
	if (dp[u].count(k)) return dp[u][k];
	LL sz = adj[u].size();
	LL rlt = s[u] * k;
	if (!sz) return rlt;
	LL val = k / sz;
	if(sz == 1) {
		return dp[u][k] = rlt + calc(adj[u][0], k);
	}
	vector <LL> V;
	LL tot = 0;
	for (auto v : adj[u]) {
		tot += calc (v, val);
		V.push_back(-calc(v, val) + calc(v, val + 1));
	}
	sort (V.begin(), V.end());
	reverse(V.begin(), V.end());
	for (LL i = 0; i < k % sz; i ++) {
		rlt += V[i];
	}
	rlt += tot;
	return dp[u][k] = rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
//
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	LL Tc; cin >> Tc;
	while (Tc --) {
		LL n, k;
		cin >> n >> k;
		for (LL i = 1; i <= n; i++) adj[i].clear();
		for (LL i = 1; i <= n; i ++) dp[i].clear();
		for (LL i = 2; i <= n; i ++) {
			cin >> p[i];
			adj[p[i]].push_back(i);
		}
		for (LL i = 1; i <= n; i ++) cin >> s[i];
		cout << calc (1, k) << endl;
//		return 0;
	}
	return 0;
}