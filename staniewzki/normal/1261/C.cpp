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

	int n, m;
	cin >> n >> m;

	vector<vector<char>> plane(n, vector<char>(m));
	vector<vector<int>> dst(n, vector<int>(m, -1));
	deque<PII> Q;

	REP(i, n) REP(j, m) {
		cin >> plane[i][j];
		if(plane[i][j] == '.') {
			dst[i][j] = 0;
			Q.emplace_back(i, j);
		}
	}

	REP(i, n) REP(j, m) {
		if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && plane[i][j] == 'X') {
			dst[i][j] = 1;
			Q.emplace_back(i, j);
		}
	}

	vector<int> dX = {-1, 0, 1, -1, 1, -1, 0, 1};
	vector<int> dY = {-1, -1, -1, 0, 0, 1, 1, 1};
	while(!Q.empty()) {
		int x, y;
		tie(x, y) = Q.front();
		Q.pop_front();

		REP(dir, 8) {
			int _x = x + dX[dir];
			int _y = y + dY[dir];

			if(0 <= _x && _x < n && 0 <= _y && _y < m) {
				if(dst[_x][_y] == -1) {
					dst[_x][_y] = dst[x][y] + 1;
					Q.emplace_back(_x, _y);
				}
			}
		}
	}

	auto check = [&](int t) {
		vector<vector<int>> pref(n + 1, vector<int>(m + 1));
		REP(i, n) REP(j, m) {
			if(dst[i][j] >= t) {
				pref[max(0, i - t + 1)][max(0, j - t + 1)]++;
				pref[max(0, i - t + 1)][min(m, j + t)]--;
				pref[min(n, i + t)][max(0, j - t + 1)]--;
				pref[min(n, i + t)][min(m, j + t)]++;
			}
		}

		REP(i, n) REP(j, m) {
			if(i) pref[i][j] += pref[i - 1][j];
			if(j) pref[i][j] += pref[i][j - 1];
			if(i && j) pref[i][j] -= pref[i - 1][j - 1];
			if(bool(pref[i][j]) ^ (plane[i][j] == 'X')) return false;
		}

		return true;
	};

	int l = 1, r = 1e6 + 5;
	while(l < r) {
		int t = (l + r + 1) / 2;
		if(check(t))
			l = t;
		else
			r = t - 1;
	}

	cout << l - 1 << "\n";
	REP(i, n) { 
		REP(j, m) {
			if(dst[i][j] >= l)
				cout << 'X';
			else
				cout << '.';
		}
		cout << "\n";
	}
}