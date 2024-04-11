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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, P[MAXN], H[MAXN];

bool can(ll d) {
	int h_ind = 0, start = 0;
	for (int p_ind = 0; p_ind < m; p_ind++) {
		if ((abs(P[start] - H[h_ind]) + abs(P[start] - P[p_ind]) > d) && (abs(H[h_ind] - P[p_ind]) + abs(P[p_ind] - P[start]) > d)) {
			h_ind++;
			start = p_ind;
			if (h_ind >= n) return false;
			p_ind--;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> H[i];
	for (int i = 0; i < m; i++) cin >> P[i];

	ll L = 0, R = INF;
	while (L < R) {
		ll mid = (L + R) / 2;
		if (can(mid)) R = mid;
		else L = mid + 1;
	}

	cout << L << endl;
	return 0;
}