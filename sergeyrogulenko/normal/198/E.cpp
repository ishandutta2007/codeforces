#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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

template <class T> T sqr (T x) {return x * x;}

struct treeNode {
	int64 leftD, rightD;
	vector <pair <int64, int> > S;
};

struct element {
	int64 d, m, r, p;
};

bool u[300500];
element A[300500];
int n, lst, ans;
int64 p, r;
treeNode tree[524288];
vector <pair <int64, int64> > Q;

bool operator < (const element& p1, const element& p2) {
	return p1.d < p2.d;
}

void read() {
	int x, y;
	cin >> x >> y >> p >> r >> n;
	r = r * r;
	seta (u, 0);
	forn (i, n) {
		int x1, y1;
		scanf ("%d%d", &x1, &y1);
		x1 -= x;
		y1 -= y;
		A[i].d = (int64)x1 * x1 + (int64)y1 * y1;
		int m1, r1, p1;
		scanf ("%d%d%d", &m1, &p1, &r1);
		A[i].r = r1;
		A[i].r = A[i].r * A[i].r;
		A[i].p = p1;
		A[i].m = m1;
	}
	ans = 0;
	Q.pb (mp (r, p));
	sort (A, A+n);
}

void update (vector <pair <int64, int> >& S, int64 y) {
	while (S.size() > 0 && S.back().fs <= y) {
		int v = S.back().sc;
		S.pop_back();
		if (!u[v]) {
			u[v] = 1;
			ans ++;
			Q.pb (mp (A[v].r, A[v].p));
		}
	}
}

void go (int v, int64 l, int64 r, int64 y) {
	if (tree[v].rightD < l || tree[v].leftD > r)
		return;
	if (l <= tree[v].leftD && tree[v].rightD <= r) {
		update (tree[v].S, y);
		return;
	}
	go (v*2, l, r, y);
	go (v*2+1, l, r, y);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	read ();	
	lst = 1;
	while (lst < n)
		lst *= 2;
	forn (i, lst*2)
		tree[i].leftD = tree[i].rightD = 0;
	forn (i, n) {
		tree[i+lst].leftD = A[i].d;
		tree[i+lst].rightD = A[i].d;
		tree[i+lst].S.pb (mp (A[i].m, i));
	}
	for (int i = n; i < lst; i ++) {
		tree[i+lst].leftD = inf64;
		tree[i+lst].rightD = inf64;
	}	
	for (int i = lst-1; i >= 1; i --) {
		tree[i].leftD = tree[i*2].leftD;
		tree[i].rightD = tree[i*2+1].rightD;
		tree[i].S = tree[i*2].S;
		tree[i].S.insert (tree[i].S.end(), all (tree[i*2+1].S));
		sort (all (tree[i].S));
		reverse (all (tree[i].S));
	}
	while (Q.size() > 0) {
		pair <int64, int64> v = Q.back();
		Q.pop_back();
		go (1, 1, v.fs, v.sc);
	}
	cout << ans << endl;
	return 0;
}