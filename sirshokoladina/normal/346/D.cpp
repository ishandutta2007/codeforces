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

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc s econd
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

int n;
vector<int> f[1000100];
int e[1000100];
bool u[1000100];
int d[1000100];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int m;
	cin >> n >> m;
	forn (i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[x]++;
		f[y].pb(x);
	}
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	memset(u, 0, sizeof u);
	memset(d, -1, sizeof d);
	deque<int> v;
	v.pb(t);
	d[t] = 0;
	while (v.size()) {
		int q = v.front();
		v.pop_front();
		if (u[q]) {
			continue;
		}
		u[q] = 1;
		forn (i, f[q].size()) {
			int j = f[q][i];
			e[j]--;
			int cur = d[q] + bool(e[j]);
			if (!u[j] && (d[j] == -1 || d[j] > cur)) {
				d[j] = cur;
				if (e[j]) {
					v.push_back(j);
				} else {
					v.push_front(j);
				}
			}
		}
	}
	cout << d[s] << endl;
	return 0;
}