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

int get(int i) {
	cout << i << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);

	int m, n;
	cin >> m >> n;

	vector<int> p(n);
	REP(i, n) {
		int r = get(1);	
		if(r == 0) return 0;
		p[i] = r;
	}

	int l = 1, r = m;
	int it = 0;
	while(true) {
		int x = (l + r) / 2;
		debug(l, r, x);
		int rt = get(x) * p[it];
		if(rt == 0) return 0;
		if(rt == -1) r = x - 1;
		else l = x + 1;
		it = (it == n - 1 ? 0 : it + 1);
	}
}