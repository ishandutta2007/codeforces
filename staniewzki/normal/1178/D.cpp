#include<bits/stdc++.h>
using namespace std;
 
 
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
 
#ifdef Demplace_backUG
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

	vector<bool> prime(n * 2 + 1, true);
	for(int i = 2; i < n * 2 + 1; i++) {
		if(!prime[i]) continue;
		for(int j = i * 2; j < n * 2 + 1; j += i)
			prime[j] = false;
	}

	int r = n;
	while(!prime[r]) r++;

	vector<PII> edges;
	REP(i, n)
		edges.emplace_back(i, (i + 1) % n);

	int half = (n + 1) / 2;
	REP(i, n / 2) {
		if(size(edges) == r) break;
		edges.emplace_back(i, half + i);
	}

	cout << r << "\n";
	for(PII x : edges)
		cout << x.ST + 1 << " " << x.ND + 1 << "\n";
}