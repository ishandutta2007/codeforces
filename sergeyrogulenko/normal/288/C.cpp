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

int pos[1000500];
int n;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n;
//	for (n = 1; n <= 1000; n++) {
	seta(pos, 255);
	int b = 1;
	while (b * 2 <= n) b *= 2;
	for (int i = n; i >= 0; i--) {
		if (i < b) b /= 2;
		if (pos[i] != -1) continue;
		if (i == 0) {
			pos[i] = 0;
			break;
		}
		int a = i - b;
//		assert(pos[i] == -1);
		pos[i] = b - 1 - a;
//		assert(pos[b-1-a] == -1);
		pos[b-1-a] = i;
	}	
	int64 res = 0;
	forn(i, n+1)
		res += i ^ pos[i];
	cout << res << endl;
	forn(i, n+1)
		printf("%d ", pos[i]);
	cout << endl;
//	}
	return 0;
}