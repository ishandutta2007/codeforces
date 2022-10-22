#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("A.in", "r", stdin);
	//freopen("A.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector <map <int, int> > numr(n), numc(m);
	vector <int> allr(n, 0), allc(m, 0);
	for (int i = 0; i < n; i++) {
		vector <int> row = a[i];
		sort(row.begin(), row.end());
		int last = 1;
		numr[i][row[0]] = last;
		for (int j = 1; j < m; j++) {
			if (row[j] != row[j - 1]) {
				last++;
				numr[i][row[j]] = last;
			}
		}
		allr[i] = last;
	}
	for (int j = 0; j < m; j++) {
		vector <int> col;
		for (int i = 0; i < n; i++) {
			col.push_back(a[i][j]);
		}
		sort(col.begin(), col.end());
		int last = 1;
		numc[j][col[0]] = last;
		for (int i = 1; i < n; i++) {
			if (col[i] != col[i - 1]) {
				last++;
				numc[j][col[i]] = last;
			}
		}
		allc[j] = last;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = a[i][j];
			int l = max(numr[i][x], numc[j][x]);
			int r = max(allr[i] - numr[i][x], allc[j] - numc[j][x]);
			cout << l + r << " ";
		}
		cout << "\n";
	}
}