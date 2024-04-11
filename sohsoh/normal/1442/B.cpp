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
const ll MOD =  998244353; // 1e9 + 9;

int n, A[MAXN], B[MAXN], k, nxt[MAXN], prv[MAXN], pos[MAXN];
bool used[MAXN];

int solve() {
	cin >> n >> k;
	fill(used, used + n + 10, false);
	for (int i = 1; i <= n; i++) cin >> A[i], nxt[i] = i + 1, prv[i] = i - 1, pos[A[i]] = i;
	for (int i = 1; i <= k; i++) cin >> B[i], used[B[i]] = true;
	nxt[n] = -1;
	prv[1] = -1;
	ll ans = 1;
	for (int i = 1; i <= k; i++) {
		int x = B[i];
		int ind = pos[x];
		int can = 0;
		if (prv[ind] >= 0 && !used[A[prv[ind]]]) can++;
		if (nxt[ind] >= 0 && !used[A[nxt[ind]]]) can++;
		ans *= can;
		ans %= MOD;
		int pr = prv[ind], nx = nxt[ind];
		if (nx >= 0) prv[nx] = pr;
		if (pr >= 0) nxt[pr] = nx;
		used[x] = false;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}