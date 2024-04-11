#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int A[MAXN], par[MAXN], n, k, F[MAXN], din[MAXN];
map<ll, int> mp;
ll tot, S[MAXN];
int dp[MAXN], cyc_mask;
vector<int> cyc, mask_cyc[MAXN];
bool vis[MAXN];
pll ans[MAXN];

void dfs(int v) {
	cyc.push_back(v);
	cyc_mask ^= (1 << par[v]);

	vis[v] = true;
	if (!vis[F[v]])
		dfs(F[v]);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> k;
	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		while (c--) {
			int x;
			cin >> x;
			mp[x] = ++n;
			A[n] = x;
			par[n] = i;
		
			S[i] += x;
			tot += x;
		}
	}

	if (tot % k) return cout << "No" << endl, 0;
	tot /= k;
	for (int i = 1; i <= n; i++) {
		F[i] = mp[tot - (S[par[i]] - A[i])];
		din[F[i]]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (din[i] <= 0)
			q.push(i);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		din[F[v]]--;

		if (F[v] && din[F[v]] <= 0)
			q.push(F[v]);

		F[v] = 0;
	}

	for (int i = 1; i <= n; i++) { 
		if (!vis[i] && F[i]) {
			cyc_mask = 0;
			cyc.clear();
			dfs(i);

			if (int(cyc.size()) == __builtin_popcount(cyc_mask)) {
				mask_cyc[cyc_mask] = cyc;
				dp[cyc_mask] = cyc_mask;
			}
		}
	}

	for (int mask = 1; mask < (1 << k); mask++) {
			if (dp[mask]) continue;
		for (int submask = mask; submask; submask = (submask - 1) & mask) {
			if (dp[mask ^ submask] && !mask_cyc[submask].empty()) {
				dp[mask] = submask;
				break;
			}
		}
	}


	int mask = (1 << k) - 1;
	if (!dp[mask]) return cout << "No" << endl, 0;

	while (mask) {
		int submask = dp[mask], sz = __builtin_popcount(submask);
		vector<int>& vec = mask_cyc[submask];

		for (int i = 0; i < sz - 1; i++)
			ans[par[vec[i + 1]]] = {A[vec[i + 1]], par[vec[i]]};

		ans[par[vec[0]]] = {A[vec[0]], par[vec[sz - 1]]};
		mask ^= submask;
	}
	
	cout << "Yes" << endl;
	for (int i = 0; i < k; i++)
		cout << ans[i].X << sep << ans[i].Y + 1 << endl;
	return 0;
}