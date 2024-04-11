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

	int q;
	cin >> q;
	REP(_q, q) {
		int n;
		cin >> n;
		vector<LL> p(n);
		REP(i, n) {
			cin >> p[i];
			p[i] /= 100;
		}
		sort(p.rbegin(), p.rend());

		LL x, a, y, b, k;
		cin >> x >> a >> y >> b >> k;

		auto check = [&](int t) {
			vector<LL> used(t);
			REP(i, t) {
				if((i + 1) % a == 0) used[i] += x;
				if((i + 1) % b == 0) used[i] += y;
			}
			sort(used.rbegin(), used.rend());

			debug(t, used);

			LL ans = 0;
			REP(i, t)
				ans += (LL) used[i] * p[i];
			return ans >= k;
		};

		int l = 0, r = n + 1;
		while(l < r) {
			int m = (l + r) / 2;
			debug(l, r, m);
			if(check(m))
				r = m;
			else
				l = m + 1;
		}

		if(l == n + 1) l = -1;
		cout << l << "\n";
	}
}