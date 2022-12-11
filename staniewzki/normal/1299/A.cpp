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
	vector<int> a(n), cnt(30);
	REP(i, n) {
		cin >> a[i];
		REP(j, 30) if(a[i] & (1 << j)) cnt[j]++;
	}
	vector<int> f(n);
	int best = 0;
	REP(i, n) {
		REP(j, 30) if((a[i] & (1 << j)) && cnt[j] == 1) f[i] += 1 << j;
		if(f[i] > f[best]) best = i;
	}
	cout << a[best] << " ";
	REP(i, n) if(i != best) cout << a[i] << " ";
	cout << "\n";
}