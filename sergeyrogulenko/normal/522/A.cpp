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

map<string, int> nums;
vector<int> g[1000];
int n, m;
int t[1000];

int getNum(string s) {
	forn(i, s.length()) {
		s[i] = tolower(s[i]);
	}
	if (nums.count(s) == 0) {
		nums[s] = n;
		n++;
	}
	return nums[s];
}

int dfs(int v) {
	if (t[v] != -1) return t[v];
	t[v] = 1;
	forn(i, g[v].size()) {
		t[v] = max(dfs(g[v][i]) + 1, t[v]);
	}
	return t[v];
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> m;
	n = 0;
	forn(i, m) {
		string a, b, c;
		cin >> a >> b >> c;
		int na = getNum(a);
		int nb = getNum(c);
		g[nb].pb(na);
	}
	int v = getNum("Polycarp");
	seta(t, 255);
	cout << dfs(v) << endl;
	return 0;
}