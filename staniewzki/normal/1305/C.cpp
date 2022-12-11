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

int mod;

int mul(int a, int b) {
	return (LL) a * b % mod;
}

int fpow(int a, LL n) {
	if(n == 0) return 1;
	if(n % 2 == 1) return mul(a, fpow(a, n - 1));
	return fpow(mul(a, a), n / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	mod = m;

	vector<int> in(n);
	REP(i, n) cin >> in[i];
	sort(in.rbegin(), in.rend());

	vector<LL> a(m), b(m);
	REP(i, n) {
		int x = in[i] % m;
		REP(j, m) {
			int y = (j + x) % m;
			b[j] += a[y];
		}
		a[x]++;
	}

	int ans = 1;
	REP(j, m) ans = mul(ans, fpow(j, b[j]));
	cout << ans << "\n";
}