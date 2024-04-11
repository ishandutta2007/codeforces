#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m, h;
	cin >> n >> m >> h;
	vector <int> a(m), b(n);
	vector <vector <int> > c(n, vector <int> (m, 0));
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (!c[i][j]) {
				cout << "0 ";
			} else {
				cout << min(b[i], a[j]) << " ";
			}
		}
		cout << "\n";
	}
}