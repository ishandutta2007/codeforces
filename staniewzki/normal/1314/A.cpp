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

	vector<PII> v(n);
	REP(i, n) cin >> v[i].ST;
	REP(i, n) cin >> v[i].ND;

	sort(v.begin(), v.end());

	multiset<int> cost;
	int pos = 0;
	LL ans = 0, sum = 0;
	REP(i, n + 1) {
		int cur_pos = (i == n ? 2e9 : v[i].ST);
		while(pos < cur_pos && size(cost)) {
			auto it = cost.end();
			it = prev(it);
			sum -= *it;
			cost.erase(it);
			ans += sum;
			pos++;
		}
		pos = cur_pos;
		if(i != n) {
			cost.emplace(v[i].ND);
			sum += v[i].ND;
		}
	}

	cout << ans << "\n";
}