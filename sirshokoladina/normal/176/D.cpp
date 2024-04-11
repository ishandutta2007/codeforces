#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld PI = 3.141592653589793238462643l;

string s[2010];
int qwert[26000010];
int *nx[2010];
string t;
int q[2010];
int lt[26];
int nx1[2010][26];

pair<int, int> d[2010][2010];

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	memset(qwert, -1, sizeof qwert);
	int n;
	cin >> n;
	getline(cin, t);
	int NX = 0;
	forn (i, n) {
		nx[i] = qwert + NX;
		getline(cin, s[i]);
		forn (j, s[i].size()) {
			s[i][j] -= 'a';
		}
		forn (j, 26) {
			lt[j] = 1000000000;
		}
		ford (j, s[i].size()) {
			lt[s[i][j]] = j;
			memcpy(qwert + NX + j * 26, lt, 26 * sizeof(int));
		}
		NX += s[i].size() * 26;
	}
	int m;
	cin >> m;
	forn (i, m) {
		cin >> q[i];
		q[i]--;
	}
	getline(cin, t);
	getline(cin, t);
	forn (j, t.size()) {
		t[j] -= 'a';
	}
	forn (j, 26) {
		lt[j] = 1000000000;
	}
	ford (j, m) {
		forn (k, 26) {
			if (nx[q[j]][k] < 1000000000) {
				lt[k] = j;
			}
			memcpy(nx1[j], lt, 26 * sizeof(int));
		}
	}
	forn (i, 2010) {
		forn (j, 2010) {
			d[i][j] = mp(1000000000, 1000000000);
		}
	}
	d[0][0] = mp(0, 0);
	forn (i, t.size()) {
		forn (j, i + 1) {
//			cerr << i << ' ' << j << ' ' << d[i][j].fs << ' ' << d[i][j].sc << endl;
			if (d[i][j] != mp(1000000000, 1000000000)) {
				d[i + 1][j]  = min(d[i + 1][j], d[i][j]);
				int x = d[i][j].fs, y = d[i][j].sc;
				if (x == m) {
					continue;
				}
				y = nx[q[x]][26 * y + t[i]];
				if (y == 1000000000) {
					y = 0;
					x++;
					if (x == m) {
						continue;
					}
					x = nx1[x][t[i]];
					if (x == 1000000000) {
						continue;
					}
					y = nx[q[x]][t[i]];
				}
				y++;
				if (y == s[q[x]].size()) {
					x++;
					y = 0;
				}
				d[i + 1][j + 1] = min(d[i + 1][j + 1], mp(x, y));
			}
		}
	}
	int h = 0;
	while (d[t.size()][h + 1] != mp(1000000000, 1000000000)) {
		h++;
	}
	cout << h;
	return 0;
}