#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)
#define ford(i,n) for (int i = (int)(n) - 1; i >= 0; i--)
#define B(x,y,z) ((y < 0) ? 0 : b[x][y][z])
#define Q(n) t[(i + n) % (2 * n)] 

string sa[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int a[10][10];
int b[10][10][11];
int t[200010];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	forn (i, 10) {
		forn (j, 10) {
			a[i][j] = 0;
			forn (k, 7) {
				a[i][j] += (sa[i][k] == '1' && sa[j][k] == '1');
			}
		}
	}
	forn (i, 10) {
		forn (j, 10) {
			forn (k, 11) {
				b[i][j][k] = k;
				while (b[i][j][k] < 10 && a[i][b[i][j][k]] < j) {
					b[i][j][k]++;
				}
			}
		}
	}
	string s;
	getline(cin, s);
	forn (i, s.size()) {
		t[i] = s[i] - '0';
	}
	int n = s.size() / 2;
	int w = -1;
	ford (i, 2 * n) {
		int x = B(Q(n), a[t[(i + n) % (2 * n)]][t[i]] - w, t[i] + 1);
		if (x < 10) {
			w += a[Q(n)][x] -  a[Q(n)][t[i]];
			t[i] = x;
			for (i++; i < 2 * n; i++) {
				int y = B(Q(n), a[Q(n)][t[i]] - w, 0);
				w += a[Q(n)][y] -  a[Q(n)][t[i]];
				t[i] = y;
			}
			for (i = 0; i < 2 * n; i++) {
				printf("%d", t[i]);
			}
			return 0;
		} else {
			w += a[Q(n)][8] -  a[Q(n)][t[i]];
			t[i] = 8;
		}
	}
	cout << -1;
}