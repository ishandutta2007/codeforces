// bla bla bla
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int n, B[MAXN], C[MAXN];
map<int, int> mp1, mp2;
vector<pll> adj[MAXN];
bool edge_vis[MAXN];
vector<int> tour, V;

inline void Compress() {
	int t = 1;
	for (int i = 1; i <= n - 1; i++) V.push_back(B[i]), V.push_back(C[i]);
	sort(all(V));
	V.resize(unique(all(V)) - V.begin());

	for (int e : V) mp1[e] = t, mp2[t] = e, t++;
	for (int i = 1; i <= n - 1; i++) {
		B[i] = mp1[B[i]];
		C[i] = mp1[C[i]];
		adj[B[i]].push_back({C[i], i});
		adj[C[i]].push_back({B[i], i});
	}
}

void Euler(int v) {
	while (!adj[v].empty()) {
		pll e = adj[v].back();
		adj[v].pop_back();
		if (edge_vis[e.Y]) continue;
		edge_vis[e.Y] = true;
		Euler(e.X);
	}
	
	tour.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) cin >> B[i];
	for (int i = 1; i <= n - 1; i++) {
		cin >> C[i];
		if (C[i] < B[i]) return cout << -1 << endl, 0;
	}

	Compress();
	
	int odd_v = B[1], odd_cnt = 0;
	for (int t : V) {
		int v = mp1[t];
		if (adj[v].size() & 1) {
			odd_v = v;
			odd_cnt++;
		}
	}

	if (odd_cnt > 2) return cout << -1 << endl, 0;
	Euler(odd_v);
	
	for (int i = 1; i <= n - 1; i++) 
		if (!edge_vis[i])
			return cout << -1 << endl, 0;	
	for (int e : tour) cout << mp2[e] << sep;
	cout << endl;
	return 0;
}