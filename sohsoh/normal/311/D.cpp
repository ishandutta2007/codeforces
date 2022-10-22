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

const ll MAXN = 5e5 + 10;
const ll MOD = 95542721;
const ll T = 48;

ll lz[MAXN], sg[MAXN][T], n, q, A[MAXN];

void Build(int L = 1, int R = n, int v = 1) {
	if (L == R) {
		sg[v][0] = A[L];
		for (int i = 1; i < T; i++) {
			sg[v][i] = sg[v][i - 1] * sg[v][i - 1] % MOD * sg[v][i - 1] % MOD;
		}
	
		return;
	}

	int mid = (L + R) >> 1;
	Build(L, mid, v << 1);
	Build(mid + 1, R, v << 1 | 1);

	for (int i = 0; i < T; i++)
		sg[v][i] = (sg[v << 1][i] + sg[v << 1 | 1][i] % MOD);

}

inline void Push(int v) {
	lz[v] %= T;
	if (lz[v]) {
		if ((v << 1 | 1) < MAXN) {
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
		}

		rotate(sg[v], sg[v] + lz[v], sg[v] + T);
		lz[v] = 0;
	}
}

void Update(int QL, int QR, int L = 1, int R = n, int v = 1) {
	Push(v);
	if (QL > R || QR < L) return;
	if (QL <= L && QR >= R) {
		lz[v]++;
		Push(v);
		return;
	}

	int mid = (L + R) >> 1;
	Update(QL, QR, L, mid, v << 1);
	Update(QL, QR, mid + 1, R, v << 1 | 1);
	for (int i = 0; i < T; i++)
		sg[v][i] = (sg[v << 1][i] + sg[v << 1 | 1][i] % MOD);
}

ll Query(int QL, int QR, int L = 1, int R = n, int v = 1) {
	Push(v);
	if (QL > R || QR < L) return 0;
	if (QL <= L && QR >= R) return sg[v][0];

	int mid = (L + R) >> 1;
	return (Query(QL, QR, L, mid, v << 1)
			+ Query(QL, QR, mid + 1, R, v << 1 | 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	Build();
	cin >> q;
	while (q--) {
		int c, L, R;
		cin >> c >> L >> R;
		if (c == 2) Update(L, R);
		else cout << Query(L, R) << endl;
	}
	return 0;
}