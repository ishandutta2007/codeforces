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
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int sg[2 * MAXN], n, A[MAXN];
vector<int> ind[MAXN];
bool B[MAXN];


void modify(int p, int val) {
	for (sg[p += n] = val; p > 1; p >>= 1) sg[p >> 1] = min(sg[p], sg[p ^ 1]);
}

int rmq(int l, int r) {
	int ans = INF;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans = min(ans, sg[l++]);
		if (r & 1) ans = min(ans, sg[--r]);
	}

	return ans;
}

bool cmp(pair<pll, ll> x, pair<pll, ll> y) {
	return x.X.Y < y.X.Y;
}

vector<pair<pll, ll>> qr; // [L, R] -> MEX

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], ind[A[i]].push_back(i);

	for (int x = 1; x <= n; x++) {
		if (ind[x + 1].empty()) qr.push_back({{1, n}, x});
		else {
			if (ind[x + 1].front() > 1) qr.push_back({{1, ind[x + 1].front() - 1}, x});
			if (ind[x + 1].back() < n) qr.push_back({{ind[x + 1].back(), n}, x});
			for (int i = 0; i < ll(ind[x + 1].size()) - 1; i++) if (ind[x + 1][i] < ind[x + 1][i + 1] - 1) qr.push_back({{ind[x + 1][i] + 1, ind[x + 1][i + 1] - 1}, x});
		}
	}

	if (count(A + 1, A + n + 1, 1) == n) return cout << 1 << endl, 0;

	sort(all(qr), cmp);
	ll r = 0;
	for (auto q : qr) {
		while (r < q.X.Y) modify(A[r + 1], r + 1), r++;
		if (rmq(1, q.Y + 1) >= q.X.X) B[q.Y] = true;
	}

	ll ans = 1;
	while (B[ans]) ans++;
	cout << ans + 1 << endl;

	return 0;
}