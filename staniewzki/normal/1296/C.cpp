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
		string str;
		cin >> str;
		map<PII, int> last;
		PII pos = {0, 0};
		last[pos] = -1;
		int l = -1, r = -1;
		REP(i, n) {
			if(str[i] == 'L') pos.ST--;
			if(str[i] == 'R') pos.ST++;
			if(str[i] == 'U') pos.ND++;
			if(str[i] == 'D') pos.ND--;
			if(last.find(pos) != last.end()) {
				int _l = last[pos], _r = i;
				debug(_l, _r);
				if(_r - _l < r - l || (l == -1 && r == -1))
					r = _r, l = _l;
			}
			last[pos] = i;
		}

		if(l == -1 && r == -1)
			cout << "-1\n";
		else 
			cout << l + 2 << " " << r + 1 << "\n";
	}
}