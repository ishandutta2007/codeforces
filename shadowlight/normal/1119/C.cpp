#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n, vector <int> (m, 0));
	vector <vector <int> > b(n, vector <int> (m, 0));
	int suma = 0, sumb = 0;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			suma += a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			sumb += b[i][j];
		}
	}
	if (a == b) {
		cout << "Yes\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		int sa = 0, sb = 0;
		for (int j = 0; j < m; j++) {
			sa += a[i][j];
			sb += b[i][j];
		}
		if (sa % 2 != sb % 2) {
			cout << "No\n";
			return 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int sa = 0, sb = 0;
		for (int j = 0; j < n; j++) {
			sa += a[j][i];
			sb += b[j][i];
		}
		if (sa % 2 != sb % 2) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}