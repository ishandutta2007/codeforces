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

	int n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<int> q(n);
	REP(i, n) {
		int h;
		cin >> h;
		h %= (a + b);
		if(h == 0) h = a + b;
		if(h <= a) q[i] = 0;
		else {
			h -= a;
			q[i] = h / a + (h % a != 0);
		}
		debug(i, q[i]);
	}

	sort(q.begin(), q.end());
	int ans = 0;
	REP(i, n) {
		if(q[i] <= k) {
			ans ++;
			k -= q[i];
		}
		else break;
	}
	cout << ans << "\n";
}