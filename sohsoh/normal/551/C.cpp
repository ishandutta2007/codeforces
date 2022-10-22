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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, lst;
ll A[MAXN], B[MAXN];

bool can(ll t) {
	int ind = 0;
	for (int i = 0; i < m; i++) {
		if (B[n - 1] == 0) return true;
		ll rem = t - ind - 1;
		
		if (rem <= 0) continue;
		while (rem > 0 && ind < n) {
			ll x = min(rem, B[ind]);
			B[ind] -= x;
			rem -= x;
			if (B[ind] == 0) ind++, rem--;
		}	
	}

	if (B[n - 1] == 0) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (A[i]) lst = i;
	}

	n = lst + 1;

	ll L = 0, R = INF;
	while (L < R) {
		ll mid = (L + R) / 2;
		memcpy(B, A, sizeof A);
		if (can(mid)) R = mid;
		else L = mid + 1;
	}

	cout << L << endl;	
	return 0;
}