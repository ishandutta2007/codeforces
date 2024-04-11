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

vector<int> cost;
vector<int> es[N];
vector<pair<int, int>> go[N];
vector<int> score;
vector<int> ans;
ll sum;

void dfs_init(int v, int pr) {		
	int fat_c = -1;
	for (int w: es[v]) {
		if (w == pr) continue;
		dfs_init(w, v);
		if (fat_c == -1 || score[fat_c] < score[w]) {
			fat_c = w;
		}
		go[v].push_back(make_pair(w, score[w]));
	}	

	if (fat_c == -1) {
		score[v] = cost[v];
		sum += cost[v];
	} else {
		score[v] = min(cost[v], score[fat_c]);
		sum += (score[v] - score[fat_c]);
	}
}

void dfs_ans(int v, bool is_open) {
	int mx_score = -1;
	for (auto q: go[v]) {
		mx_score = max(mx_score, q.second);
	}
	vector<int> mx, oth;
	for (auto q: go[v]) {
		if (q.second == mx_score) {
			mx.push_back(q.first);
		} else {
			oth.push_back(q.first);
		}
	}

	if (mx_score == -1) mx_score = INF;
	if (cost[v] <= mx_score && is_open) ans.push_back(v);
	
	for (int w: oth) dfs_ans(w, true);

	if ((int)mx.size() == 1 && (mx_score > cost[v] || !is_open)) {
		dfs_ans(mx[0], false);
	} else {
		for (int w: mx) dfs_ans(w, true);
	}
}

void solve() {
	int n; cin >> n;
	cost.resize(n);
	score.resize(n);
	ans.clear();
	sum = 0;
	for (int i = 0; i < n; i++) {
		score[i] = -1;
		es[i].clear();
		go[i].clear();
		cin >> cost[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	dfs_init(0, -1);
	dfs_ans(0, true);

	sort(ans.begin(), ans.end());
	cout << sum << " " << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
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
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}