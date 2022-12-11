#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)30;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int val[N][N];
int x[N * N];
int y[N * N];
int n, m;

void swp(int v1, int v2) {
	swap(x[v1], x[v2]);
	swap(y[v1], y[v2]);
	swap(val[y[v1]][x[v1]], val[y[v2]][x[v2]]);
}

void moveA(const vector<int> &v, int d = 0) {
	for (int i = (int)v.size() - 2; i >= 0; i--) {		
		swp(v.back() + d, v[i] + d);
	}
}

void moveC(const vector<pair<int, int>> v, vector<vector<int>> &ans) {
	vector<int> a;
	for (int i = 0; i < (int)v.size(); i++) {
		a.push_back(val[v[i].second][v[i].first]);
		//cerr << a.back() + 1 << " ";
	}
	//cerr << "\n";
	ans.push_back(a);
	moveA(a);
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << val[i][j] + 1 << " ";
		}
		cout << "\n";
	}
}

void moveVal(int val, int xx, int yy, vector<vector<int>> &ans) {	
	while (y[val] > yy) {
		int dx = (x[val] > 0 ? -1 : 1);
		int xv = x[val];
		int yv = y[val];
		moveC({{xv, yv}, {xv, yv - 1}, {xv + dx, yv - 1}, {xv + dx, yv}}, ans);		
	}

	while (y[val] < yy) {
		int dx = (x[val] > 0 ? -1 : 1);
		int xv = x[val];
		int yv = y[val];
		moveC({{xv, yv}, {xv, yv + 1}, {xv + dx, yv + 1}, {xv + dx, yv}}, ans);
	}

	while (x[val] != xx) {
		int dx = (x[val] > xx ? -1 : 1);
		int dy = (y[val] == 0 ? 1 : -1);
		int xv = x[val];
		int yv = y[val];
		moveC({{xv, yv}, {xv + dx, yv}, {xv + dx, yv + dy}, {xv, yv + dy}}, ans);
	}
}

void swapY(int x, int y, vector<vector<int>> &ans) {
	for (int iq = 0; iq < 3; iq++) {
		moveC({{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}}, ans);
		moveC({{x, y}, {x - 1, y}, {x - 1, y - 1}, {x, y - 1}}, ans);
		moveC({{x, y}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y}}, ans);
		moveC({{x, y}, {x, y - 1}, {x - 1, y - 1}, {x - 1, y}}, ans);
		moveC({{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}}, ans);
	}
}

void swapY2(int x, int y, vector<vector<int>> &ans) {
	for (int iq = 0; iq < 3; iq++) {
		moveC({{x, y}, {x + 1, y}, {x + 1, y - 1}, {x, y - 1}}, ans);
		moveC({{x, y}, {x - 1, y}, {x - 1, y + 1}, {x, y + 1}}, ans);
		moveC({{x, y}, {x, y - 1}, {x + 1, y - 1}, {x + 1, y}}, ans);
		moveC({{x, y}, {x, y + 1}, {x - 1, y + 1}, {x - 1, y}}, ans);
		moveC({{x, y}, {x + 1, y}, {x + 1, y - 1}, {x, y - 1}}, ans);
	}
}

void swapX(int x, int y, vector<vector<int>> &ans) {
	for (int iq = 0; iq < 3; iq++) {
		moveC({{x, y}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y}}, ans);
		moveC({{x, y}, {x, y - 1}, {x - 1, y - 1}, {x - 1, y}}, ans);
		moveC({{x, y}, {x + 1, y}, {x + 1, y + 1}, {x, y + 1}}, ans);
		moveC({{x, y}, {x - 1, y}, {x - 1, y - 1}, {x, y - 1}}, ans);
		moveC({{x, y}, {x, y + 1}, {x + 1, y + 1}, {x + 1, y}}, ans);
	}
}

void swapX2(int x, int y, vector<vector<int>> &ans) {
	for (int iq = 0; iq < 3; iq++) {
		moveC({{x, y}, {x, y + 1}, {x - 1, y + 1}, {x - 1, y}}, ans);
		moveC({{x, y}, {x, y - 1}, {x + 1, y - 1}, {x + 1, y}}, ans);
		moveC({{x, y}, {x - 1, y}, {x - 1, y + 1}, {x, y + 1}}, ans);
		moveC({{x, y}, {x + 1, y}, {x + 1, y - 1}, {x, y - 1}}, ans);
		moveC({{x, y}, {x, y + 1}, {x - 1, y + 1}, {x - 1, y}}, ans);
	}
}

void moveK(int x, int y, char dir, vector<vector<int>> &ans) {
	if (dir == 'L') {
		if (x == 1) swapX(x, y, ans);
		else swapX2(x - 1, y, ans);
	} else if (dir == 'R') {
		if (x == 0) swapX(x + 1, y, ans);
		else swapX2(x, y, ans);
	} else if (dir == 'U') {
		if (y == 1) swapY(x, y, ans);
		else swapY2(x, y - 1, ans);
	} else if (dir == 'D') {
		if (y == 0) swapY(x, y + 1, ans);
		else swapY2(x, y, ans);
	} else {
		exit(11);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int z;
			cin >> z;
			z--;
			val[i][j] = z;
			x[z] = j;
			y[z] = i;
		}
	}

	vector<vector<int>> ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			moveVal(i * m + j, j, i, ans);
		}
	}

	for (int iq = 0; iq < 4; iq++) {
		moveVal(0, 0, 0, ans);
		moveVal(m - 1, m - 1, 0, ans);
		moveVal((n - 1) * m, 0, n - 1, ans);
		moveVal(n * m - 1, m - 1, n - 1, ans);
	}	

	int mk = 0;

	for (int i = 1; i < m - 1; i++) {
		if (y[i] == 0) moveK(x[i], y[i], 'D', ans);
		if (y[i] == n - 1) moveK(x[i], y[i], 'U', ans);
		while (x[i] < i) {
			if (y[i] + 2 == n) moveK(x[i], y[i], 'R', ans);
			else moveC({{x[i], y[i]}, {x[i] + 1, y[i]}, {x[i] + 1, y[i] + 1}, {x[i], y[i] + 1}}, ans);
		}
		while (x[i] > i) {
			if (y[i] + 2 == n) moveK(x[i], y[i], 'L', ans);
			else moveC({{x[i], y[i]}, {x[i] - 1, y[i]}, {x[i] - 1, y[i] + 1}, {x[i], y[i] + 1}}, ans);
		}
		while (y[i] != 0) {
			int dx = (x[i] == 0 ? 1 : -1);
			if (y[i] == 1) moveK(x[i], y[i], 'U', ans);			
			else moveC({{x[i], y[i]}, {x[i], y[i] - 1}, {x[i] + dx, y[i] - 1}, {x[i] + dx, y[i]}}, ans);
		}
	}	

	//print(); cout << "----\n";	

	for (int i = 1 + (n - 1) * m; i < n * m - 1; i++) {
		int xx = i - (n - 1) * m;
		if (y[i] == n - 1) moveK(x[i], y[i], 'U', ans);
		if (y[i] == 0) moveK(x[i], y[i], 'D', ans);
		while (x[i] < xx) {
			if (y[i] + 2 == n) moveK(x[i], y[i], 'R', ans);
			else moveC({{x[i], y[i]}, {x[i] + 1, y[i]}, {x[i] + 1, y[i] + 1}, {x[i], y[i] + 1}}, ans);
		}
		while (x[i] > xx) {
			if (y[i] + 2 == n) moveK(x[i], y[i], 'L', ans);
			else moveC({{x[i], y[i]}, {x[i] - 1, y[i]}, {x[i] - 1, y[i] + 1}, {x[i], y[i] + 1}}, ans);
		}
		while (y[i] != n - 1) {
			//moveK(x[i], y[i], 'D', ans);
			int dx = (x[i] == 0 ? 1 : -1);
			if (y[i] == n - 2) moveK(x[i], y[i], 'D', ans);			
			else moveC({{x[i], y[i]}, {x[i], y[i] + 1}, {x[i] + dx, y[i] + 1}, {x[i] + dx, y[i]}}, ans);	
		}
	}		

	//cout << mk << "\n";
	//print(); cout << "----\n";

	for (int i = 1; i < n - 1; i++) {
		//cout << i << endl;				
		for (int j = m - 1; j >= 0; j--) {
			int v = i * m + j;
			if (j == 0) v++;
			if (j == 1) v--;			
			int nidx = j;
			if (nidx < 2) nidx ^= 1;			

			if (y[v] != i) {
				while (x[v] > 1) {
					if (y[v] + 2 == n) moveK(x[v], y[v], 'L', ans);
					else moveC({{x[v], y[v]}, {x[v] - 1, y[v]}, {x[v] - 1, y[v] + 1}, {x[v], y[v] + 1}}, ans);
				}
				if (x[v] == 0) moveK(x[v], y[v], 'R', ans);

				while (y[v] > i) {
					if (y[v] - 1 == i) moveK(x[v], y[v], 'U', ans);
					else moveC({{x[v], y[v]}, {x[v], y[v] - 1}, {x[v] - 1, y[v] - 1}, {x[v] - 1, y[v]}}, ans);
				}
			}

			//if (v == 30) {print(); cout << "---\n" << y[v] << "\n";}

			while (x[v] < nidx) {				
				if (y[v] + 2 == n) moveK(x[v], y[v], 'R', ans);
				else moveC({{x[v], y[v]}, {x[v] + 1, y[v]}, {x[v] + 1, y[v] + 1}, {x[v], y[v] + 1}}, ans);
			}
			if (x[v] > nidx) {
				moveK(x[v], y[v], 'L', ans);
			}

			//if (v == 30) {print(); cout << "---\n";}
		}
	}

	if (D) print();
		else {
		cout << ans.size() << "\n";
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i].size() << " ";
			for (int j = 0; j < (int)ans[i].size(); j++) {
				cout << ans[i][j] + 1 << " ";
			}
			cout << "\n";
		}
	}
	int qq = 0;
	for (const auto q: ans) qq += q.size();
	if (D) cout << qq << "\n";
}

int main() {
	/*int num = 0;
	int s = 20;
	for (int i = 0; i < 512; i++) {
		int x = (i ^ 341);
		if (x > 0 && x <= s * s) {
			cout << x << " ";
			num++;
			if (num % s == 0) cout << "\n";
		}
	}
	return 0;*/
	/*int n = 20;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << n * n - j * n - i << " ";
		}
		cout << "\n";
	}
	return 0;*/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}