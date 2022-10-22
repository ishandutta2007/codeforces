#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

set<pll> st;
map<pll, int> dist;
queue<pll> q;
int n;
pll s, t;

inline void Update(int d, int x, int y) {
	pll v = {x, y};
	if (st.find(v) == st.end()) return;
	if (dist.find(v) == dist.end()) {
		dist[v] = d, q.push(v);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s.X >> s.Y >> t.X >> t.Y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, a, b;
		cin >> r >> a >> b;
		for (int j = a; j <= b; j++)
			st.insert({r, j});
	}

	dist[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front().X, y = q.front().Y;
		q.pop();
		int d = dist[make_pair(x, y)] + 1;	
		Update(d, x + 1, y);
		Update(d, x, y + 1);
		Update(d, x - 1, y);
		Update(d, x, y - 1);
		Update(d, x - 1, y - 1);
		Update(d, x - 1, y + 1);
		Update(d, x + 1, y + 1);
		Update(d, x + 1, y - 1);
	}

	if (dist.find(t) == dist.end()) return cout << -1 << endl, 0;
	cout << dist[t] << endl;
	return 0;
}