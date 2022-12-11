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

	int n;
	cin >> n;
	vector<LL> a(n);
	REP(i, n) cin >> a[i];
	FOR(i, 1, n - 1) a[i] += a[i - 1];

	LL ans = 1e18;
	auto check = [&](LL k) {
		LL ops = 0;
		REP(i, n) ops += min(a[i] % k, k - a[i] % k);
		ans = min(ans, ops);
	};

	LL sum = a[n - 1];
	for(LL i = 2; i * i <= sum; i++) {
		if(sum % i == 0) {
			check(i);
			while(sum % i == 0) sum /= i;
		}
	}
	if(sum != 1) check(sum);

	if(ans == 1e18) ans = -1;
	cout << ans << "\n";

}