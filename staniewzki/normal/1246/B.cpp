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
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	LL ans = 0;
	map<vector<PII>, int> m;
	REP(i, n) {
		int a, x;
		cin >> a;
		x = a;
		vector<PII> r1, r2;
		for(int j = 2; j * j <= a; j++) {
			int q = 0;
			while(x % j == 0) q++, x /= j;
			q %= k;
			if(q) {
				r1.emplace_back(j, q);
				r2.emplace_back(j, k - q);
			}
		}
		if(x != 1) {
			r1.emplace_back(x, 1);
			r2.emplace_back(x, k - 1);
		}
		debug(a, r1, r2);
		ans += m[r2];
		m[r1]++;
	}

	cout << ans << "\n";
}