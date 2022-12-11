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
	vector<LL> a(n), b(n);
	LL ans = 0;
	LL sum = 0;
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i], sum += b[i];

	vector<int> cnt(n); // od ilu uwaza sie za lepszego
	REP(i, n) REP(j, n) if((a[i] | a[j]) != a[j]) cnt[i]++;
	vector<bool> del(n);
	bool chg = true;
	int s = n;
	while(chg) {
		chg = false;
		REP(i, n) {
			if(del[i]) continue;		
			if(cnt[i] == s - 1) {
				s--;
				del[i] = true;
				sum -= b[i];
				REP(j, n) if((a[j] | a[i]) != a[i]) cnt[j]--;
				chg = true;
				break;
			}
		}
	}

	if(s <= 1) sum = 0;
	cout << sum << "\n";
}