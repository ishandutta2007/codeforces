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

int n, k;
map <string, pii> w[3];
map <string, pair <int, string> > w1[3];

pair <pair <string, int> , vector <string> > calc (int x, bool change) {
	pair <pair <string, int> , vector <string> > res;
	res.fs.sc = -inf;
	for (map <string, pii> :: iterator it = w[x].begin(); it != w[x].end(); it ++) {
		pair <pair <string, int> , vector <string> > tmp;
		tmp.fs.fs = it->fs;
		tmp.fs.sc = it->sc.fs;
		if (!change) {
			forn (i, 3)
				for (map <string, pair <int, string> > :: iterator  jt = w1[i].begin(); jt != w1[i].end(); jt ++)
					if (jt->sc.sc == tmp.fs.fs) {
						tmp.sc.pb (jt->fs);
						if (i == x)
							tmp.fs.sc += jt->sc.fs;
					}
		} else {
			vector < pair <int, string> > tmpvec;
			for (map <string, pair <int, string> > :: iterator  jt = w1[x].begin(); jt != w1[x].end(); jt ++)
				tmpvec.pb (mp (jt->sc.fs, jt->fs));
			sort (all (tmpvec));
			reverse (all (tmpvec));
			forn (i, min (I tmpvec.size(), it->sc.sc)) {
				tmp.sc.pb (tmpvec[i].sc);
				tmp.fs.sc += tmpvec[i].fs;
			}
		}
		if (res.fs.sc < tmp.fs.sc)
			res = tmp;
	}
	forn (i, res.sc.size())
		forn (x, 3)
			w1[x].erase (res.sc[i]);
	return res;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	int total = 0;
	forn (i, n) {
		string s1, s2;
		int a, b, c, d;
		cin >> s1 >> s2 >> a >> b >> c >> d;
		if (s2 == "weapon")
			w[0][s1] = mp (a, d);
		else
		if (s2 == "armor")
			w[1][s1] = mp (b, d);
		else
			w[2][s1] = mp (c, d);
		total += d;
	}
	cin >> k;
	forn (i, k) {
		string s1, s2, s3;
		int x;
		cin >> s1 >> s2 >> x >> s3;
		if (s2 == "gladiator")
			w1[0][s1] = mp (x, s3);
		else
		if (s2 == "sentry")
			w1[1][s1] = mp (x, s3);
		else
			w1[2][s1] = mp (x, s3);
	}
	bool change;
	if (total == k) 
		change = 0;
	else
		change = 1;
	pair <pair <string, int> , vector <string> > best[3];
	forn (i, 3)
		best[i] = calc (i, change);
	forn (i, 3) {
		forn (x, 3)
			for (map <string, pair <int, string> > :: iterator  jt = w1[x].begin(); jt != w1[x].end(); jt ++)
				if (w[i][best[i].fs.fs].sc > I best[i].sc.size())
					best[i].sc.pb (jt->fs);
		forn (j, best[i].sc.size())
			forn (x, 3)
				w1[x].erase (best[i].sc[j]);
	}
	forn (i, 3) {
		cout << best[i].fs.fs << " " << best[i].sc.size();
		forn (j, best[i].sc.size())
			cout << " " << best[i].sc[j];
		cout << endl;
	}
	return 0;
}