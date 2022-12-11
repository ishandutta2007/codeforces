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

int match(PII x, PII y) {
	int ans = 0;
	if(x.ST == y.ST || x.ST == y.ND) ans++;
	if(x.ND == y.ST || x.ND == y.ND) ans++;
	return ans;
}

int get_match(PII x, PII y) {
	assert(match(x, y) == 1);
	if(x.ST == y.ST || x.ST == y.ND) return x.ST;
	else return x.ND;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<PII> A(n), B(m);
	REP(i, n) cin >> A[i].ST >> A[i].ND;
	REP(i, m) cin >> B[i].ST >> B[i].ND;

	set<int> an;
	REP(i, n) REP(j, m) {
		if(match(A[i], B[j]) == 1) 
			an.emplace(get_match(A[i], B[j]));
	}

	if(size(an) == 1) {
		cout << *an.begin() << "\n";
		return 0;
	}

	bool always = true;
	REP(i, n) REP(j, m) {
		int ans = -1;
		REP(k, m) if(match(A[i], B[k]) == 1) {
			if(ans == -1) ans = get_match(A[i], B[k]);
			else if(ans != get_match(A[i], B[k])) ans = 0;
		}
		if(ans == 0) always = false;
		ans = -1;
		REP(k, n) if(match(A[k], B[j]) == 1) {
			if(ans == -1) ans = get_match(A[k], B[j]);
			else if(ans != get_match(A[k], B[j])) ans = 0;
		}
		if(ans == 0) always = false;
	}

	if(always) cout << "0\n";
	else cout << "-1\n";
}