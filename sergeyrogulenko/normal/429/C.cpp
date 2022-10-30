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

int n;
int s[25];
int need[25], has[25];

void answer(string s) {
	cout << s << endl;
	exit(0);
}

void go(int num, int k) {
	if (k == n) {
		forn(i, n)
			if (has[i] != need[i]) return;
		answer("YES");
		return;
	}
	while (s[num] == 0)
		num--;
	has[k] = 1;
	need[k] = num;
	forn(i, k)
		if (num + 1 < need[i] && has[i] + num <= need[i]) {
			has[i] += num;
			s[num]--;
			go(num, k + 1);
			has[i] -= num;
			s[num]++;
			if (num == 1) break;
		}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta(s, 0);
	cin >> n;
	forn(i, n) {
		int x;
		cin >> x;
		s[x]++;
	}
	if (s[n] != 1) answer("NO");
	if (s[1] * 2 <= n) answer("NO");
	need[0] = n;
	has[0] = 1;
	go(n-1, 1);
	answer("NO");
	return 0;
}