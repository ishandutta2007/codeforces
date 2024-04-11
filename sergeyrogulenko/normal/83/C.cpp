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

int n, m, k;
char a[50][50];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool u[256];
int d[50][50];
pii q[2500];

string bfs () {
	seta (d, 255);
	pii S, T;
	forn (i, n)
		forn (j, m) {
			if (a[i][j] == 'S')
				S = mp (i, j);
			if (a[i][j] == 'T')
				T = mp (i, j);
		}
	d[T.fs][T.sc] = 0;
	int h, t;
	h = t = 0;
	q[h] = T;
	while (h <= t) {
		pii v = q[h];
		h ++;
		forn (i, 4) {
			pii w = mp (v.fs + dx[i], v.sc + dy[i]);
			if (0 <= w.fs && w.fs < n && 0 <= w.sc && w.sc < m && d[w.fs][w.sc] == -1 && u[a[w.fs][w.sc]]) {
				d[w.fs][w.sc] = d[v.fs][v.sc] + 1;
				t ++;
				q[t] = w;
			}
		}
	}
	if (d[S.fs][S.sc] == -1)
		return "S";
	string res = "";
	vector <pii> V, W;
	V.pb (S);
	int cd = d[S.fs][S.sc];
	while (cd > 1) {
		char c = 'z';
		forn (i, V.size())
			forn (j, 4) {
				pii w = mp (V[i].fs + dx[j], V[i].sc + dy[j]);
				if (0 <= w.fs && w.fs < n && 0 <= w.sc && w.sc < m && cd - 1 == d[w.fs][w.sc])
					c = min (c, a[w.fs][w.sc]);
			}
		res += c;
		W.clear ();
		forn (i, V.size())
			forn (j, 4) {
				pii w = mp (V[i].fs + dx[j], V[i].sc + dy[j]);
				if (0 <= w.fs && w.fs < n && 0 <= w.sc && w.sc < m && cd - 1 == d[w.fs][w.sc] && a[w.fs][w.sc] == c)
					W.pb (w);
			}
		sort (all (W));
		W.resize (unique (all (W)) - W.begin());
		cd --;
		V = W;
		W.clear ();
	}
	return res;
}

string res;

void calc (int cur, int la) {
	if (cur == 26) {
		string tmp = bfs ();
		if (tmp == "S")
			return;
		if (res == "S")
			res = tmp;
		else
		if (res.length() > tmp.length() || (res.length() == tmp.length() && res > tmp))
			res = tmp;
		return;
	}
	calc (cur+1, la);
	if (la == 0)
		return;
	u[cur+'a'] = 1;
	calc (cur+1, la-1);
	u[cur+'a'] = 0;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m >> k;
	forn (i, n)
		forn (j, m)
			cin >> a[i][j];
	seta (u, 0);
	u['S'] = 1;
	u['T'] = 1;
	res = "S";
	calc (0, k);
	if (res == "S")
		cout <<	-1 << endl;
	else
		cout << res << endl;
	return 0;
}