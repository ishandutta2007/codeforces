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
struct mi {
	int val;
	mi() { val = 0; }
	mi(const LL& v) {
		val = (-mod <= v && v <= mod) ? v : v % mod;
		if(val < 0) val += mod;
	}

	friend ostream& operator<<(ostream &os, const mi &a) {
		return os << a.val;
	}
	friend istream& operator>>(istream &is, mi &a) {
		return is >> a.val;
	}

	friend bool operator==(const mi &a, const mi &b) {
		return a.val == b.val;
	}
	friend bool operator!=(const mi &a, const mi &b) {
		return !(a == b);
	}
	friend bool operator<(const mi &a, const mi &b) {
		return a.val < b.val;
	}
	friend bool operator<=(const mi &a, const mi &b) {
		return a.val <= b.val;
	}

	mi operator-() const { return mi(-val); }
	mi& operator+=(const mi &m) {
		if((val += m.val) >= mod) val -= mod;
		return *this;
	}
	mi& operator-=(const mi &m) {
		if((val -= m.val) < 0) val += mod;
		return *this;
	}
	mi& operator*=(const mi &m) {
		val = (LL) val * m.val % mod;
		return *this;
	}
	friend mi qpow(mi a, LL n) {
		if(n == 0) return 1;
		if(n % 2 == 1) return qpow(a, n - 1) * a;
		return qpow(a * a, n / 2);
	}
	friend mi inv(const mi &a) {
		assert(a != 0); return qpow(a, mod - 2);
	}
	mi& operator /=(const mi &m) { 
		return (*this) *= inv(m); 
	}

	friend mi operator+(mi a, const mi &b) { return a += b; }
	friend mi operator-(mi a, const mi &b) { return a -= b; }
	friend mi operator*(mi a, const mi &b) { return a *= b; }
	friend mi operator/(mi a, const mi &b) { return a /= b; }
};
using MI = mi;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> mod;

	MI ans = 0;
	MI fac = 1, f2 = 1;
	FOR(i, 1, n) f2 *= i;
	FOR(i, 1, n) {
		f2 /= (n + 1 - i);
		fac *= i;
		MI q = (n + 1 - i);
		q *= q;
		q *= fac;
		q *= f2;
		debug(fac, q, fac * q);
		ans += q;
	}

	cout << ans << "\n";
}