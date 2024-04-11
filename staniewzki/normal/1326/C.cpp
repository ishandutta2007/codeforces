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

template<int mod>
struct modular {
	int val;
	modular() { val = 0; }
	modular(const LL& v) {
		val = (-mod <= v && v <= mod) ? v : v % mod;
		if(val < 0) val += mod;
	}
	int to_int() { return val; }

	friend ostream& operator<<(ostream &os, const modular &a) {
		return os << a.val;
	}
	friend istream& operator>>(istream &is, modular &a) {
		return is >> a.val;
	}

	friend bool operator==(const modular &a, const modular &b) {
		return a.val == b.val;
	}
	friend bool operator!=(const modular &a, const modular &b) {
		return !(a == b);
	}
	friend bool operator<(const modular &a, const modular &b) {
		return a.val < b.val;
	}
	friend bool operator<=(const modular &a, const modular &b) {
		return a.val <= b.val;
	}

	modular operator-() const { return modular(-val); }
	modular& operator+=(const modular &m) {
		if((val += m.val) >= mod) val -= mod;
		return *this;
	}
	modular& operator-=(const modular &m) {
		if((val -= m.val) < 0) val += mod;
		return *this;
	}
	modular& operator*=(const modular &m) {
		val = (LL) val * m.val % mod;
		return *this;
	}
	friend modular qpow(modular a, LL n) {
		if(n == 0) return 1;
		if(n % 2 == 1) return qpow(a, n - 1) * a;
		return qpow(a * a, n / 2);
	}
	friend modular inv(const modular &a) {
		assert(a != 0); return qpow(a, mod - 2);
	}
	modular& operator /=(const modular &m) { 
		return (*this) *= inv(m); 
	}

	friend modular operator+(modular a, const modular &b) { return a += b; }
	friend modular operator-(modular a, const modular &b) { return a -= b; }
	friend modular operator*(modular a, const modular &b) { return a *= b; }
	friend modular operator/(modular a, const modular &b) { return a /= b; }
};
using mint = modular<int(998244353)>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<PII> p(n);
	REP(i, n) {
		cin >> p[i].ST;
		p[i].ND = i;
	}

	sort(p.rbegin(), p.rend());

	vector<bool> mark(n);

	LL sum = 0;
	REP(i, k) {
		sum += p[i].ST;
		mark[p[i].ND] = true;
	}

	int last = -1;
	mint ans = 1;
	REP(i, n) {
		if(mark[i]) {
			if(last != -1)
				ans *= (i - last);
			last = i;
		}
	}

	cout << sum << " " << ans << "\n";

}