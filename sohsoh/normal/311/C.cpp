#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool used[MAXN];
ll h, n, q, k, dist[MAXN], val[MAXN], pos[MAXN];
vector<ll> V;
set<pll> T; // val, index
vector<int> st[MAXN];

inline void Update() {	
	memset(dist, 63, sizeof dist); //
	dist[1] = 1;
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({1, 1});
	
	while (!pq.empty()) {
		ll v = pq.top().Y, d_v = pq.top().X;
		pq.pop();
		if (dist[v] != d_v) continue;
		
		for (ll e : V) {
			ll u = (e + v) % k;
			if (d_v + e < dist[u]) {
				dist[u] = d_v + e;
				pq.push({dist[u], u});
			}
		}
	}

	T.clear();
	for (int i = 0; i < k; i++) {
		for (int e : st[i]) {
			if (used[e]) continue;
			ll p = pos[e], c = val[e];
			if (p >= dist[i]) T.insert({c, -1 * e});
		}
	}
}

inline int Answer() {
	if (T.empty()) return cout << 0 << endl, 0;
	int ind = -1 * (T.rbegin() -> Y), c = T.rbegin() -> X;
	used[ind] = true;
	T.erase({c, -ind});
	cout << c << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> h >> n >> q >> k;
	for (int i = 1; i <= n; i++) {
		cin >> pos[i] >> val[i];
		st[pos[i] % k].push_back(i);
	}
	
	Update();
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll x;
			cin >> x;
			V.push_back(x);
			Update();
		} else if (cmd == 2) {
			int x, y;
			cin >> x >> y;
			if (T.find({val[x], -x}) != T.end()) {
				T.erase({val[x], -x});
				T.insert({val[x] - y, -x});
			}

			val[x] -= y;
		} else Answer();
	}	
	return 0;
}