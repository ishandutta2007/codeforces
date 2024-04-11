#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int mod = 998244353;
int mul(int a, int b) {
	return (LL) a * b % mod;
}
 
int qpow(int a, int n) {
	if(n == 0) return 1;
	if(n % 2 == 1) return mul(a, qpow(a, n - 1));
	return qpow(mul(a, a), n / 2);
}

vector<int> fac, rev;

void fac_init(int n) {
	fac.resize(n + 1);
	fac[0] = 1;
	FOR(i, 1, n) fac[i] = mul(fac[i - 1], i);
	rev.resize(n + 1);
	rev[n] = qpow(fac[n], mod - 2);
	for(int i = n; i >= 1; i--)
		rev[i - 1] = mul(rev[i], i);
	debug(fac, rev);
}
 
int n_choose_k(int n, int k) {
	debug(n, k);
	int ret = fac[n];
	ret = mul(ret, rev[n - k]);
	ret = mul(ret, rev[k]);
	return ret;	
}

int add(int a, int b) {
	a += b;
	while(a >= mod) a -= mod;
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	REP(i, n) cin >> h[i];

	k %= mod;

	int w = 0, p = 1;
	REP(i, n) {
		int j = (i + 1) % n;
		if(h[i] == h[j]) w++, p = mul(p, k);
	}

	int q = n - w, ans = 0;
	fac_init(q);
	FOR(i, 0, q / 2) {
		int c = n_choose_k(q, i);
		int u = n_choose_k(q - i, i);
		c = mul(c, u);
		ans = add(ans, mul(c, mul(p, qpow(k - 2, q - 2 * i))));
	}

	debug(ans);


	int ret = (qpow(k, n) - ans + mod) % mod;
	ret = mul(ret, qpow(2, mod - 2));

	cout << ret << "\n";
}