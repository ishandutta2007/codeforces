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

struct RMQ {
	vector<vector<int>> st;
	vector<int> pre;
	RMQ(vector<int> &a) {
		int n = size(a), lg = 0;
		while((1 << lg) < n) lg++;
		st.resize(lg + 1, vector<int>(a));
		st[0] = a;
		FOR(i, 1, lg) REP(j, n) {
			st[i][j] = st[i - 1][j];
			int q = j + (1 << (i - 1));
			if(q < n) st[i][j] = min(st[i][j], st[i - 1][q]);
		}
		pre.resize(n + 1);
		FOR(i, 2, n) pre[i] = pre[i / 2] + 1;
	}
 
	int query(int l, int r) {
		int q = pre[r - l + 1], x = r - (1 << q) + 1;
		return min(st[q][l], st[q][x]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	REP(it, t) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n);
		REP(i, n) cin >> a[i];

		vector<int> b(m);
		int q = n - m;
		REP(i, m) b[i] = max(a[i], a[i + q]);
		RMQ rmq(b);

		int l = max(1, m - k) - 1, ans = 0;
		REP(i, m - l) {
			ans = max(ans, rmq.query(i, i + l));
		}

		cout << ans << "\n";
	}
}