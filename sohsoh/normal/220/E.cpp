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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct FenwickTree {
	int fen[MAXN];
	void Add_t(int ind, int val) {
		for (++ind; ind < MAXN; ind += ind & -ind) 
			fen[ind] += val;
	}

	void Add(int L, int R, int val = 1) {
		if (L > R) return;
		Add_t(L, val);
		Add_t(R + 1, -val);
	}

	int Query(int ind) {
		int ans = 0;
		for (++ind; ind > 0; ind -= ind & -ind) 
			ans += fen[ind];
		return ans;
	}
} Suff, Pref;

int A[MAXN], n;
ll k;
vector<int> v;

inline int Remove(int R) {
	R++;
	int ans = Pref.Query(A[R]) + Suff.Query(A[R]);
	Suff.Add(A[R] + 1, n, -1);
	return ans;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		v.push_back(A[i]);
	}

	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (int i = 1; i <= n; i++) A[i] = lower_bound(all(v), A[i]) - v.begin() + 1;
	
	ll inv = 0;
	for (int i = n; i > 0; i--) {
		inv += Suff.Query(A[i]);
		Suff.Add(A[i] + 1, n);
	}

	if (inv <= k) return cout << 1ll * n * (n - 1) / 2 << endl, 0;
	
	ll ans = 0;
	int R = 0;
	for (int L = 1; L <= n; L++) {
		while (R < L) inv -= Remove(R), R++;
		
		while (R < n - 1 && inv > k) {
			inv -= Remove(R);
			R++;
		}

		if (inv <= k && L > 1) ans += n - R;
	
		inv += Pref.Query(A[L]) + Suff.Query(A[L]);
		Pref.Add(1, A[L] - 1);
			
	}

	cout << ans << endl;
	return 0;
}