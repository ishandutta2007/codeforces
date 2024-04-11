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
 
const ll MAXN = 2e5 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll lz[4 * MAXN] = {0}, A[MAXN], n;
pll sg[4 * MAXN];

void push(ll v) {
	sg[2 * v].X += lz[v];
	sg[2 * v + 1].X += lz[v];
	lz[2 * v] += lz[v];
	lz[2 * v + 1] += lz[v];
	lz[v] = 0;
}

pll mmax(pll x, pll y) {
	if (x.X < y.X) return x;
	if (y.X < x.X) return y;
	
	if (x.Y > y.Y) return x;
	return y;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll val, ll ind = 0) {
	if (l > r) return;
	if (l == tl && tr == r) {
		sg[v].X += val;
		lz[v] += val;
		if (ind > 0) sg[v].Y = ind;
		return;
	}

	push(v);
	ll tm = (tl + tr) / 2;
	update(2 * v, tl, tm, l, min(r, tm), val, ind);
	update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val, ind);
	sg[v] = mmax(sg[2 * v], sg[2 * v + 1]);
}

pll rmq(ll v, ll tl, ll tr, ll l, ll r) {
	if (l > r) return {INF, 0};
	if (l <= tl && tr <= r) return sg[v];
	push(v);
	ll tm = (tl + tr) / 2;
	return mmax(rmq(v * 2, tl, tm, l, min(r, tm)), rmq(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll B[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], update(1, 1, n, i, i, A[i], i);
	for (int i = 1; i <= n; i++) {
		pll R = rmq(1, 1, n, 1, n);
		B[R.Y] = i;
		update(1, 1, n, R.Y, R.Y, INF);
		update(1, 1, n, R.Y, n, -1 * i);
	}

	for (int i = 1; i <= n; i++) cout << B[i] << sep;
	cout << endl;
	return 0;
}