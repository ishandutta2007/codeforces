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
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, m, k;
	cin >> n >> m >> k;
 
	vector<PII> s(n);
	REP(i, n) cin >> s[i].ST >> s[i].ND, s[i].ND++;
	sort(s.begin(), s.end());
 
	vector<PII> events;
	REP(i, n) {
		events.emplace_back(s[i].ST, i);
		events.emplace_back(s[i].ND, i);
	}
	sort(events.begin(), events.end());

	vector<int> dp(1 << k, -1);
	int last_pos = 0, ans = 0;
	dp[0] = 0;

	vector<int> bit(k, -1);
 
	for(auto &[pos, id] : events) {
		REP(i, (1 << k)) {
			if(dp[i] != -1 && __builtin_popcount(i) % 2) {
				dp[i] += pos - last_pos;
				ans = max(ans, dp[i]);
			}
		}
		last_pos = pos;
 
		if(pos == s[id].ST) {
			int q = -1;
			REP(i, k) if(bit[i] == -1) {
				q = i, bit[i] = id;
				break;
			}

			REP(i, (1 << k)) {
				if((i & (1 << q)) == 0)
					dp[i + (1 << q)] = dp[i];
			}
		}
		else {
			int q = -1;
			REP(i, k) if(bit[i] == id) {
				q = i, bit[i] = -1;
				break;
			}

			REP(i, (1 << k)) {
				if(i & (1 << q)) {
					dp[i - (1 << q)] = max(dp[i - (1 << q)], dp[i]);
					dp[i] = -1;
				}
			}
		}
	}
 
	cout << ans << "\n";
}