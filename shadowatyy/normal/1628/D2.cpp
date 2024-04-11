#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

#define int ll
const int N = 1e6 + 7;
const int mod = 1e9 + 7;

int fact[N];
int inv[N];
int pot[N];
int invpot[N];

int fpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int newt(int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;

	debug(n, k, fact[n] * inv[k] % mod * inv[n - k] % mod);

	return fact[n] * inv[k] % mod * inv[n - k] % mod;
}

int n, m, x;

void solve() {
	cin >> n >> m >> x;

	if (n == m) {
		cout << x * n % mod << endl;
		return;
	}

	int ans = 0;

	for (int k = 0; k <= n; ++k) {
		int kk = x * k % mod;
		ans += kk * pot[n - k] % mod * newt(n - k - 1, m - k) % mod;
		ans %= mod;
	}

	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = inv[0] = pot[0] = 1;

	for (int i = 1; i < N; ++i) {
		fact[i] = i * fact[i - 1] % mod;
		pot[i] = ((mod + 1) / 2) * pot[i - 1] % mod;
		inv[i] = fpow(fact[i], mod - 2);
	}

	int t;
	cin >> t;

	while (t--)
		solve();
}