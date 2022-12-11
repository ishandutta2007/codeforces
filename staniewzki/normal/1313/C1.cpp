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
	vector<LL> h(n + 2);
	FOR(i, 1, n) cin >> h[i];

	auto gen = [&]() {
		vector<int> last_smaller(n + 2), q;
		REP(i, n + 2) {
			while(size(q) && h[q.back()] >= h[i])
				q.pop_back();
			last_smaller[i] = (size(q) ? q.back() : - 1);
			q.emplace_back(i);
		}
		vector<LL> dp(n + 2);
		REP(i, n) {
			int j = last_smaller[i];
			if(j == -1) dp[i] = h[i] * (i + 1);
			else dp[i] = dp[j] + h[i] * (i - j);
		}
		
		reverse(h.begin(), h.end());
		return dp;
	};

	auto x1 = gen();
	auto x2 = gen();
	reverse(x2.begin(), x2.end());

	pair<LL, int> best = {0, -1};
	FOR(i, 0, n) {
		best = max(best, {x1[i] + x2[i + 1], i});
	}

	int split = best.ND;
	LL m = 1e9;
	for(int i = split + 1; i <= n; i++) {
		m = min(m, h[i]);
		h[i] = m;
	}

	m = 1e9;
	for(int i = split; i >= 1; i--) {
		m = min(m, h[i]);
		h[i] = m;
	}

	FOR(i, 1, n) cout << h[i] << " ";
	cout << "\n";
}