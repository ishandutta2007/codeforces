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
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

vector<string> digits = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int dst(string a, string b) {
	int ret = 0;
	REP(i, size(a)) {
		if(a[i] == '0' && b[i] == '1')
			ret++;
		if(a[i] == '1' && b[i] == '0')
			return -1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<string> cur(n);
	REP(i, n) cin >> cur[i];

	vector<vector<bool>> dp(n + 1, vector<bool>(k + 1));
	dp[n][0] = true;
	for(int i = n - 1; i >= 0; i--) {
		REP(d, 10) {
			int x = dst(cur[i], digits[d]);
			if(x == -1) continue;
			FOR(j, x, k)
				if(dp[i + 1][j - x]) 
					dp[i][j] = true;
		}
	}

	if(!dp[0][k]) {
		cout << "-1\n";
		return 0;
	}

	REP(i, n) {
		for(int d = 9; d >= 0; d--) {
			int x = dst(cur[i], digits[d]);
			if(x != -1 && k >= x && dp[i + 1][k - x]) {
				cout << d;
				k -= x;
				break;
			}
		}
	}
	cout << "\n";
}