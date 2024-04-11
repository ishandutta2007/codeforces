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

		vector<int> a(n);
		vector<int> first(n, n), last(n, -1);
		int dif = 0;
		REP(i, n) {
			cin >> a[i];
			a[i]--;
			if(first[a[i]] == n) {
				dif++;
				first[a[i]] = i;
			}
			last[a[i]] = i;
		}

		debug(dif);

		int r = -1;
		int e = -1;
		int ans = 0;
		int w = 0;
		REP(i, n) {
			if(r < i) e = -1;
			while(r + 1 < n && e < first[r + 1]) {
				e = max(e, last[++r]);
				if(last[r] != -1) w++;
			}
			ans = max(ans, w);
			if(last[i] != -1) w--;
		}

		cout << dif - ans << "\n";
	}
}