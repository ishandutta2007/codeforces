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

	int m, k, n, s;
	cin >> m >> k >> n >> s;

	int N = 5e5, dif = 0;
	vector<int> a(m), b(s), cnt(N), t(N);
	REP(i, m) cin >> a[i], a[i]--;
	REP(i, s) {
		cin >> b[i], b[i]--;
		if(t[b[i]]++ == 0)
			dif++;
	}

	int r = -1, good = 0;
	REP(l, m) {
		while(r + 1 < m && good != dif) {
			int x = a[++r];
			if(++cnt[x] == t[x]) good++;
		}

		if(l % k == 0 && good == dif && r - l + 1 - k <= m - n * k) {
			int to_del = max(r - l + 1 - k, 0);
			cout << to_del << "\n";
			FOR(i, l, r) {
				int x = a[i];
				if(t[x]-- <= 0 && to_del-- >= 1) 
					cout << i + 1 << " ";
			}
			cout << "\n";
			return 0;	
		}

		int x = a[l];
		if(cnt[x]-- == t[x]) good--;
	}

	cout << "-1\n";
}