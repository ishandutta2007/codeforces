#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;

int cnt = 0;

vector <string> b;

bool query(int x1, int y1, int x2, int y2) {
	cnt++;
	assert(cnt <= n * n);
	assert(x1 >= 0 && y1 >= 0 && x1 < n && y1 < n);
	assert(x2 >= 0 && y2 >= 0 && x2 < n && y2 < n);
	cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
	int x;
	cin >> x;
	/*x = (b[x1][y1] == b[x2][y2]);
	if (x2 + y2 == x1 + y1 + 3) {
		x = (b[0][1] == '0');
	}*/
	//cout << x << endl;
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//srand(time(0));

	cin >> n;

	while (true) {

		cnt = 0;
		b.clear();
		b.resize(n);

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i] += (rand() % 2 ? '1' : '0');
			}
		}
		b[0][0] = '1';
		b[n - 1][n - 1] = '0';

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << b[i][j];
			}
			cout << endl;
		}*/

		vector <vector <int> > a(n, vector <int> (n, -1));
		a[0][0] = 1;
		a[n - 1][n - 1] = 0;
		a[0][1] = 0;
		for (int i = 0; i < n; i++) {
			if (i >= 2) {
				a[i][0] = (query(i - 2, 0, i, 0) ? a[i - 2][0] : !a[i - 2][0]);
				a[i][1] = (query(i - 2, 1, i, 1	) ? a[i - 2][1] : !a[i - 2][1]);
			} else if (i) {
				a[i][1] = (query(0, 0, 1, 1) ? 1 : 0);
			}
			for (int j = 2; j < n; j++) {
				if (i == n - 1 && j == n - 1) continue;
				if (i == 1 && j % 2 == 0) continue;
				a[i][j] = (query(i, j - 2, i, j) ? a[i][j - 2] : !a[i][j - 2]);
			}
			if (i == 1) {
				a[i][n - 1] = (query(i - 1, n - 2, i, n - 1) ? a[i - 1][n - 2] : !a[i - 1][n - 2]);
				for (int j = n - 1; j >= 2; j -= 2) {
					a[i][j - 2] = (query(i, j - 2, i, j) ? a[i][j] : !a[i][j]);
				}
			}
		}

		//cout << "===\n";

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}*/

		for (int it = 0; it < 2; it++) {
			bool found = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (found) continue;
					for (int msk = 0; msk < 8; msk++) {
						vector <int> t;
						int x = i, y = j;
						t.push_back(a[x][y]);
						for (int d = 0; d < 3; d++) {
							if (msk & (1 << d)) {
								x++;
							} else {
								y++;
							}
							if (x > n - 1 || y > n - 1) break;
							t.push_back(a[x][y]);
						}
						if (t.size() < 4) continue;
						if (t[0] == t[3] && t[1] == t[2]) {
							found = true;
							if (!query(i, j, x, y)) {
								for (int i = 0; i < n; i++) {
									for (int j = 0; j < n; j++) {
										if ((i + j) % 2) {
											a[i][j] = !a[i][j];
										}
									}
								}
							}
							break;
						}
					}
				}
			}
			if (found) break;
			if (!found) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if ((i + j) % 2) {
							a[i][j] = !a[i][j];
						}
					}
				}
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				assert(a[i][j] == b[i][j] - '0');
			}
		}*/

		cout << "!" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j];
			}
			cout << endl;
		}
		exit(0);
	}

}