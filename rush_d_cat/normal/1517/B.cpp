#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100 + 10;
int res[N][N], b[N][N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t --) {
		int n, m;
		cin >> n >> m;
		vector< vector<int> > a(n * m);
		int id = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j ++) {
				int x; cin >> x;
				b[i][j] = x;
				a[id ++] = {x, i, j};
			}
		}
		for (int i = 0; i < n; i ++) 
			for (int j = 0; j < m; j ++) 
				res[i][j] = -1;
		sort(a.begin(), a.end());

		LL ans = 0;
		for (int i = 0; i < m; i ++) {
			res[ a[i][1] ][ a[i][2] ] = i;
		}
		for (int j = 0; j < n; j ++) {
			set<int> s;
			for (int i = 0; i < m; i ++) s.insert(i);
			for (int i = 0; i < m; i ++) {
				if (res[j][i] != -1) {
					s.erase(res[j][i]);
				}
			}
			for (int i = 0; i < m; i ++) {
				if (res[j][i] == -1) {
					res[j][i] = (*s.begin()); s.erase(s.begin());
				}
			}
			vector<int> tmp(m, -1);
			for (int i = 0; i < m; i ++) {
				tmp[res[j][i]] = b[j][i];
			}
			for (int i = 0; i < m; i ++) {
				cout << tmp[i] << " \n"[i==m-1];
			}
		}
	}
}