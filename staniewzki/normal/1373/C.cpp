#include<bits/stdc++.h>
using namespace std;
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.ST << ", " << p.ND << ")";
}

template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto &e : x)
        	out << e << (&e == &*--x.end() ? "" : ", ");
	return out << '}';
}

template<class... Args> void dump(Args&&... args) {
	((cerr << args << ";  "), ...);
}
 
#ifdef DEBUG
#  define debug(x...) cerr << "[" #x "]: ", dump(x), cerr << "\n"
#else
#  define debug(...) false
#endif
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(_t, t) {
		string str;
		cin >> str;

		int pref = 0, opt = 0, x = 0;
		REP(i, size(str)) {
			if(str[i] == '+') pref++;
			else pref--;
			opt = max(opt, -pref);
		}

		pref = 0;
		LL ans = size(str);
		REP(i, size(str)) {
			if(str[i] == '+') pref++;
			else pref--;
			ans += opt - x;
			x = max(x, -pref);
		}

		cout << ans << "\n";
	}
}