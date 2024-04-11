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

char s[100500];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	gets(s);
	int n = strlen(s);
	s[n] = ' ';
	n++;

	string res = "";
	bool cur = 0;
	bool cw = 0;
	string ans = "";
	forn(i, n) {
		if (s[i] == '"') {
			if (cw) {
				printf("<%s>\n", ans.data());
				ans = "";
				cur = 0;
				cw = 0;
			} else {
				cur = 1;
				cw = 1;
			}
		} else {
			if (s[i] == ' ') {
				if (cur == 0) continue;
				if (cw == 1) ans += s[i];
				else {
					printf("<%s>\n", ans.data());
					ans = "";
					cur = 0;
					cw = 0;
				}
			} else {
				cur = 1;
				ans += s[i];
			}
		}
	}	
	return 0;
}