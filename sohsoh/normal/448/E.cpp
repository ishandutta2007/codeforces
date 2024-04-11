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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll X, k, cnt;
vector<ll> v, adj[MAXN];

void dfs(int i, int d) {
	if (d == k || i == 0) {
		cout << v[i] << sep;
		cnt++;
		if (cnt >= int(1e5)) cout << endl, exit(0);
		return;
	}

	for (int e : adj[i]) dfs(e, d + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> X >> k;

	for (ll i = 1; i * i <= X; i++) {
		if (X % i) continue;
		v.push_back(i);
		if (i * i != X) v.push_back(X / i);
	}	

	sort(all(v));
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j <= i; j++) 
			if (v[i] % v[j] == 0) adj[i].push_back(j);

	dfs(v.size() - 1, 0);
	cout << endl;
	return 0;
}