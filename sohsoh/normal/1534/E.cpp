// Sohsoh84 O_o //
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 500 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int M[MAXN][MAXN];
int par[MAXN];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			M[i][j] = -1, par[i] = -1;

	par[0] = -2;	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= k; j++)
			if (j <= i && (k - j) <= n - i)
				M[i][i - j + (k - j)] = j;
	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u = 0; u <= n; u++) {
			if (par[u] == -1 && M[v][u] >= 0) {
				par[u] = v;
				q.push(u);
			}
		}
	}

	if (par[n] == -1) return cout << -1 << endl, 0;
	
	int v = n;
	vector<int> O, Z;
	for (int i = 1; i <= n; i++) O.push_back(i);

	ll ans = 0;
	while (v != 0) {
		int u = par[v], w = M[u][v];
		vector<int> t;
	
		cout << "? ";
		for (int j = 0; j < w; j++) {
			cout << Z.back() << sep;
			t.push_back(Z.back());
			Z.pop_back();
		}

		for (int j = 0; j < k - w; j++) {
			cout << O.back() << sep;
			Z.push_back(O.back());
			O.pop_back();
		}

		cout << endl;
		ll x;
		cin >> x;
		ans ^= x;

		for (int e : t) O.push_back(e);
		v = u;
	}

	cout << "! " << ans << endl;
	return 0;
}