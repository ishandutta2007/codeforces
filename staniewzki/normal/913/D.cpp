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

	int n, T;
	cin >> n >> T;
	vector<int> a(n), t(n);
	REP(i, n) cin >> a[i] >> t[i];

	auto able = [&](int k, bool output) {
		vector<PII> b;
		REP(i, n) if(a[i] >= k)
			b.emplace_back(t[i], i);
		if(size(b) < k) return false;
		sort(b.begin(), b.end());
		LL sum = 0;
		REP(i, k) {
			sum += b[i].ST;
			if(output) cout << b[i].ND + 1 << " "; 
		}
		return sum <= T;
	};

	int l = 0, r = n;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(able(m, false))
			l = m;
		else
			r = m - 1;
	}

	cout << l << "\n" << l << "\n";
	able(l, true);
	cout << "\n";
}