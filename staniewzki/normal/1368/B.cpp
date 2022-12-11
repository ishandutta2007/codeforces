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

	LL k;
	cin >> k;
	FOR(i, 1, 100) {
		LL f = 1;
		REP(j, 10) f *= (i + 1);
		if(f >= k) {
			f = 1;
			REP(j, 10) f *= i;
			debug(f, k);
			int x = 0;
			while(f < k) {
				f = f / i * (i + 1);
				x++;
			}

			string cf = "codeforces";
			REP(j, 10) {
				REP(q, i + (j < x)) cout << cf[j];
			}
			cout << "\n";
			return 0;
		}
	}
}