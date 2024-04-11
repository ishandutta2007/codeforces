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

mt19937 _gen(chrono::system_clock::now().time_since_epoch().count());
int rd(int a, int b) {
	return uniform_int_distribution<int>(a, b)(_gen);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(_t, t) {
		int n;
		cin >> n;
		string str;
		cin >> str;

		bool found = false;
		FOR(d, 0, 10) {
			int last_small = 0;
			int last_big = 0;

			bool ok = true;
			string ans = str;
			REP(i, n) {
				ans[i] = '1';
				if(str[i] - '0' < d || (str[i] - '0' == d && last_big > str[i])) {
					if(last_small > str[i]) {
						ok = false;
						break;
					}
					else last_small = str[i];
				}
				else {
					ans[i] = '2';
					if(last_big > str[i]) {
						ok = false;
						break;
					}
					else last_big = str[i];
				}
			}

			if(ok) {
				cout << ans << "\n";
				found = true;
				break;
			}
		}

		if(!found) cout << "-\n";

	}
}