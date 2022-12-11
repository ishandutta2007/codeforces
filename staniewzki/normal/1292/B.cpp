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

	vector<LL> x(1), y(1);
	cin >> x[0] >> y[0];
	LL ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	LL px, py, t;
	cin >> px >> py >> t;
	FOR(i, 1, 1e6) {
		if(x[i - 1] > (1e18 - bx) / ax) break;
		if(y[i - 1] > (1e18 - by) / ay) break;
		x.emplace_back(x[i - 1] * ax + bx);
		y.emplace_back(y[i - 1] * ay + by);
	}

	auto dst = [&](LL x1, LL y1, LL x2, LL y2) {
		return abs(x1 - x2) + abs(y1 - y2);
	};

	int n = size(x);
	int ans = 0;
	REP(i, n) {
		LL q = dst(px, py, x[i], y[i]);
		debug(x[i], y[i], q);
		if(q > t) continue;
		for(int j = i; j >= 1; j--) {
			q += dst(x[j], y[j], x[j - 1], y[j - 1]);
			if(q > t) {
				ans = max(ans, i - j + 1);
				break;
			}
		}
		if(q <= t) ans = max(ans, i + 1);
		q = dst(px, py, x[i], y[i]);
		for(int j = i; j < n - 1; j++) {
			q += dst(x[j], y[j], x[j + 1], y[j + 1]);
			if(q > t) {
				ans = max(ans, j - i + 1);
				break;
			}
		}
		if(q <= t) ans = max(ans, n - i);
	}

	cout << ans << "\n";
}