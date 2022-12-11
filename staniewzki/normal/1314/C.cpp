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

	int n, m;
	LL k;
	cin >> n >> m >> k;
	string str;
	cin >> str;
	str += "$";

	vector<vector<int>> lcp(n + 1, vector<int>(n + 1));
	for(int i = n - 1; i >= 0; i--) {
		lcp[i][i] = size(str) - i;
		REP(j, n) {
			if(str[i] == str[j]) 
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
		}
	}

	vector<PII> sub;
	REP(i, n) FOR(j, i, n - 1)
		sub.emplace_back(i, j);

	sort(sub.begin(), sub.end(), [&](PII a, PII b) {
		int A = a.ND - a.ST + 1, B = b.ND - b.ST + 1;
		int l = lcp[a.ST][b.ST];
		if(l >= min(A, B)) return A < B;
		return str[a.ST + l] < str[b.ST + l];
	});

	auto check = [&](PII a) {
		vector<vector<LL>> dp(n + 1, vector<LL>(m + 1));
		dp[n][0] = 1;
		auto sum = dp;

		for(int i = n - 1; i >= 0; i--) {
			int prev = -1;
			REP(j, n - i) {
				if(str[i + j] < str[a.ST + j]) break;
				if(str[i + j] > str[a.ST + j] || a.ST + j == a.ND) {
					prev = i + j + 1;
					break;
				}
			}
			
			if(prev != -1) FOR(j, 1, m)
				dp[i][j] = sum[prev][j - 1];

			FOR(j, 0, m) {
				sum[i][j] = dp[i][j] + sum[i + 1][j];
				sum[i][j] = min<LL>(sum[i][j], 1e18);
			}
		}

		return dp[0][m] >= k;
	};

	int l = 0, r = size(sub) - 1;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(check(sub[mid])) 
			l = mid;
		else
			r = mid - 1;
	}

	FOR(i, sub[l].ST, sub[l].ND)
		cout << str[i];
	cout << "\n";
}