// \_()_/
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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, sg[MAXN], lz[MAXN], C[MAXN];
vector<pll> R[MAXN];

void push(int v) {
	sg[v] += lz[v];
	if (v << 1 >= MAXN) {
		lz[v] = 0;
		return;
	}

	lz[v << 1] += lz[v];
	lz[v << 1 | 1] += lz[v];
	lz[v] = 0;	
}

void Update(int v, int L, int R, int QL, int QR, ll val) {
	push(v);
	if (QR < QL) return;
	if (QL == L && QR == R) {
		lz[v] += val;
		push(v);
		return;
	}

	int mid = (L + R) >> 1;
	Update(v << 1, L, mid, QL, min(QR, mid), val);
	Update(v << 1 | 1, mid + 1, R, max(QL, mid + 1), QR, val);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

ll Query(int v, int L, int R, int QL, int QR) {
	push(v);
	if (QR < QL) return -INF;
	if (QL == L && QR == R) return sg[v];

	int mid = (L + R) >> 1;
	return max(Query(v << 1, L, mid, QL, min(QR, mid)),
			Query(v << 1 | 1, mid + 1, R, max(mid + 1, QL), QR));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 2; i <= n + 1; i++) cin >> C[i];
	fill(sg, sg + MAXN, -INF);

	for (int i = 0; i < m; i++) {
		int l, r, p;
		cin >> l >> r >> p;
		l++, r++;
		R[r].push_back({l, p});
	}

	n++;
	Update(1, 1, n, 1, 1, INF);
	for (int i = 2; i <= n; i++) {
		Update(1, 1, n, i, i, INF + Query(1, 1, n, 1, i - 1));	
		Update(1, 1, n, 1, i - 1, -C[i]);
		
		for (pll e : R[i]) 
			Update(1, 1, n, 1, e.X - 1, e.Y);

	}

	cout << Query(1, 1, n, 1, n) << endl;
	return 0;
}