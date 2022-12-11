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

using LD = long double;

LD eps = 1e-10;
bool evaluate(LD k, LD d, LD t, LD x) {
	LL seg = x / d;
	x -= seg * d;
	LD q = seg * (d + k);
	if(x <= k) q += x * 2;
	else q += k + x;
	return q + eps > 2 * t;
}

void update(LD k, LD &d) {
	LD q = k / d;
	d *= ceil(q);
}

bool good(LD l, LD r) {
	return (r - l) / r <= 1e-9;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	LD k, d, t;
	cin >> k >> d >> t;
	update(k, d);

	LD x = 2 * t;
	LL seg = x / (k + d);
	LD ans = seg * d;
	x -= seg * (k + d);	
	if(x < k * 2) ans += x / 2;
	else {
		ans += k;
		x -= k * 2;
		ans += x;	
	}

	cout.precision(10);
	cout << fixed;
	cout << ans;
}