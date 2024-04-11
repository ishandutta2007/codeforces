// Sohsoh84 :)))
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

int n, q, A[MAXN], mx[MAXN];
ll sg[MAXN];

void Build(int v = 1, int L = 1, int R = n) {
	if (L == R) sg[v] = A[L], mx[v] = L;
	else {
		int mid = (L + R) >> 1;
		Build(v << 1, L, mid);
		Build(v << 1 | 1, mid + 1, R);
		
		sg[v] = sg[v << 1] + sg[v << 1 | 1];
		mx[v] = mx[v << 1];
		if (A[mx[v << 1 | 1]] > A[mx[v]]) mx[v] = mx[v << 1 | 1];
	}
}

void Update(int ind, int L = 1, int R = n, int v = 1) {
	if (L == R) sg[v] = A[L], mx[v] = L;
	else {
		int mid = (L + R) >> 1;
		if (ind <= mid) Update(ind, L, mid, v << 1);
		else Update(ind, mid + 1, R, v << 1 | 1);
		
		sg[v] = sg[v << 1] + sg[v << 1 | 1];
		mx[v] = mx[v << 1];
		
		if (A[mx[v << 1 | 1]] > A[mx[v]]) mx[v] = mx[v << 1 | 1];
	}
}

void Mod(int QL, int QR, int mod, int L = 1, int R = n, int v = 1) {
	if (QL > R || QR < L) return;
	if (QL <= L && QR >= R) {
		while (A[mx[v]] >= mod) {
			A[mx[v]] = A[mx[v]] % mod;
			Update(mx[v]);
		}

		return;
	}

	int mid = (L + R) >> 1;
	Mod(QL, QR, mod, L, mid, v << 1);
	Mod(QL, QR, mod, mid + 1, R, v << 1 | 1);
}

ll Query(int QL, int QR, int L = 1, int R = n, int v = 1) {
	if (QL > R || QR < L) return 0;
	if (QL <= L && QR >= R) return sg[v];

	int mid = (L + R) >> 1;
	return Query(QL, QR, L, mid, v << 1) +
		Query(QL, QR, mid + 1, R, v << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];

	Build();
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int l, r;
			cin >> l >> r;
			cout << Query(l, r) << endl;
		} else if (c == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			Mod(l, r, x);
		} else {
			int ind, k;
			cin >> ind >> k;
			A[ind] = k;
			Update(ind);
		}
	}
	return 0;
}