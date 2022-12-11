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
template<class T> int sz(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(it, t) {
		int r, c;
		cin >> r >> c;

		vector<vector<char>> p(r, vector<char>(c));
		REP(i, r) REP(j, c) cin >> p[i][j];

		bool ok = true;
		REP(i, r) REP(j, c) if(p[i][j] == 'A')
			ok = false;
		if(ok) {
			cout << "MORTAL\n";
			continue;
		}

		ok = true;
		REP(i, r) REP(j, c) if(p[i][j] == 'P')
			ok = false;
		if(ok) {
			cout << "0\n";
			continue;
		}

		vector<int> sum_r(r), sum_c(c);
		REP(i, r) REP(j, c) if(p[i][j] == 'P')
			sum_r[i]++, sum_c[j]++;

		if(sum_r[0] == 0 || sum_r[r - 1] == 0 || sum_c[0] == 0 || sum_c[c - 1] == 0) {
			cout << "1\n";
			continue;
		}

		ok = false;
		REP(i, r) REP(j, c) if(p[i][j] == 'A') {
			if((i == 0 || i == r - 1) && (j == 0 || j == c - 1))
				ok = true;
		}

		REP(i, r) if(sum_r[i] == 0) ok = true;
		REP(i, c) if(sum_c[i] == 0) ok = true;

		if(ok) {
			cout << "2\n";
			continue;
		}
		
		ok = false;
		REP(i, r) REP(j, c) if(p[i][j] == 'A') {
			if((i == 0 || i == r - 1) || (j == 0 || j == c - 1))
				ok = true;
		}

		if(ok) {
			cout << "3\n";
			continue;
		}


		cout << "4\n";
	}
}