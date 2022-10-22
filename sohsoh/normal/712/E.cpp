#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

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

ld A[MAXN], sg[MAXN][2]; // 0: ans, 1: reverse
int n, q;

inline ld Add(ld p, ld b) {
	return p * b / (1 + p * b - p);
}

inline ld AddSeg(ld seg1, ld seg2, ld seg1R) {
	return seg1 * (seg2 + (1 - seg2) * Add(1 - seg1R, seg2));
}

void Update(int v, int L, int R, int ind) {
	if (R < L || R < ind || L > ind) return;
	if (L == R) {
		sg[v][0] = A[ind];
		sg[v][1] = 1 - A[ind];
		return;
	}

	int mid = (L + R) >> 1;
	if (ind <= mid) Update(v << 1, L, mid, ind);
	else Update(v << 1 | 1, mid + 1, R, ind);
		
	sg[v][0] = AddSeg(sg[v << 1][0], sg[v << 1 | 1][0], sg[v << 1][1]);
	sg[v][1] = AddSeg(sg[v << 1 | 1][1], sg[v << 1][1], sg[v << 1 | 1][0]);
}

inline pair<ld, ld> Query(int v, int L, int R, int ql, int qr) {		
	if (R < L || qr < L || ql > R) return {3, 3}; // 0
	if (ql <= L && qr >= R) return {sg[v][0], sg[v][1]};
	
	int mid = (L + R) >> 1;
	pair<ld, ld> P1 = Query(v << 1, L, mid, ql, qr), P2 = Query(v << 1 | 1, mid + 1, R, ql, qr);
	if (P1.X == 3) return P2;
	if (P2.X == 3) return P1;
	
	ld ans1 = AddSeg(P1.X, P2.X, P1.Y), ans2 = AddSeg(P2.Y, P1.Y, P2.X);
	return {ans1, ans2};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		A[i] = ld(a) / ld(b);
		Update(1, 1, n, i);
	}

	cout << setprecision(10) << fixed;
	while (q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int i, a, b;
			cin >> i >> a >> b;
			A[i] = ld(a) / ld(b);
			Update(1, 1, n, i);
		} else {
			int l, r;
			cin >> l >> r;
			cout << Query(1, 1, n, l, r).X << endl;
		}
	}
	
	return 0;
}