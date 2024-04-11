#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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
const ll CST = 3e5;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, t;
vector<pll> adj[MAXN];
vector<vector<pair<pll, bool>>> tours;
bool mark[MAXN], vis[MAXN];
map<pll, int> mp;

void Euler(int v, int p, int ind) {
	vis[v] = true;
	while (!adj[v].empty()) {
		pll e = adj[v].back();
		adj[v].pop_back();
		if (mark[e.Y]) continue;
		mark[e.Y] = true;
		Euler(e.X, v, e.Y);
	}

	if (p >= 0) {
		if (v > p) swap(v, p);
		p -= CST;
		bool b = ind < n;
		tours.rbegin() -> push_back({{v, p}, b});
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	t = n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		mp.insert({{x, y}, i});
		y += CST;
		adj[x].push_back({y, i});
		adj[y].push_back({x, i});
	}

	stack<int> odd_deg;
	for (int i = 0; i < MAXN; i++) 
		if (adj[i].size() & 1) 
			odd_deg.push(i);

	while (!odd_deg.empty()) {
		int v = odd_deg.top();
		odd_deg.pop();
		int u = odd_deg.top();
		odd_deg.pop();
		adj[v].push_back({u, t});
		adj[u].push_back({v, t});
		t++;
	}

	for (int i = 0; i < MAXN; i++) {
		if (adj[i].empty() || vis[i]) continue;
		tours.push_back({});
		Euler(i, -1, -1);
	}

	vector<pair<int, bool>> ans;
	for (auto tour : tours) {
		bool b = false;
		int rotate_ind = 0;
		for (int i = 0; i < tour.size(); i++)
			if (!tour[i].Y) rotate_ind = i;
		rotate(tour.begin(), tour.begin() + rotate_ind, tour.end());
		
		for (auto e : tour) {
			b = !b;
			if (!e.Y) continue;
			ans.push_back({mp[e.X], b});
		}
	}
	
	sort(all(ans));
	for (auto e : ans) {
		if (e.Y) cout << 'b';
		else cout << 'r';
	}

	cout << endl;
	return 0;
}