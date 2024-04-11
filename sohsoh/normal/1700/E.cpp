#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll LIM = 10;

int n, m, cnt;
vector<vector<int>> A;
vector<pll> poss, bads;

inline bool f(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

inline bool check(int x, int y) {
	if (!f(x, y)) return true;
	return A[x][y] == 1 || A[x - 1][y] < A[x][y] || A[x + 1][y] < A[x][y] 
			|| A[x][y + 1] < A[x][y] || A[x][y - 1] < A[x][y];
}

inline bool tcheck(int x, int y) {
	return check(x, y) && check(x - 1, y) && check(x + 1, y) && check(x, y - 1) && check(x, y + 1);
}

inline bool fcheck(int x1, int y1, int x2, int y2) {
	if (!tcheck(x1, y1) || !tcheck(x2, y2)) return false;
	for (pll e : bads)
		if (!check(e.X, e.Y))
			return false;

	return true;
}

inline pair<pll, pll> wtf(pll a, pll b) {
	return {min(a, b), max(a, b)};
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	A.resize(n + 5);
	for (vector<int>& vec : A) {
		vec.resize(m + 5);
		for (int& e : vec)
			e = MAXN;
	}


	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!check(i, j)) {
				cnt++;
				poss.push_back({i, j});
				bads.push_back({i, j});
			
				if (f(i - 1, j)) poss.push_back({i - 1, j});
				if (f(i + 1, j)) poss.push_back({i + 1, j});
				if (f(i, j - 1)) poss.push_back({i, j - 1});
				if (f(i, j + 1)) poss.push_back({i, j + 1});
				
			}
		}
	}

	if (cnt == 0) return cout << 0 << endl, 0;
	if (cnt > LIM) return cout << 2 << endl, 0;

	set<pair<pll, pll>> st;
	for (pll e : poss) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				swap(A[i][j], A[e.X][e.Y]);
				if (fcheck(i, j, e.X, e.Y))
					st.insert(wtf({i, j}, {e.X, e.Y}));
				swap(A[i][j], A[e.X][e.Y]);
			}
		}
	}

	if (!st.empty()) return cout << 1 << sep << st.size() << endl, 0;

	cout << 2 << endl;
	return 0;
}