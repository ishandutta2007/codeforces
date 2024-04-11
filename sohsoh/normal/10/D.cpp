#include <bits/stdc++.h>
 
using namespace std;
 
typedef int ll;
typedef long double ld;
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
 
const ll MAXN = 500 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN] = {0}, n, m, A[MAXN], B[MAXN];
pll par[MAXN][MAXN];

map<ll, ll> mp, rev_map;
void compress() {
	vector<pll> v;
	for (int i = 1; i <= n; i++) if (A[i] != -1) v.push_back({A[i], i});
	sort(all(v));
	ll val = 0;
	for (int i = 0; i < v.size(); i++) {
		if (mp.find(v[i].X) != mp.end()) A[v[i].Y] = mp[v[i].X];
		else {
			val++;
			mp.insert({v[i].X, val});
			rev_map.insert({val, v[i].X});
			A[v[i].Y] = val;
		}
	}
}

// indj, less than k 
pair<ll, pll> val[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) val[i][j] = {0, {0, 0}}, par[i][j] = {-1, -1};
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	compress();
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		if (mp.find(B[i]) != mp.end()) B[i] = mp[B[i]];
		else B[i] = -1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i] != B[j]) continue;
			ll k = A[i];
			for (ll tj = 0; tj < j; tj++) {
				if (val[tj][k - 1].X + 1 > dp[i][j]) dp[i][j] = val[tj][k - 1].X + 1, par[i][j] = val[tj][k - 1].Y;
			}

			for (int tk = k; tk < MAXN; tk++) val[j][tk] = max(val[j][tk], {dp[i][j], {i, j}});
		}
	}

	pll e = {0, 0};
        ll x = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (dp[i][j] > x) x = dp[i][j], e = {i, j};
	
	cout << x << endl;
	stack<ll> st;
	while (e.X > 0) {
		st.push(A[e.X]);
		pll t = par[e.X][e.Y];
		e = t;
	}

	while (!st.empty()) cout << rev_map[st.top()] << sep, st.pop();
	cout << endl;
	return 0;
}