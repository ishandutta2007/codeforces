#undef _GLIBCXX_DEBUG
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

	int t;
	cin >> t;
	REP(it, t) {
		int n;
		cin >> n;
		vector<int> p(n);
		REP(i, n) cin >> p[i];

		int g = 0, s = 0, b = 0;
		while(g < n && p[g] == p[0]) g++;
		while(g >= s) {
			int l = g + s;
			while(g + s < n && p[s + g] == p[l]) s++;
			if(g + s == n) break;
		}
		while(g + s + b < n && p[s + g + b] == p[s + g]) b++;

		if((g + s + b) * 2 > n) {
			cout << "0 0 0\n";
			continue;
		}

		while(true) {
			int pos = g + s + b;
			int q = 0;
			while(pos + q < n && p[pos + q] == p[pos]) q++;
			if((g + s + b + q) * 2 > n) break;
			else b += q;
		}

		if(g < s && g < b && g && b && s)
			cout << g << " " << s << " " << b << "\n";
		else
			cout << "0 0 0 \n";
	}
}