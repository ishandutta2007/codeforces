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
const ll MOD = 1e9 + 7;

ll sg[MAXN], lz[MAXN], hsh_pref[MAXN], p_pow[MAXN], p = 2;
vector<ll> hsh_P[MAXN];
int A[MAXN], n, q, x;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void Prep() {
	p = rng() % MOD;
	p_pow[0] = hsh_pref[0] = 1;
	for (int i = 1; i <= n; i++) p_pow[i] = p_pow[i - 1] * p % MOD, 
		hsh_pref[i] = (hsh_pref[i - 1] + p_pow[i]) % MOD;
	
	for (int i = 1; i <= n; i++) {
		hsh_P[i] = {0};
		for (int d = i; d <= n; d += i) hsh_P[i].push_back((p_pow[d - i] + hsh_P[i].back()) % MOD);
	}

	for (int i = 0; i < MAXN; i++) lz[i] = -1;
}

inline void Push(int v, int L, int R) {
	if (lz[v] == -1) return;
	sg[v] = lz[v] * hsh_pref[R - L] % MOD;
	if ((v << 1 | 1) < MAXN) {
		lz[v << 1] = lz[v];
		lz[v << 1 | 1] = lz[v];
	}

	lz[v] = -1;
}

void Build(int v, int L, int R) {
	if (L == R) sg[v] = A[L];
	else {
		int mid = (L + R) >> 1;
		Build(v << 1, L, mid);
		Build(v << 1 | 1, mid + 1, R);
		sg[v] = (sg[v << 1] + sg[v << 1 | 1] * p_pow[mid - L + 1]) % MOD;
	}
}

void Update(int v, int L, int R, int QL, int QR, int val) {
	Push(v, L, R);	
	if (QR < QL) return;
	if (QL == L && QR == R) {
		lz[v] = val;
		Push(v, L, R);
		return;	
	}

	int mid = (L + R) >> 1;
	Update(v << 1, L, mid, QL, min(QR, mid), val);
	Update(v << 1 | 1, mid + 1, R, max(QL, mid + 1), QR, val);	
	sg[v] = (sg[v << 1] + sg[v << 1 | 1] * p_pow[mid - L + 1]) % MOD;
}

ll Query(int v, int L, int R, int QL, int QR) {
	Push(v, L, R);
	if (QR < QL) return 0;
	if (QL == L && QR == R) return sg[v];

	int mid = (L + R) >> 1;
	return (Query(v << 1, L, mid, QL, min(QR, mid)) + 
		p_pow[max(0, mid - QL + 1)] * Query(v << 1 | 1, mid + 1, R, max(QL, mid + 1), QR)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> x;
	q += x;
	Prep();

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		A[i] = c - '0';
	}

	Build(1, 1, n);
	while (q--) {
		int c, l, r, d;
		cin >> c >> l >> r >> d;
		if (c == 1) Update(1, 1, n, l, r, d);
		else {
			int sz = r - l + 1;	
			ll hsh1 = Query(1, 1, n, l, l + d - 1), 
			   hsh2 = Query(1, 1, n, l, r),
			   suff = Query(1, 1, n, l, l + sz % d - 1);
			cout << ((hsh1 * hsh_P[d][sz / d] + suff * p_pow[sz - sz % d]) % MOD == hsh2 ? "YES" : "NO") << endl;
			
		}
	}
	return 0;
}