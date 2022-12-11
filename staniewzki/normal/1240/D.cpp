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

LL mod = 1e13 + 7;
LL base = 4e5 + 13;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	REP(_q, q) {
		int n;
		cin >> n;

		vector<LL> s = {0}, h = {0};
		map<LL, int> cnt = {{0, 1}};
		LL ans = 0;

		REP(i, n) {
			int x;
			cin >> x;
			if(s.back() != x) {
				s.emplace_back(x);
				LL q = h.back();
				h.emplace_back((q * base + x) % mod);
			}
			else {
				s.pop_back();
				h.pop_back();
			}

			ans += cnt[h.back()];
			cnt[h.back()]++;
		}

		cout << ans << "\n";
	}
}