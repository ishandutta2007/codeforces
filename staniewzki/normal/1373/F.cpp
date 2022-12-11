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
		int n;
		cin >> n;
		vector<LL> a(n), b(n);
		REP(i, n) cin >> a[i];
		REP(i, n) cin >> b[i];

		auto check = [&](LL g) -> LL {
			REP(i, n - 1) {
				if(a[i] - g > b[i])
					return -1;
				g = b[i] - max(0LL, a[i] - g);
			}
			return max(0LL, a.back() - g);
		};

		if(check(2e9 + 1) == -1) {
			cout << "NO\n";
			continue;
		}

		LL l = 0, r = 2e9;
		while(l < r) {
			LL m = (l + r) / 2;
			if(check(m) >= 0) 
				r = m;
			else
				l = m + 1;
		}

		LL x = check(l);
		cout << (b.back() >= x + l ? "YES\n" : "NO\n");
	}
}