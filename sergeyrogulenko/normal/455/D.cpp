#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXTHUI
#define prev PREVHUI
#define y1 Y1HUI

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

const int M = 400;

struct rec {
	int l, r;
	vector<int> a;
	map<int, int> s;
};

int n;
int a[100500];
int ans;
rec q[500];
int k;

void build() {
	k = -1;
	forn(i, n) {
		if (i % M == 0) {
			k++;
			q[k].a.clear();
			q[k].s.clear();
			q[k].l = i;
		}
		q[k].r = i;
		q[k].a.pb(a[i]);
		q[k].s[a[i]]++;
	}
	k++;	
}

void destroy() {
	n = 0;
	forn(i, k) {
		forn(j, q[i].a.size()) {
			a[n] = q[i].a[j];
			n++;
		}
	}
}

int lf, rg;

int del(int pos) {
	forn(i, k)
		if (q[i].l <= pos && pos <= q[i].r) {
			rg = i;
			int ind = pos - q[i].l;
			int v = q[i].a[ind];
			q[i].a.erase(q[i].a.begin() + ind);
			q[i].s[v]--;
			return v;
		}
	return -1;			
}

void put(int pos, int v) {
	forn(i, k)
		if (q[i].l <= pos && pos <= q[i].r) {
			lf = i;
			int ind = pos - q[i].l;
			q[i].a.insert(q[i].a.begin() + ind, v);
			q[i].s[v]++;
			break;
		}
}

void shift(int l, int r) {
 	if (l > r) swap(l, r);
 	if (l == r) return;
 	int v = del(r);
 	put(l, v);
 	for (int i = lf + 1; i <= rg - 1; i++) {
 		q[i].l++;
 		q[i].r++;
 	}
 	if (lf != rg) {
 		q[lf].r++;
 		q[rg].l++;
 	}
}

void solve(int l, int r, int k1) {
	if (l > r) swap(l, r);
	ans = 0;
	forn(i, k) {
		if (r < q[i].l || l > q[i].r) continue;
		if (l <= q[i].l && q[i].r <= r) {
			if (q[i].s.count(k1)) {
				ans += q[i].s[k1];
			}	
			continue;
		}
		for (int j = q[i].l; j <= q[i].r; j++) {
			int ind = j - q[i].l;
			if (l <= j && j <= r && q[i].a[ind] == k1) ans++;
		}
	}
	printf("%d\n", ans);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
  	cin >> n;
  	forn(i, n) {
  		scanf("%d", &a[i]);
  	}
	build();
	int t;
	cin >> t;
	ans = 0;
	forn(i, t) {
		if (i % (M * 10) == 0 && i > 0) {
			destroy();
			build();
		}
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			l = (l + ans - 1) % n;
			r = (r + ans - 1) % n;
			shift(l, r);
		} else {
			int l, r, k1;
			scanf("%d%d%d", &l, &r, &k1);
			l = (l + ans - 1) % n;
			r = (r + ans - 1) % n;
			k1 = (k1 + ans - 1) % n + 1;
			solve(l, r, k1);
		}
	}
	return 0;
}