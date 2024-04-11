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

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rd(LL a, LL b) { return uniform_int_distribution<LL>(a, b)(rng); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
		
	int t;
	cin >> t;
	REP(_t, t) {
		int n, m;
		cin >> n >> m;

		vector<LL> c(n);
		REP(i, n) cin >> c[i];

		vector<LL> w(n), h(n);
		REP(i, n) w[i] = rd(1, 1e18);

		REP(i, m) {
			int a, b;
			cin >> a >> b;
			h[b - 1] ^= w[a - 1];
		}

		unordered_map<LL, LL> q;
		REP(i, n) q[h[i]] += c[i];
		
		LL d = 0;
		for(auto &[x, y] : q) {
			if(x != 0)
				d = gcd(d, y);
		}

		cout << d << "\n";
	}
}