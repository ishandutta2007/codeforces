#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) cout << c;
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

int mod = 1e9 + 7;
int add(int a, int b) {
	return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
	return (a - b < 0 ? a - b + mod : a - b);
}

int mul(int a, int b) {
	return ((LL) a * b) % mod;
}

int qpow(int a, int n) {
	if(n == 0) return 1;
	if(n % 2 == 1) return mul(a, qpow(a, n - 1));
	int x = qpow(a, n / 2);
	return mul(x, x);
}

vector<int> fac, inv;

void fac_init(int size) {
	fac.resize(size + 1);
	fac[0] = 1;
	FOR(i, 1, size) 
		fac[i] = mul(fac[i - 1], i);
	inv.resize(size + 1);
	inv[size] = qpow(fac[size], mod - 2);
	for(int i = size; i >= 1; i--)
		inv[i - 1] = mul(inv[i], i);
}

int get_bin(int n, int k) {
	assert(n >= k);
	return mul(fac[n], mul(inv[n - k], inv[k]));
}

int divi(int a, int b) {
	return mul(a, qpow(b, mod - 2));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	LL n, T;
	cin >> n >> T;
	vector<int> t(n);
	REP(i, n)
		cin >> t[i];	

	fac_init(n + 1);

	int prev = 1;
	int prev_n = -1, prev_k = -1;
	int ans = 0;
	REP(i, n) {
		T -= t[i];
		if(T < 0) break;
		if(T > i + 1) ans = add(ans, 1);			
		else {
			if(prev_n == -1) {
				prev_n = i + 1;
				prev_k = i + 1;
				prev = qpow(2, i + 1);
			}
			else {
				prev = add(prev, prev);
				prev = sub(prev, get_bin(prev_n, 0));
				prev = sub(prev, get_bin(prev_n, prev_k));
				prev_n = i + 1;
				prev = add(prev, get_bin(prev_n, 0));
			}

			while(prev_k != T) {
				prev = sub(prev, get_bin(prev_n, prev_k));
				prev_k--;
			}

			ans = add(ans, divi(prev, qpow(2, prev_n)));
		}
	}

	cout << ans << "\n";
}