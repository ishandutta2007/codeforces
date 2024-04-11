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
#define y1 botva

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n;
vector <pii> A, B;

bool lucky (int x) {
	while (x) {
		if ((x % 10 != 7) && (x % 10 != 4))
			return 0;
		x /= 10;
	}
	return 1;
}

map <pii, int> pos;
vector <pii> ans;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	A.resize (n);
	forn (i, n) {
		scanf ("%d", &A[i].fs);
		A[i].sc = i;
	}
	B = A;
	sort (all (B));
	if (A == B) {
		cout << 0 << endl;
		return 0;
	}
	pii q = mp (-1, -1);
	forn (i, n)
		if (lucky (A[i].fs)) 
			q = A[i];
	if (q == mp (-1, -1)) {
		cout << -1 << endl;
		return 0;
	}
	forn (i, n)
		pos[A[i]] = i;
	int qpos = pos[q];
	ans.clear ();
	for (int i = 0; i < n; i ++)
		if (B[i] != q && B[i] != A[i]) {
			swap (pos[A[i]], pos[A[qpos]]);
			swap (A[i], A[qpos]);
			if (i != qpos)
				ans.pb (mp (i, qpos));
			qpos = i;
			int p1 = pos[B[i]];
			if (p1 != qpos)
				ans.pb (mp (qpos, p1));
			swap (pos[A[qpos]], pos[A[p1]]);
			swap (A[qpos], A[p1]);
			swap (qpos, p1);
		}
	printf ("%d\n", ans.size());
	forn (i, ans.size())
		printf ("%d %d\n", ans[i].fs+1, ans[i].sc + 1);
	return 0;
}