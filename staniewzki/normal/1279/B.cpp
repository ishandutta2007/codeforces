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
		int n, s;
		cin >> n >> s;
		vector<int> a(n);
		int sum = 0, mx = 0;
		int ans = -1, ski = -1;
		int used = -1;
		REP(i, n) {
			cin >> a[i];
			sum += a[i];
			if(a[i] > a[mx])
				mx = i;

			if(sum > s && used == -1) {
				sum -= a[mx];
				used = mx;
			}

			if(sum <= s) {
				int score = i - (used != -1);
				if(ans < score) {
					ans = score;
					ski = used;
				}
			}
		}
		cout << ski + 1 << "\n";	
	}
}