#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cout << #x << ":" <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 4e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline ll poww(ll a, ll b) {
	a %= MOD;
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1ll;
		a = a * a % MOD;
	}

	return ans;
}

struct SegmentMask {
	ll sg[MAXN], lz[MAXN];
	void Build(int v, int L, int R, ll* A) {
		if (L == R) sg[v] = A[L];
		else {
			int mid = (L + R) >> 1;
			Build(v << 1, L, mid, A);
			Build(v << 1 | 1, mid + 1, R, A);
			sg[v] = sg[v << 1] | sg[v << 1 | 1];
		}
	}  

	inline void Push(int v) {
		sg[v] |= lz[v];
		lz[v << 1] |= lz[v];
		lz[v << 1 | 1] |= lz[v];
	}

	void Update(int v, int L, int R, int ql, int qr, ll val) {
		Push(v);
		if (qr < ql) return;
		if (ql == L && qr == R) {
			lz[v] |= val;
			Push(v);
			return;
		}

		int mid = (L + R) >> 1;
		Update(v << 1, L, mid, ql, min(mid, qr), val);
		Update(v << 1 | 1, mid + 1, R, max(mid + 1, ql), qr, val);
		sg[v] = sg[v << 1] | sg[v << 1 | 1];
	}

	ll Query(int v, int L, int R, int ql, int qr) {
		Push(v);
		if (qr < ql) return 0;
		if (ql == L && qr == R) return sg[v];
		
		int mid = (L + R) >> 1;
		return Query(v << 1, L, mid, ql, min(mid, qr)) | Query(v << 1 | 1, mid + 1, R, max(mid + 1, ql), qr);	
	}
};

struct SegmentMul {
	ll sg[MAXN], lz[MAXN];
	SegmentMul() {
		fill(lz, lz + MAXN, 1);
	}
	
	void Build(int v, int L, int R, ll* A) {
		if (L == R) sg[v] = A[L];
		else {
			int mid = (L + R) >> 1;
			Build(v << 1, L, mid, A);
			Build(v << 1 | 1, mid + 1, R, A);
			sg[v] = sg[v << 1] * sg[v << 1 | 1] % MOD;
		}
	}

	inline void Push(int v, int L, int R) {
		if (lz[v] > 1) {
			sg[v] = sg[v] * poww(lz[v], R - L + 1) % MOD;
			lz[v << 1] = lz[v << 1] * lz[v] % MOD;
			lz[v << 1 | 1] = lz[v << 1 | 1] * lz[v] % MOD;
			lz[v] = 1;
		}
	}

	void Update(int v, int L, int R, int ql, int qr, ll val) {
		Push(v, L, R);
		if (ql > qr) return;
		if (ql == L && qr == R) {
			lz[v] = lz[v] * val % MOD;
			Push(v, L, R);
			return;
		} 

		int mid = (L + R) >> 1;
		Update(v << 1, L, mid, ql, min(qr, mid), val);
		Update(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr, val);
		sg[v] = sg[v << 1] * sg[v << 1 | 1] % MOD;
	}

	ll Query(int v, int L, int R, int ql, int qr) {
		Push(v, L, R);
		if (ql > qr) return 1;
		if (ql == L && qr == R) return sg[v];
		
		int mid = (L + R) >> 1;
		return Query(v << 1, L, mid, ql, min(qr, mid)) * Query(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr) % MOD;
	}
};

ll A[MAXN], n, M[MAXN], q, inv[MAXN];
SegmentMask SegMask;
SegmentMul SegMul;
int ind = 0;
vector<int> primes;

inline bool Prime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

inline ll to_mask(ll x) {
	ll msk = 0;
	for (ll i = 0; i < primes.size(); i++) 
		if (x % primes[i] == 0) 
			msk ^= (1ll << i);
	return msk;
}

inline vector<int> from_mask(ll msk) {
	vector<int> ans;
	for (int i = 0; i < primes.size(); i++) 
		if (msk & (1ll << i))
			ans.push_back(primes[i]);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 300; i++) 
		if (Prime(i)) 
			primes.push_back(i), inv[i] = poww(i, MOD - 2);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i], M[i] = to_mask(A[i]);	
	SegMask.Build(1, 1, n, M);
	SegMul.Build(1, 1, n, A);

	while (q--) {
		string s;
		int L, R;
		cin >> s >> L >> R;
		if (s == "MULTIPLY") {
			ll x;
			cin >> x;
			SegMul.Update(1, 1, n, L, R, x);
			ll msk = to_mask(x);
			SegMask.Update(1, 1, n, L, R, msk);
		} else {
			ll ans = SegMul.Query(1, 1, n, L, R);
			ll msk = SegMask.Query(1, 1, n, L, R);
		
			vector<int> v = from_mask(msk);
			for (ll e : v) {	
				ans = ans * (e - 1) % MOD;
				ans = ans * inv[e] % MOD;
			}
			
			cout << ans << endl;
		}
	}
	return 0;
}