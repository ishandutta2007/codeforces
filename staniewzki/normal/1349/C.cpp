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

	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<int>> plane(n, vector<int>(m));
	REP(i, n) REP(j, m) {
		char c;
		cin >> c;
		plane[i][j] = c - '0';
	}

	array dx = {0, 0, +1, -1}, dy = {+1, -1, 0, 0};
	auto adj = [&](int i, int j) {
		vector<PII> ret;
		REP(d, 4) {
			int _i = i + dx[d], _j = j + dy[d];
			if(0 <= _i && _i < n && 0 <= _j && _j < m)
				ret.emplace_back(_i, _j);
		}
		return ret;
	};

	deque<PII> Q;
	vector<vector<int>> dst(n, vector<int>(m, -1));
	REP(i, n) REP(j, m) {
		bool found = false;
		for(auto &[_i, _j] : adj(i, j)) {
			if(plane[i][j] == plane[_i][_j])
				found = true;
		}

		if(found) {
			dst[i][j] = 0;
			Q.emplace_back(i, j);
		}
	}

	while(!Q.empty()) {
		auto [i, j] = Q.front();
		Q.pop_front();

		for(auto &[_i, _j] : adj(i, j)) {
			if(dst[_i][_j] == -1) {
				dst[_i][_j] = dst[i][j] + 1;
				Q.emplace_back(_i, _j);
			}
		}
	}

	REP(_t, t) {
		int i, j; LL p;
		cin >> i >> j >> p;
		i--, j--;
		cout << (plane[i][j] ^ (p < dst[i][j] || dst[i][j] == -1 ? 0 : (p - dst[i][j]) % 2)) << "\n";
	}
}