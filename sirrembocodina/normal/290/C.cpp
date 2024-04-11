#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forv(i, a) forn (i, a.size())
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define sqr(x) ((x) * (x))

typedef long long int64;
typedef long double ld;

string a[100];

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	int tux;
	cin >> tux;
	int foo = 0, bar = 0, baz = 0, quz = 1;
	forn (i, tux) {
		int pur;
		cin >> pur;
		foo += pur;
		++bar;
		if (max(foo * quz, bar * baz) == foo * quz) {
			baz = foo;
			quz = bar;
		}
	}
	cout.precision(10);
	cout << fixed << ld(baz) / ld(quz);
}