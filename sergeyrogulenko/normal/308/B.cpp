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

template <class T> T sqr (T x) {return x * x;}

int n, R, c;
string s[1005000];
int f[22][1005000];
int ans[1005000];
char buf[5005000];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> R >> c;
	forn(i, n) {
		scanf("%s", buf);
		s[i] = buf;		
	}		
	int r = 0;
	int sum = 0;
	for (int l = 0; l < n; l++) {
		r = max(r, l);
		while (r < n && sum + I s[r].length() + r - l <= c) {
			sum += s[r].length();
			r++;
		}
		f[0][l] = r;
		if (l < r)
			sum -= s[l].length();
	}
	forn(i, 22)
		f[i][n] = n;
	for (int i = 1; i < 22; i++)
		forn(j, n)
			f[i][j] = f[i-1][f[i-1][j]];
	forn(i, n+1)
		ans[i] = i;
	forn(i, 22)
		if (R & (1 << i))
			forn(j, n)
				ans[j] = f[i][ans[j]];
	int v = 0;
	forn(i, n)
		if (ans[i] - i > ans[v] - v)
			v = i;
	sum = 0;
	int cnt = 0;
	for (int i = v; i < ans[v]; i++) {
		cnt++;
		sum += s[i].length();
		if (cnt > 1)
			sum++;
		if (sum > c) {
			cnt = 1;
			sum = s[i].length();
			printf("\n");
		}
		if (cnt > 1)
			printf(" ");
		printf("%s", s[i].data());
	}
	return 0;
}