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

int n;
int d[101][101];
int q[100];
int cnt;
vector<pii> a;
vector<pii> ans;
int best;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}


void check() {
	int sum = 0;
	int ones = max(0, n - q[0]);
	vector<pii> c;
	int cur = 1;
	forn (i, n) {
		int x;
		if (ones) {
			x = 1;
			ones--;
		} else {
			x = q[cur];
			cur++;	
		}
		c.pb(mp(x, a[i].sc));
		sum += abs(x - a[i].fs);
	}
	if (sum < best) {
		best = sum;
		ans = c;
	}
}

void go(int v, int cur) {
	if (v == 0) {
		if (cur < best) {
			best = cur;
			ans.clear();
			forn(i, q[0])
				ans.pb(mp(q[i+1], a[i].sc));
			forn(i, n - q[0])
				ans.pb(mp(1, a[i + q[0]].sc));								
		}
		return;	
	}
	go(v-1, cur);
	if (q[0] == n) return;
	for (int i = 1; i <= q[0]; i++)
		if (d[q[i]][v] != 1) return;
	q[0]++;
	q[q[0]] = v;
	go(v-1, cur - abs(1 - a[q[0]-1].fs) + abs(v - a[q[0]-1].fs));
	q[0]--;
}

int main () {
//	freopen ((task + ".in").data(), "r", stdin);
//	freopen ((task + ".out").data(), "w", stdout);
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i].fs;
	forn(i, n)
		a[i].sc = i;
	sort(all(a));
	reverse(all(a));
	q[0] = 0;
	best = inf;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			d[i][j] = gcd(i, j);
	int cur = 0;
	forn(i, n)
		cur += abs(1 - a[i].fs);
	go(59, cur);
	forn(i, n)
		swap(ans[i].fs, ans[i].sc);
	sort(all(ans));
	forn(i, n)
		swap(ans[i].fs, ans[i].sc);
	forn(i, n)
		cout << ans[i].fs << " ";
		cout << endl;
	return 0;
}