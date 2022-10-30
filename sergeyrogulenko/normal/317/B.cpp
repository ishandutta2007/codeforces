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

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int S[140][140], T[140][140];

void solve(int n) {
	seta(S, 0);
	S[70][70] = n;
	while (1) {
	        seta(T, 0);
		bool ok = 0;
		forn(i, 140)
			forn(j, 140) {
				if (S[i][j] >= 4) {
					ok = 1;
					forn(k, 4)
						T[i+dx[k]][j+dy[k]] += S[i][j] / 4;
					S[i][j] %= 4;
				}
				T[i][j] += S[i][j];
			}
		if (!ok) break;
		memcpy(S, T, sizeof(S));
	}
	int t;
	scanf("%d", &t);
	forn(i, t) {
		int x, y;
		scanf("%d%d", &x, &y);
		x += 70;
		y += 70;
		if (x < 0 || x >= 140 || y < 0 || y >= 140)
			printf("0\n");
		else
			printf("%d\n", S[x][y]);
	}
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n;
	cin >> n;	
	solve(n);
	return 0;
}