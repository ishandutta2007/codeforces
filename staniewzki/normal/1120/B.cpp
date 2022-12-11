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

bool good(int x) {
	return '0' <= x && x <= '9';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string a, b;
	cin >> a >> b;

	auto gen_c = [](string a, string b) {
		LL c = 0;
		int n = size(a);
		int r = 0;
		REP(i, n - 1) {
			r = max(r, i + 1);
			while(a[i] != b[i]) {
				int v = (a[i] < b[i] ? +1 : -1);
				a[i] += v;
				if(good(a[i + 1] + v)) {
					a[i + 1] += v;	
					c++;
					continue;
				}
				if((r - i) % 2 == 0) v *= -1;
				while(!good(a[r] + v)) {
					if(++r == n) {
						cout << "-1\n";
						exit(0);
					}
					v *= -1;	
				}
				a[r] += v;
				c += r - i;
			}
			debug(i, a);
		}

		if(a[n - 1] != b[n - 1]) {
			cout << "-1\n";
			exit(0);
		}

		cout << c << "\n";
	};

	auto gen_sec = [](string a, string b) {
		int n = size(a);
		vector<PII> m;
		REP(i, n - 1) {
			while(a[i] != b[i] && size(m) < 1e5) {
				int pos = i, v = (a[i] < b[i] ? +1 : -1);
				while(!good(a[pos + 1] + v))
					pos++, v *= -1;
				debug(pos, v);
				for(int j = pos; j >= i; j--) {
					debug(j, a[j], a[j + 1], v);
					a[j] += v, a[j + 1] += v;
					m.emplace_back(j, v);
					v *= -1;
				}
			}
			debug(a);
		}
		REP(i, min<int>(1e5, size(m)))
			cout << m[i].ST + 1 << " " << m[i].ND << "\n";
	};

	gen_c(a, b);
	gen_sec(a, b);
}