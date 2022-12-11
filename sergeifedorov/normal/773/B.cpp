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
#include <bitset>
#include <sstream>
#include <queue>

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
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 150;
const int m = 5;

int n;
int a[nmax][m];

long long getScore(long long minute, long long solved, long long total) {
	if (minute == -1) return 0;
	long long cost = 0;
	if (solved * 2 > total) cost = 500;
	else if (solved * 4 > total) cost = 1000;
	else if (solved * 8 > total) cost = 1500;
	else if (solved * 16 > total) cost = 2000;
	else if (solved * 32 > total) cost = 2500;
	else cost = 3000;
	return cost * 250 - minute * cost;
}

bool check(int x) {
	vector<int> l(m, 0);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (a[i][j] >= 0)
				l[j] ++;
	vector<int> r = l;
	for (int j = 0; j < m; j ++)
		if (a[0][j] >= 0)
			r[j] = l[j] + x;

	long long res = 0.0;
	for (int j = 0; j < m; j++) {
		long long d1 = getScore(a[0][j], l[j], n + x) - getScore(a[1][j], l[j], n + x);
		long long d2 = getScore(a[0][j], r[j], n + x) - getScore(a[1][j], r[j], n + x);
		// cout << d1 << " " << d2 << endl;
		res += max(d1, d2);
	}
	if (res > 0) return 1;
	return 0;
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n;
	forn(i, n)
		forn(j, m)
			cin >> a[i][j];

	if (check(0)) {
		puts("0");
		exit(0);
	}

	vector<int> c(m, 0);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if (a[i][j] >= 0)
				c[j] ++;

	vector<int> gr;
	for (int j = 0; j < m; j ++) 
		for (int k = 1; k <= 6; k ++) {
			int now = 1 << k;
			gr.push_back(c[j] * now - n);
			gr.push_back((n - now * c[j]) / (now - 1));
			gr.push_back((n - now * c[j]) / (now - 1) + 1);
			gr.push_back((n - now * c[j]) / (now - 1) - 1);
		}
	sort(gr.begin(), gr.end());
	vector<int> e;
	e.push_back(0);
	// e.push_back(1e9 + 8);
	for (int i = 0; i < gr.size(); i ++)
		if (gr[i] > e.back())
			e.push_back(gr[i]);
	e.push_back(1e9 + 8);

	for (int i = 0; i < (int)e.size() - 1; i ++) {
		int l = e[i];
		int r = e[i+1] - 1;
		if (!check(r)) continue;
		while (l < r) {
			long long m  = (l + r) / 2;
			// cout << m << " " << check(m) << endl;
			if (check(m))
				r = m;
			else
				l = m + 1;
		}
		cout << l << endl;
		exit(0);
		// if (check(l)) {
		// 	cout << l << endl;
		// if (l > 1e9 + 7)
		// 	cout << -1 << endl;
		// else
		// 	cout << l << endl;
	}
	cout << -1 << endl;
	// for (int i = 0; i < 10; i++)
		// cout << check(i) << endl;
	// cout << check(2) << endl;
	// cout << check(4) << endl;
	// return 0;



	return 0;
}