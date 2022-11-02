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

const int MMAX = 27 * 27 * 27 * 27;

char str[100500];
string s;
vector<int> l[MMAX], r[MMAX];
int d[MMAX];
int n;
int q;
map<pii, int> ans;

int get_number(string t) {
	int res = 0;
	forn(i, 4) {
		res = res * 27;
		if (i < I t.length())
			res = res + t[i] - 'a';
		else
			res = res + 26;
	}
	return res;
}

int get(int vl, int vr) {
	int res = inf;
	int rr = 0;
	forn(i, l[vl].size()) {
		int pl = l[vl][i];
		int pr = pl + d[vr] - 1;
		while (rr < I r[vr].size() && r[vr][rr] < pr)
			rr++;
		if (rr < I r[vr].size())
			res = min(res, max(r[vr][rr], pl + d[vl] - 1) - pl + 1);
	}
	return res;
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%s", str);
	s = str;
	n = s.length();
	forn(i, n) {
		for (int len = 1; len + i <= n && len <= 4; len++) {
			string t = s.substr(i, len);
			int v = get_number(t);
			l[v].pb(i);
			r[v].pb(i + len - 1);
			d[v] = len;
		}
	}
	cin >> q;
	forn(i, q) {
		scanf("%s", str);
		string a = str;
		scanf("%s", str);
		string b = str;
		int u = get_number(a);
		int v = get_number(b);

		if (u > v)
			swap(u, v);
		if (ans.count(mp(u, v))) {
			printf("%d\n", ans[mp(u, v)]);
			continue;
		}
		int vans = min(get(u, v), get(v, u));
		if (vans == inf) vans = -1;
		ans[mp(u, v)] = vans;
		printf("%d\n", vans);
	}
	return 0;
}