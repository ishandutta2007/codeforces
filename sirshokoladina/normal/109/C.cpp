#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

int n;
vector<int> e[200000], c[200000], a[200000];
bool u[200000] = {0};
int b[200000], d[200000];

void make(int v, bool q = 0, int p1 = 0, int p2 = 0) {
	u[v] = 1;
	int s = 1;
	int p = 0;
	int w = 0;
	forn (i, e[v].size()) {
		if (u[e[v][i]]) {
			w = i;
		} else {
			make(e[v][i], 1, v, i);
			s += a[v][i];
			if (c[v][i]) {
				p += a[v][i];
			} else {
				p += b[e[v][i]];
			}
		}
	}
	if (q) {
		a[p1][p2] = s;
		a[v][w] = n - s;
	}
	b[v] = p;
}

void cal(int v) {
	u[v] = 0;
	if (v == 0) {
		d[v] = b[v];
	}
	forn (i, e[v].size()) {
		if (u[e[v][i]]) {
			if (c[v][i]) {
				d[e[v][i]] = b[e[v][i]] + n - a[v][i];
			} else {
				d[e[v][i]] = d[v];
			}
			cal(e[v][i]);
		}
	}
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	cin >> n;
	forn (i, n - 1) {
		int x, y, z;
		cin >> x >> y >> z;
		while (z > 0) {
			if (z % 10 != 4 && z % 10 != 7) {
				z = -1;
			} else {
				z /= 10;
			}
		}
		x--, y--, z++;
		e[x].push_back(y);
		c[x].push_back(z);
		e[y].push_back(x);
		c[y].push_back(z);
		a[x].push_back(0);
		a[y].push_back(0);
	}
	make(0);
	cal(0);
	long long ans = 0;
	forn (i, n) {
		ans += (long long)d[i] * ((long long)d[i] - 1);
	}
	cout << ans;
}