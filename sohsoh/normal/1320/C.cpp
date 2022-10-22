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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

pll B[MAXN];
ll tree[5 * MAXN] = {0}, lz[5 * MAXN] = {0}, n, m, p, A[MAXN];
pair<ll, pll> C[MAXN];

void push(ll v, ll ss, ll se) {
	if (lz[v] != 0) {
		tree[v] += lz[v];
		if (ss != se) {
			lz[2 * v + 1] += lz[v];
			lz[2 * v + 2] += lz[v];
		}
	}

	lz[v] = 0;
}

void update(ll v, ll ss, ll se, ll us, ll ue, ll diff) {
	push(v, ss, se);
	if (ss > se || ss > ue || se < us) return; 
	if (ss >= us && se <= ue) { 
		tree[v] += diff;
		if (ss != se) {
			lz[2 * v + 1] += diff;
			lz[2 * v + 2] += diff;
		}
		
		return;
	}
	
	ll mid = (ss + se) / 2;
	update(2 * v + 1, ss, mid, us, ue, diff);
	update(2 * v + 2, mid + 1, se, us, ue, diff);
	tree[v] = max(tree[2 * v + + 1], tree[2 * v + 2]);
}

ll RMQ(ll v, ll ss, ll se, ll qs, ll qe) {
	push(v, ss, se);
	if (ss > se || ss > qe || se < qs) return -1 * INF;
       	if (ss >= qs && se <= qe) return tree[v];
	ll mid = (ss + se) / 2;
	return max(RMQ(2 * v + 1, ss, mid, qs, qe), RMQ(2 * v + 2, mid + 1, se, qs, qe));
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(A, A + MAXN, INF);
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		A[x] = min(A[x], y);	
	}

	for (int i = 0; i <= MAXN; i++) update(0, 0, MAXN, i, i, -1 * A[i]);	

	for (int i = 0; i < m; i++) cin >> B[i].X >> B[i].Y;
	for (int i = 0; i < p; i++) cin >> C[i].Y.X >> C[i].X >> C[i].Y.Y;
	sort(B, B + m);	
	sort(C, C + p);	

	ll ind = 0, ans = -1 * INF;
	for (int i = 0; i < m; i++) {
		while (ind < p && C[ind].X < B[i].X) {
			ll x = C[ind].Y.X, z = C[ind].Y.Y;
			update(0, 0, MAXN, x + 1, MAXN - 5, z);
			ind++;
		}

		ans = max(ans, -1 * B[i].Y + RMQ(0, 0, MAXN, 0, MAXN - 5));
	}

	cout << ans << endl;
	return 0;
}