#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) cout << c;
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
 
mt19937 _gen(2137);
int rd(int a, int b) { return uniform_int_distribution<int>(a, b)(_gen); }
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	LL n, m, k;
	cin >> n >> m >> k;
 
	LL del = 0;
	LL tmp = 0;
	LL moves = 1;
	LL beg = -1;
	REP(i, m) {
		LL p;
		cin >> p;
		if(beg == -1) beg = ((p - 1) / k) * k;
		if(p - del > k + beg) {
			del += tmp;
			moves++;
			p -= del;
			beg = ((p - 1) / k) * k;
			tmp = 1;
		}
		else tmp++;

	}
 
	cout << moves  << "\n";
 
}