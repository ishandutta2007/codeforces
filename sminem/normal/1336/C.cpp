#include <bits/stdc++.h>
using namespace std;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 998244353;
typedef modint<mod> mint;

string s, t;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;
	n = s.size();
	m = t.size();

	mint sol = 0;

	vector<mint> dp(n+1, 1);
	int len = 0;
	for (char c : s) {
		vector<mint> tmp(n+1);
		for (int i=0; i<=n; i++) {
			// levo
			if ((i-1 >= 0 && i-1 < m && c == t[i-1]) || i-1 >= m) {
				tmp[i-1] += dp[i];
			}
			// desno
			if (i + len >= m || c == t[i + len]) {
				tmp[i] += dp[i];
			}
		}
		len++;
		swap(tmp, dp);
		if (len >= m)
			sol += dp[0];
	}

	cout << sol() << '\n';
}