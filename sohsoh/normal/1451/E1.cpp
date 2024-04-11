#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int ans1, n, X[MAXN], ans[MAXN];

int orz(int x, int y, int z) {
	swap(y, z);
	int a = (z - y + x) >> 1;
	return a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	map<int, int> mp;
	mp.insert({0, 1});

	for (int i = 2; i <= n; i++) {
		cout << "XOR " << 1 << sep << i << endl;
		cin >> X[i];
		if (mp.find(X[i]) != mp.end()) {
			cout << "AND " << mp[X[i]] << sep << i << endl;
			int E;
			cin >> E;
			ans1 = (E ^ X[i]);
			
			for (int j = i + 1; j <= n; j++) {
				cout << "XOR " << 1 << sep << j << endl;
				cin >> X[j];
			}

			cout << "! " << ans1 << sep;
			for (int j = 2; j <= n; j++) cout << (ans1 ^ X[j]) << sep;
			return cout << endl, 0;
		}

		mp.insert({X[i], i});	
	}

	int nice_ind = 0;
	for (int i = 2; i <= n; i++) if (X[i] == n - 1) nice_ind = i;
	int ind2 = 2;
	if (ind2 == nice_ind) ind2++;
	
	int a2, a3;
	cout << "AND " << 1 << sep << ind2 << endl;
	cin >> a2;
	cout << "AND " << ind2 << sep << nice_ind << endl;
	cin >> a3;

	ans[1] = orz(n - 1, 2 * a2 + X[ind2], 2 * a3 + (X[ind2] ^ X[nice_ind]));

	cout << "! " << ans[1] << sep;
	for (int i = 2; i <= n; i++)
		cout << (ans[1] ^ X[i]) << sep;

	cout << endl;
	return 0;
}