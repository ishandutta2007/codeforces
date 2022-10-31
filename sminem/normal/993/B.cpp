#include <bits/stdc++.h>
using namespace std;

bool s1[10][10], s2[10][10];
int n, m;

int istii(int a, int b, int c, int d) {
	if (a == b) return a;
	if (a == c) return a;
	if (a == d) return a;
	if (b == c) return b;
	if (b == d) return b;
	if (c == d) return c;
	return -1;
}

int cja[10];
int zu[10][10], zv[10][10];

set<int> ind1[10][10], ind2[10][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;

		if (x > y)
			swap(x, y);

		s1[x][y] = 1;
	}

	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;

		if (x > y)
			swap(x, y);

		s2[x][y] = 1;
	}

	for (int i=1; i<=9; i++) {
		for (int j=1; j<=9; j++) {
			for (int k=1; k<=9; k++) {
				for (int l=1; l<=9; l++) {

					if (i == j || k == l)
						continue;

					int sp = 0;
					sp += i == k;
					sp += i == l;
					sp += j == k;
					sp += j == l;

					if (sp != 1)
						continue;

					int isti = istii(i, j, k, l);

					if (s1[i][j] && s2[k][l]) {
						cja[isti]++;
						cerr << "!! " << i << ' ' << j << ' ' << k << ' ' << l << '\n';

						ind1[i][j].insert(isti);
						ind2[k][l].insert(isti);
					}
				}
			}
		}
	}

	if (count(cja+1, cja+10, 0) == 8) {
		for (int i=1; i<=9; i++)
			if (cja[i])
				cout << i;
		return 0;
	}

	{
		int bad = 0;
		for (int i=1; i<=9; i++) {
			for (int j=1; j<=9; j++) {
				if (ind1[i][j].size() > 1) {
					cerr << "B1 " << i << ' ' << j << '\n';
					bad++;
				}
				if (ind2[i][j].size() > 1) {
					cerr << "B2 " << i << ' ' << j << '\n';
					bad++;
				}
			}
		}

		if (bad)
			cout << "-1\n";
		else
			cout << "0\n";
	}
}

/*
2 3
1 2 4 5
1 3 2 3 4 6
*/

/*
2 3
1 2 2 3
1 3 1 4 3 4
*/