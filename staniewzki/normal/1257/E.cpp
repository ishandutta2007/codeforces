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

	int a, b, c;
	cin >> a >> b >> c;
	int n = a + b + c;

	vector<int> A(a), B(b), C(c);
	auto read = [&](vector<int> &v) { for(int &x : v) cin >> x; };
	read(A), read(B), read(C);

	vector<int> pref(n + 1);
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int p = 0, q = 0;
	FOR(i, 0, n) {
		if(p < a && A[p] == i) p++;
		if(q < b && B[q] == i) q++;
		pref[i] = (a - p) + q;
	}

	vector<int> suff(n + 2);
	sort(C.rbegin(), C.rend());
	sort(B.rbegin(), B.rend());
	p = 0, q = 0;
	for(int i = n + 1; i >= 1; i--) {
		if(p < c && C[p] == i) p++;
		if(q < b && B[q] == i) q++;
		suff[i] = (c - p) + q;
		if(i != n + 1) suff[i] = min(suff[i], suff[i + 1]);
	}

	int ans = 1e9;
	FOR(i, 0, n)
		ans = min(ans, pref[i] + suff[i + 1]);
	cout << ans << "\n";
}