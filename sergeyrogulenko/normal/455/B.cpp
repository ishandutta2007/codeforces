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

int n, k;
int nxt[100500][26];
char buf[100500];
int m;
int t[100500];
int deg[100500];
int win;
int ans[100];

void add(string s) {
	int v = 0;
	forn(i, s.length()) {
		int c = s[i] - 'a';
		if (nxt[v][c] == -1) {
			nxt[v][c] = m;
			deg[v]++;
			m++;
		}
		v = nxt[v][c];
	}
}

void go(int v) {
	t[v] = 0;
	if (deg[v] == 0) {
		t[v] = win;
		return;
	}
	forn(i, 26)
		if (nxt[v][i] != -1) {
			int w = nxt[v][i];
			go(w);
			if (t[w] == 0) {
				t[v] = 1;
			}
		}
}

void answer(int ans) {
	if (ans)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	exit(0);
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> k;
	m = 1;
	seta(deg, 0);
	seta(nxt, 255);
	forn(i, n) {
		scanf("%s", buf);
		string s = buf;
		add(s);
	}
	win = 0;
	ans[0] = 0;
	for (int i = 1; i <= 10; i++) {
		go(0);
		ans[i] = t[0];
		win = ans[i];
	}
	if (k <= 10)
		answer(ans[k]);
	if (ans[10] == ans[9])
		answer(ans[10]);
	else
		answer(ans[k%2]);
	return 0;
}