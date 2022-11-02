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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

vector < pair < vector <int>, vector <int> > > ans, threes, twos;
int n;
vector <int> a;
char buf[100];

pair < vector <int>, vector <int> > merge (pair < vector <int>, vector <int> > a, pair < vector <int>, vector <int> > b) {
	a.fs.insert (a.fs.end(), b.fs.begin(), b.fs.end());
	a.sc.insert (a.sc.end(), b.sc.begin(), b.sc.end());
	return a;
}

void split (pair < vector <int>, vector <int> > a) {
	pair < vector <int>, vector <int> > a1, a2;
	a1.fs.pb (a.fs[0]);
	a1.fs.pb (a.fs[1]);
	a1.sc.pb (a.fs[1]);
	a1.sc.pb (a.fs[0]);

	a2.fs.pb (a.fs[0]);
	a2.fs.pb (a.fs[2]);
	a2.sc.pb (a.fs[2]);
	a2.sc.pb (a.fs[0]);

	twos.pb (a2);
	twos.pb (a1);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	a.resize (n);
	forn (i, n)
		scanf ("%d", &a[i]);
	forn (i, n)
		a[i] --;
	ans.clear ();
	threes.clear ();
	twos.clear ();
	forn (i, n)
		while (a[i] != i) {
			int v = i;
			vector <int> tmp;
			tmp.pb (v);
			while (I tmp.size() < 5 && a[v] != i) {
				v = a[v];
				tmp.pb (v);
			}
			vector <int> tmpans;
			forn (i, tmp.size()) 
				tmpans.pb (tmp[(i+1)%tmp.size()]);
			if (tmp.size() == 2)
				twos.pb (mp (tmp, tmpans));
			else
			if (tmp.size() == 3)
				threes.pb (mp (tmp, tmpans));
			else
				ans.pb (mp (tmp, tmpans));
			ford (i, tmp.size())
				if (i)
					swap (a[tmp[(i+1)%tmp.size()]], a[tmp[i]]);
		}
	while (threes.size() > 0) {
		if (twos.size() > 0) {
			ans.pb (merge (twos.back(), threes.back()));
			twos.pop_back();
			threes.pop_back();
			continue;
		}
		if (threes.size() == 1) {
			ans.pb (threes.back());
			threes.pop_back();
			continue;
		}
		split (threes.back());
		threes.pop_back();
	}

	while (twos.size() > 0) {
		if (twos.size() == 1) {
			ans.pb (twos.back());
			twos.pop_back();
			continue;
		}
		pair < vector <int>, vector <int> > tmp = twos.back();
		twos.pop_back();
		ans.pb (merge (tmp, twos.back()));
		twos.pop_back();
	}
	printf ("%d\n", ans.size());
	forn (i, ans.size()) {
		printf ("%d\n", ans[i].fs.size());
		forn (j, ans[i].fs.size())
			printf ("%d ", ans[i].fs[j]+1);
		printf ("\n");
		forn (j, ans[i].fs.size())
			printf ("%d ", ans[i].sc[j]+1);
		printf ("\n");
	}
	return 0;
}