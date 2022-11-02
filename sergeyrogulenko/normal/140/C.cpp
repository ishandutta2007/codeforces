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

int n;
map <int, vector <int> > A;
set <pii> S;
vector < vector <int> > ans;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	A.clear ();
	forn (i, n) {
		int x;
		scanf ("%d", &x);
		A[x].pb (x);
	}
	for (map <int, vector <int> > :: iterator it = A.begin() ;it != A.end() ;it++)
		S.insert (mp (it->sc.size(), it->fs));
	while (S.size() >= 3) {
		set <pii> :: iterator it = S.end();
		vector <int> tmp;
		it --;
		pii p1 = *it;
		it --;
		pii p2 = *it;
		it --;
		pii p3 = *it;
		S.erase(p1);
		S.erase(p2);
		S.erase(p3);
		p1.fs --;
		p2.fs --;
		p3.fs --;
		if(p1.fs>0)
		S.insert (p1);
		if(p2.fs>0)
		S.insert (p2);
		if(p3.fs>0)
		S.insert (p3);
		tmp.pb (A[p1.sc].back());
		tmp.pb (A[p2.sc].back());
		tmp.pb (A[p3.sc].back());
		A[p1.sc].pop_back();
		A[p2.sc].pop_back();
		A[p3.sc].pop_back();
		sort (all (tmp));
		reverse (all (tmp));
		ans.pb (tmp);
	}
	sort (all (ans));
	printf ("%d\n", ans.size());
	forn (i, ans.size()) {
		printf ("%d %d %d\n", ans[i][0],ans[i][1],ans[i][2]);
	}
	

	return 0;
}