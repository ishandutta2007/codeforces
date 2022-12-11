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

	int n;
	cin >> n;
	string str;
	cin >> str;

	const int A = 26;
	vector<int> col(n), mex(A);
	array<vector<int>, A> usd;
	REP(i, A) usd[i].resize(n + 1);
	int ans = 0;
	REP(i, n) {
		int let = str[i] - 'a';
		col[i] = mex[let];
		FOR(j, 0, let - 1) {
			usd[j][col[i]] = true;
			debug(j, usd[j][col[i]], mex[j]);
			while(usd[j][mex[j]]) {
				mex[j]++;
				debug(mex[j]);
			}
		}
		ans = max(ans, col[i] + 1);
	}

	if(ans <= 2) {
		cout << "YES" << "\n";
		REP(i, n) cout << col[i];
		cout << "\n";
	}
	else cout << "NO\n";
}