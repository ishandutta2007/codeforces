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

template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto &e : x)
        	out << e << (&e == &*--x.end() ? "" : ", ");
	return out << '}';
}

template<class... Args> void dump(Args&&... args) {
	((cerr << args << ";  "), ...);
}
 
#ifdef DEBUG
#  define debug(x...) cerr << "[" #x "]: ", dump(x), cerr << "\n"
#else
#  define debug(...) false
#endif
 
template<class T> int size(T && a) { return (int) a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	REP(_t, t) {
		int n, m;
		cin >> n >> m;

		vector<int> deg(n);
		vector<vector<int>> out(n);
		REP(i, m) {
			int x, y;
			cin >> x >> y;
			out[x - 1].emplace_back(y - 1);
			deg[y - 1]++;
		}

		vector<int> ans, dst(n);
		REP(i, n) {
			if(dst[i] == 2)
				ans.emplace_back(i);
			else
				for(int j : out[i])
					dst[j] = max(dst[j], dst[i] + 1);
		}

		cout << size(ans) << "\n";
		for(int x : ans) cout << x + 1 << " ";
		cout << "\n";
	}
}