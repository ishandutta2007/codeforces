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

int a[5010], d[5010], b[5010];

int t[5010], l[5010], r[5010], v[5010];

int main () {
#ifndef SUKPZDC
	//freopen(".in", "rt", stdin);
	//freopen(".out", "wt", stdout);
#else
	freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
#endif
	int n, m;
	cin >> n >> m;
	forn (i, n) {
		a[i] = 1000000000;
	}
	forn (i, m) {
		scanf("%d%d%d%d", &t[i], &l[i], &r[i], &v[i]);
		l[i]--;
	}
	forn (i, m) {
		if (t[i] == 1) {
			for (int j = l[i]; j < r[i]; ++j) {
				d[j] += v[i];
			}
		} else {
			for (int j = l[i]; j < r[i]; ++j) {
				a[j] = min(a[j], v[i] - d[j]);
			}
		}
	}
	memcpy(b, a, sizeof a);
	forn (i, m) {
		if (t[i] == 1) {
			for (int j = l[i]; j < r[i]; ++j) {
				b[j] += v[i];
			}
		} else {
			int q = -1000000000;
			for (int j = l[i]; j < r[i]; ++j) {
				q = max(q, b[j]);
			}
			if (q != v[i]) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	forn (i, n) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}