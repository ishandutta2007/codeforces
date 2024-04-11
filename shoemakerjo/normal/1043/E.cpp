#include <bits/stdc++.h>

using namespace std;
#define maxn 300010
#define ll long long

int n, m;
ll x[maxn];
ll y[maxn];
#define pli pair<ll, int>
#define mp make_pair

ll xsum = 0LL;
ll fees[maxn];

vector<int> nogo[maxn];
ll ans[maxn];

ll comp(int u, int v) {
	if (x[u] + y[v] < y[u] + x[v]) return x[u] + y[v];
	return y[u] + x[v];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	vector<pli> stuff;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		fees[i] = y[i] - x[i];
		xsum += x[i];
		stuff.push_back(pli(fees[i], i));
	}
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		--u; --v;
		nogo[u].push_back(v);
		nogo[v].push_back(u);
	}
	sort(stuff.begin(), stuff.end());
	ll pref = 0LL;
	int seen = 0;
	for (pli cur : stuff) {
		seen++;
		int indo = cur.second;
		ll f = cur.first;
		ans[indo] = xsum - x[indo];
		ans[indo] += (n-1) * (x[indo]);
		ans[indo] += pref;
		ans[indo]  += f * (n-seen);

		pref += f;
	}

	for (int i = 0; i < n; i++) {
		for (int v : nogo[i]) {
			ans[i] -= comp(i, v);
		}
		cout << ans[i] << " ";
	}

	cout << endl;
	
}