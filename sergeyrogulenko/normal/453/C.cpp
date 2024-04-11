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

int n, m;
vector<int> g[100500];
int t[100500];
vector<int> ans;
bool u[100500];

void go(int v, int p) {
	if (u[v]) return;
	u[v] = 1;
	ans.pb(v);
	t[v] ^= 1;
	forn(i, g[v].size()) {
		if (u[g[v][i]]) continue;
		go(g[v][i], v);
		ans.pb(v);
		t[v] ^= 1;
	}
	if (t[v] == 1 && p != -1) {
		ans.pb(p);
		t[p] ^= 1;
		ans.pb(v);
		t[v] ^= 1;
	}
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf("%d%d", &n ,&m);
	forn(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	forn(i, n)
		scanf("%d", &t[i]);
	int v = -1;
	forn(i, n)
		if (t[i] == 1)
			v = i;
	if (v == -1) {
		cout << 0 << endl;
		cout << endl;
		return 0;
	}
	seta(u, 0);
	go(v, -1);
	if (t[v] == 1) {
		t[v] ^= 1;
		ans.pop_back();
	}
	forn(i, n)
		if (t[i] == 1) {
			cout << -1 << endl;
			return 0;
		}
	cout << ans.size() << endl;
	forn(i, ans.size())
		printf("%d ", ans[i] + 1);
		cout << endl;
	return 0;
}