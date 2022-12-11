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

	int n;
	cin >> n;

	vector<PII> out = {{0, 2}};
	REP(i, n + 1) {
		int x = i * 2;
		out.emplace_back(x + 1, 2);
		out.emplace_back(x + 2, 2);
		if(i % 2 == 0) {
			out.emplace_back(x, 0);
			out.emplace_back(x, 1);
			out.emplace_back(x + 1, 0);
			out.emplace_back(x + 2, 0);
			out.emplace_back(x + 2, 1);
		}
		else {
			out.emplace_back(x, 3);
			out.emplace_back(x, 4);
			out.emplace_back(x + 1, 4);
			out.emplace_back(x + 2, 3);
			out.emplace_back(x + 2, 4);
		}
	}

	cout << size(out) << "\n";
	for(auto [x, y] : out) cout << x << " " << y << "\n";
}