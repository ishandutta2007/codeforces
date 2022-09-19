#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <algorithm>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int v[100], vs = 0;
pair<int, int> go[100];

void precalc () {
	forn (i, 7) {
		forn (j, 7 - i) {
			v[vs++] = 4 * i + 7 * j;
			go[4 * i + 7 * j] = mp(i, j);
		}
	}
	sort(v, v + vs);
	vs = unique(v, v + vs) - v;
}

int p[20][6];
int q[20][6];

void solve () {
	ll n;
	cin >> n;
	memset(p, -1, sizeof p);
	p[0][0] = 0;
	forn (i, 19) {
		int r = n % 10;
		n /= 10;
		forn (j, 6) {
			if (p[i][j] != -1) {
				forn (k, vs) {
					if ((j + v[k]) % 10 == r) {
						p[i + 1][(j + v[k]) / 10] = j;
						q[i + 1][(j + v[k]) / 10] = v[k];
					}
				}
			}
		}
	}
	if (p[19][0] == -1) {
		cout << -1 << endl;
		return;
	}
	ll ans[6];
	memset(ans, 0, sizeof ans);
	ll d = 1;
	forn (i, 18) {
		d *= 10;
	}
	int y = 0;
	for (int x = 19; x > 0; --x) {
		int i = 0;
		forn (w, go[q[x][y]].fs) {
			ans[i++] += d * 4;
		}
		forn (w, go[q[x][y]].sc) {
			ans[i++] += d * 7;
		}
		d /= 10;
		y = p[x][y];
	}
	forn (i, 6) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	precalc();
	int n;
	cin >> n;
	forn (i, n) {
		solve();
	}
	return 0;
}