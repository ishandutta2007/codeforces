#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll md1 = 1e9 + 7;
const ll md2 = 998244353; // 1e9 + 9;
      ll md3 = 0;

ll hsh[10][10][3] = {0};
vector<pll> adj[MAXN];

ll ans1, ans2, ans3, bf[10], ans = 0;

void brute_force(ll ind, ll k) {
	if (ind >= k) {
		ll tans1 = 0, tans2 = 1, tans3 = 1;
		for (int i = 0; i < k; i++) {
			tans1 = (tans1 + hsh[i + 1][bf[i]][0]) % md1;
			tans2 = (tans2 * hsh[i + 1][bf[i]][1]) % md2;
			tans3 = (tans3 * hsh[i + 1][bf[i]][2]) % md3;
		}	

		if (tans1 == ans1 && tans2 == ans2 && tans3 == ans3) ans++;
		return;
	}

	for (int i = 1; i <= ind + 1; i++) {
		bf[ind] = i;
		brute_force(ind + 1, k);
	}
}

int main() {
	fast_io;
	srand(time(0));
	ll n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}

	md3 = rand() % 10000;
	md3 += 123;

	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) hsh[i][j][1] = hsh[i][j][2] = 1;

	for (int i = 1; i <= n; i++) {
		if (adj[i].empty()) return cout << 0 << endl, 0;
		sort(all(adj[i]));
		for (int j = 0; j < adj[i].size(); j++) {
			hsh[adj[i].size()][j + 1][0] += adj[i][j].Y;
			hsh[adj[i].size()][j + 1][1] *= adj[i][j].Y;
			hsh[adj[i].size()][j + 1][2] *= adj[i][j].Y;	
			hsh[adj[i].size()][j + 1][0] %= md1;
			hsh[adj[i].size()][j + 1][1] %= md2;
			hsh[adj[i].size()][j + 1][2] %= md3;
		}
	}

	ans1 = 0;
	ans2 = 1;
	ans3 = 1;
	for (int i = 1; i <= n; i++) {
		ans1 = (ans1 + i) % md1;
		ans2 = (ans2 * i) % md2;
		ans3 = (ans3 * i) % md3;
	}

	brute_force(0, k);

	cout << ans << endl;
	return 0;
}