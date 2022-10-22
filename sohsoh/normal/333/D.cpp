#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 62;

int A[MAXN][MAXN], n, m;
vector<ll> parts[MAXN];

bool can(int T) {
	for (int i = 0; i < n; i++) {
		parts[i].clear();
		ll val = 0;
		for (int j = 0; j < m; j++) {
			if ((j - 1) % LOG == 0) parts[i].push_back(val), val = 0;
			if (A[i][j] >= T) val ^= (1ll << ((ll)j % LOG));
		}

		parts[i].push_back(val);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			vector<ll> v;
			for (int k = 0; k < int(parts[i].size()); k++) {
				if (parts[i][k] & parts[j][k]) v.push_back(parts[j][k] & parts[i][k]);
			}

			if (v.size() > 1) return true;
			if (v.size() == 1 && __builtin_popcountll(v.front()) > 1) return true;
		}
	}

	return false;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	int L = 0, R = MOD;
	while (L < R) {
		int mid = (L + R + 1) >> 1;
		if (can(mid)) L = mid;
		else R = mid - 1;
	}

	printf("%d", L);	
	return 0;
}