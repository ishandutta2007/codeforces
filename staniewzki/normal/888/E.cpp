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

	int n, m;
	cin >> n >> m;

	int l = n / 2, r = (n + 1) / 2;
	vector<int> a(l), b(r);
	REP(i, l) cin >> a[i];
	REP(i, r) cin >> b[i];

	auto gen = [&](vector<int> x) {
		int s = size(x);
		vector<int> vals;
		REP(i, (1 << s)) {
			LL sum = 0;
			REP(j, s) if(i & (1 << j)) sum += x[j];
			vals.emplace_back(sum % m);
		}
		sort(vals.begin(), vals.end());
		return vals;
	};

	auto A = gen(a), B = gen(b);
	int ans = 0;
	for(int q : A) {
		auto it = lower_bound(B.begin(), B.end(), m - q);	
		it = prev(it);
		if(it != B.begin()) ans = max(ans, q + *it);
		ans = max(ans, (q + B.back()) % m);
		ans = max(ans, q);
	}

	cout << ans << "\n";
}