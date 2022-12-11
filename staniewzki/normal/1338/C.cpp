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

	vector<LL> T = {0, 3, 1, 2};

	int t;
	cin >> t;
	REP(_t, t) {
		LL n;
		cin >> n;

		auto print_ans = [&](vector<LL> v) {
			cout << v[n % 3] << "\n";
		};

		n--;
		LL tripple = n / 3;
		if(tripple-- == 0)
			print_ans({1, 2, 3});
		else {
			LL q = 1;
			while(true) {
				q *= 4;
				if(tripple < q) {
					LL a = q + tripple;
					LL c = q * 3;
					debug(q, a, c);

					LL x = q;
					while(x != 1) {
						x /= 4;
						LL seg = tripple / x;
						c += T[seg] * x;	
						tripple %= x;
					}

					print_ans({a, a ^ c, c});
					break;
				}
				else tripple -= q;
			}
		}
	}
}