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
	
	int n;
	cin >> n;

	vector<bool> on(n);
	int on_cnt = 0;
	REP(i, n) {
		char c;
		cin >> c;
		if(c == '1') on[i] = true, on_cnt++;
	}

	debug(on);

	vector<PII> light(n);
	REP(i, n)
		cin >> light[i].ST >> light[i].ND;


	int ans = on_cnt;
	FOR(i, 1,  10000) {
		REP(j, n) {
			if(i >= light[j].ND && (i - light[j].ND) % light[j].ST == 0) {
				on_cnt -= on[j];
				on[j] = on[j] ^ 1;
				on_cnt += on[j];
			}
		}

		debug(i, on);
		ans = max(ans, on_cnt);
	}

	cout << ans << "\n";
}