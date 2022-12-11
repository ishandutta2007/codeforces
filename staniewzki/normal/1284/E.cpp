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

LL cross(PII a, PII b) {
	return (LL) a.ST * b.ND - (LL) a.ND * b.ST;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> x(n), y(n);
	REP(i, n) cin >> x[i] >> y[i];

	LL ans = 0;
	REP(i, n) {
		vector<PII> pts;
		REP(j, n) {
			if(i == j) continue;
			pts.emplace_back(x[j] - x[i], y[j] - y[i]);
		}
		sort(pts.begin(), pts.end(), [&](PII p, PII q) {
			bool P = PII(0, 0) < p;
			bool Q = PII(0, 0) < q;
			if(P != Q) return p < q;
			return cross(p, q) < 0;
		});

		REP(j, n - 1) pts.emplace_back(pts[j]);

		int pos = 0;
		LL total = (LL) (n - 1) * (n - 2) * (n - 3) / 6;
		REP(j, n - 1) {
			pos = max(pos, j + 1);
			while(pos < size(pts) && cross(pts[j], pts[pos]) < 0)
				pos++;

			LL k = pos - j - 1;
			total -= k * (k - 1) / 2;
		}

		ans += total * (n - 4);
		debug(i, total, ans);
	}

	cout << ans / 2 << "\n";
}