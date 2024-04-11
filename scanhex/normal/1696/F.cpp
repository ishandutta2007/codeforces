#include <bits/stdc++.h>

using namespace std;
using nagai = long long;

const int N = 101;
bool e[N][N][N];

vector<pair<int,int>> comp;
bool used[N][N];

int n;
void dfs(int i, int j) {
	if (i > j) swap(i, j);
	if (used[i][j])return;
	used[i][j] = true;
	comp.emplace_back(i, j);
	for(int k = 0; k < n; ++k) {
		if (e[i][k][j]) {
			dfs(i, k);
		}
		if (e[j][k][i]) {
			dfs(j, k);
		}
	}
}

bool check(vector<pair<int,int>> edg) {
	const int oo = 0x3f3f3f3f;
	vector<vector<int>> mat(n, vector<int>(n, oo));
	for(int i = 0; i < n; ++i) mat[i][i] = 0;
	for(auto [x, y] : edg) {
		if (x == y) return false;
		mat[x][y] = mat[y][x] = 1;
	}
	for(int k = 0; k < n; ++k) 
		for (int i = 0; i < n; ++i) 
			for(int j = 0; j < n; ++j) 
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	for(int i = 0; i < n; ++i) if (mat[0][i] == oo) return false;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < n; ++k) {
				if (j == k)
					continue;
				if (e[i][j][k] != (mat[i][j] == mat[i][k]))
					return false;
			}
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		 cin >> n;
		 for(int i = 0; i < n - 1; ++i) {
			 for(int j = 1; j <= n - i - 1; ++j) {
				 string s; 
				 cin >> s;
				 for(int k = 0; k < s.size(); ++k) 
					 e[k][i][i + j] = e[k][i + j][i] = s[k] == '1';
			 }
		 }
		 for(int i = 0; i < n; ++i)
			 fill(used[i], used[i] + n, false);
		 vector<pair<int, int>> rescomp;
		 for(int i = 0; i < n; ++i) 
			 for(int j = i + 1; j < n; ++j) {
				 if (rescomp.size()) continue;
				 if (used[i][j]) continue;
				 comp.clear();
				 dfs(i, j);
				 if (comp.size() == n - 1) { 
					 if (check(comp))
						 rescomp = comp;
				 }
			 }
		 if (rescomp.size()) {
			 cout << "Yes\n";
			 for(auto& [x, y] : rescomp) 
				 cout << x + 1 << ' ' << y + 1 << '\n';
		 }
		 else 
			 cout << "No\n";
	}
}