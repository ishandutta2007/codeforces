// Sohsoh84 :)
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

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll LOG = 24;

ll hsh[MAXN], p, p_pow[MAXN];
int n, ind, par[MAXN][LOG], H[MAXN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> adj[MAXN];

inline int Par(int v, int k) {
	for (int i = LOG - 1; i >= 0; i--)
		if (k & (1 << i))
			v = par[v][i];
	return v;
}

void wtf(int v, int p) {
	H[v] = H[p] + 1;
	for (int u : adj[v])
		wtf(u, v);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	p = rng() % MOD;
	p_pow[0] = 1;
	for (int i = 1; i < MAXN; i++)
		p_pow[i] = p_pow[i - 1] * p % MOD;

	ind = n + 1;
	for (int i = 1; i < MAXN; i++) p_pow[i] = p_pow[i - 1] * p % MOD;
	
	vector<pair<pll, string>> vec;
	for (int i = 2; i <= n; i++) {
		int p;
		string s;
		cin >> p >> s;
		adj[p].push_back(i);
		vec.push_back({{p, i}, s});
	}
	
	wtf(1, 0);
	sort(all(vec), [] (auto e1, auto e2) {
			return H[e1.X.Y] < H[e2.X.Y];
	});
	
	for (auto e : vec) {
		int v = e.X.X, i = e.X.Y;
		string s = e.Y;
		for (int i = 0; i < s.size() - 1; i++) {
			par[++ind][0] = v;
			hsh[ind] = (hsh[v] * p + (s[i] - 'a' + 1)) % MOD;
			v = ind;
		}	
		
		par[i][0] = v;
		hsh[i] = (hsh[v] * p + (s.back() - 'a' + 1)) % MOD;
	}	

	ll h = 0;
	string s;
	cin >> s;
	for (char c : s) h = (h * p + (c - 'a' + 1)) % MOD;

	for (int i = 1; i < LOG; i++)
		for (int v = 1; v <= n + ind; v++)
			par[v][i] = par[par[v][i - 1]][i - 1];
	
	int ans = 0;
	for (int v = 1; v <= ind + n; v++) {
		ll t = (hsh[v] - hsh[Par(v, s.size())] * p_pow[s.size()] % MOD + MOD) % MOD;
		ans += (t == h);
	}

	cout << ans << endl;
	return 0;
}