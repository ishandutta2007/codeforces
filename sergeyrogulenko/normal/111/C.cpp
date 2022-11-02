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
#define y1 botva

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n, m;
int64 g[40];
int64 rest[41];
const int dx[5] = {0, 1, -1, 0, 0};
const int dy[5] = {0, 0, 0, 1, -1};
int best;

void go (int64 mask, int cur, int cura) {
	if (cura >= best)
		return;
	if (cur >= n*m)
		return;
	if (mask == (1LL << (n * m)) - 1) {
		best = cura;
		return;
	}
	if ((mask | rest[cur]) != (1LL << (n * m)) - 1)
		return;
	go (mask | g[cur], cur+1, cura+1);
	go (mask, cur+1, cura);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	cin >> n >> m;
	seta (g, 0);
	forn (i, n)
		forn (j, m) {
			int num1 = i * m + j;
			forn (k, 5) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (0 <= x && x < n && 0 <= y && y < m) {
					int num2 = x * m + y;
					g[num1] |= (1LL << num2);
				}
			}
		}
	seta (rest, 0);
	ford (i, n*m)
		rest[i] = rest[i+1] | g[i];
	best = n * m;
	go (0, 0, 0);
	cout << n*m - best << endl;
	return 0;
}