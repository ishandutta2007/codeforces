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
vector<pii> a, b;
set<int> S;

int main () {
	cin >> n;
	a.resize(n);
	S.clear();
	forn(i, n) {
		scanf("%d", &a[i].fs);
		a[i].sc = i;
		S.insert(i);
	}
	b = a;
	int64 ans = 0;
	sort(all(a));
	forn(i, a.size() - 2) {
		int pos = a[i].sc;
		set<int> :: iterator it = S.find(pos), l, r;
		if (it == S.begin()) {
			ans += a[i].fs;
			S.erase(it);
			continue;
		}
		l = it;
		r = it;
		l--;
		r++;
		if (r == S.end()) {
			ans += a[i].fs;
			S.erase(it);
			continue;
		}
                ans += min(b[*l].fs, b[*r].fs);
                S.erase(it);
	}
	cout << ans << endl;
	return 0;
}