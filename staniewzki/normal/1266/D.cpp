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
template<class T> int sz(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m; 
	cin >> n >> m;

	vector<LL> a(n);
	REP(i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u - 1] -= w;
		a[v - 1] += w;
	}

	vector<int> p(n);
	REP(i, n) p[i] = i;
	sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });

	int r = n - 1;
	vector<int> u, v;
	vector<LL> w;
	REP(l, n) {
		if(l >= r) break;
		int L = p[l];
		while(a[L] != 0) {
			int R = p[r];
			LL z = min(a[R], -a[L]);
			debug(L, R, z);
			if(z) {
				a[R] -= z, a[L] += z;
				u.emplace_back(L);
				v.emplace_back(R);
				w.emplace_back(z);
			}
			if(a[R] == 0) r--;
		}
	}

	cout << size(u) << "\n";
	REP(i, size(u))
		cout << u[i] + 1 << " " << v[i] + 1 << " " << w[i] << "\n";
}