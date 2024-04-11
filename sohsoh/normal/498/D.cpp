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
const ll MOD = 60; // 998244353; // 1e9 + 9;

int sg[MOD][MAXN], n, A[MAXN], q;

void Build(int v, int L, int R) {
	if (R < L) return;
	if (R == L) {
		for (int i = 0; i < MOD; i++) {
			if (i % A[L] == 0) sg[i][v] = 2;
			else sg[i][v] = 1;
		}

		return;
	}
	
	int mid = (L + R) >> 1;
	Build(v << 1, L, mid);
	Build(v << 1 | 1, mid + 1, R);

	for (int i = 0; i < MOD; i++)
		sg[i][v] = sg[i][v << 1] + sg[(i + sg[i][v << 1]) % MOD][v << 1 | 1];
}

void Update(int v, int L, int R, int ind) {
	if (R < L) return;
	if (R == L) {
		for (int i = 0; i < MOD; i++) {
			if (i % A[L] == 0) sg[i][v] = 2;
			else sg[i][v] = 1;
		}

		return;	
	}

	int mid = (L + R) >> 1;
	if (ind <= mid) Update(v << 1, L, mid, ind);
	else Update(v << 1 | 1, mid + 1, R, ind);

	for (int i = 0; i < 60; i++) 
		sg[i][v] = sg[i][v << 1] + sg[(i + sg[i][v << 1]) % MOD][v << 1 | 1];
}

int Query(int v, int L, int R, int ql, int qr, int mod = 0) {
	if (R < L || R < ql || qr < L) return 0;
	if (ql <= L && qr >= R) return sg[mod][v];
	int mid = (L + R) >> 1;
	int ans = Query(v << 1, L, mid, ql, qr, mod);
	ans += Query(v << 1 | 1, mid + 1, R, ql, qr, (mod + ans) % MOD);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	Build(1, 1, n);

	cin >> q;
	while (q--) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		if (c == 'C') {
			A[x] = y;
			Update(1, 1, n, x);
		} else cout << Query(1, 1, n, x, y - 1) << endl;
	}
	return 0;
}