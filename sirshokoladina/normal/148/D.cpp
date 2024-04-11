#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i ++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i --)
#define sqr(a) ((a) * (a))
#define mp make_pair
#define pb push_back
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

ld p[1010][1010][3];

int main() {
	//freopen ("input.txt", "rt", stdin);
	//freopen ("output.txt", "wt", stdout);
	int w, b;
	cin >> w >> b;
	forn (i, 1010) {
		forn (j, 1010) {
			forn (k, 3) {
				if (!i && !j) {
					p[i][j][k] = 0.l;
					continue;
				}
				if (k == 0) {
					if (j) {
						p[i][j][k] = ld(i) / ld(i + j) + ld(j) / ld(i + j) * p[i][j - 1][1];
					} else {
						p[i][j][k] = 1.l;
					}
				} else if (k == 1) {
					if (j) {
						p[i][j][k] = ld(j) / ld(i + j) * p[i][j - 1][2];
					} else {
						p[i][j][k] = 0.l;
					}
				} else {
					if (!i) {
						p[i][j][k] = p[i][j - 1][0];
					} else if (!j) {
						p[i][j][k] = p[i - 1][j][0];
					} else {
						p[i][j][k] = ld(i) / ld(i + j) * p[i - 1][j][0] + ld(j) / ld(i + j) * p[i][j - 1][0];
					}
				}
			}
		}
	}
	printf("%0.20lf", double(p[w][b][0]));
	return 0;
}