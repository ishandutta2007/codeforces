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

/*
 * Status: Przetestowane
 * Opis:
 * Uycie: 
 * get_hash(l, r) zwraca hasza [l, r] wcznie
 * mona zmieni modulo i baz
 * Czas: O(1)
 */

struct Hashing {
	vector<LL> ha, pw;
	LL mod = 1000696969;
	int base;

	Hashing(string &str) {
		base = 31;
		int len = size(str);
		ha.resize(len + 1);
		pw.resize(len + 1, 1);
		REP(i, len) {
			ha[i + 1] = (ha[i] * base + str[i] - 'a' + 1) % mod;
			pw[i + 1] = (pw[i] * base) % mod;
		}
	}

	LL get_hash(int l, int r) {
		if(l > r) return 0;
		return ((ha[r + 1] - ha[l] * pw[r - l + 1]) % mod + mod) % mod;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	string str;
	cin >> str;
	vector<int> dp(n);
	Hashing hasz(str);
	REP(i, n) {
		dp[i] = (i != 0 ? dp[i - 1] : 0) + a;

		auto check = [&](int k) {
			int h = hasz.get_hash(i - k + 1, i);
			FOR(j, k - 1, i - k) {
				int _h = hasz.get_hash(j - k + 1, j);
				if(h == _h) return true;
			}
			return false;
		};

		int l = 0, r = i + 1;
		while(l < r) {
			int m = (l + r + 1) / 2;
			if(check(m))
				l = m;
			else
				r = m - 1;
		}

		if(l) dp[i] = min(dp[i], dp[i - l] + b);
	}

	cout << dp[n - 1] << "\n";
}