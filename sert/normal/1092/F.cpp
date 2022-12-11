#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int a[N];
ll sum[N], score[N];
vector<int> es[N];

void dfs_init(int v, int pr = -1) {
	sum[v] = a[v];
	score[v] = 0;
	for (int w: es[v]) {
		if (w == pr) continue;
		dfs_init(w, v);
		sum[v] += sum[w];
		score[v] += score[w] + sum[w];
	}
}

void go(int v, int pr, ll &ans, ll up_sum, ll up_score) {
	ll ch_sum = 0;
	ll ch_score = 0;
	ans = max(ans, up_score);

	//cout << v + 1 << " " << up_sum << " " << up_score << "\n";

	for (int w: es[v]) {
		if (w == pr) continue;
		ch_score += score[w];
		ch_sum += sum[w];
	}

	for (int w: es[v]) {
		if (w == pr) continue;
		ll new_sum = up_sum + ch_sum - sum[w] + a[v];
		//cout << v + 1 << " -> " << w + 1 << "\n";
		go(w, v, ans, new_sum, up_score + ch_score - score[w] + new_sum + ch_sum - sum[w]);
	}	
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		es[i].clear();
	}

	if (n == 1) cout << "0\n";
	if (n == 2) cout << max(a[0], a[1]) << "\n";
	if (n < 3) return;

	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	int root = -1;
	for (int i = 0; i < n; i++) {
		if ((int)es[i].size() > 1) root = i;
	}

	dfs_init(root);
	//cout << "root = " << root + 1 << "\n";
	//cout << score[0] << " " << sum[0] << " 0\n";

	ll ans = 0;
	go(root, -1, ans, 0, 0);

	cout << ans << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}