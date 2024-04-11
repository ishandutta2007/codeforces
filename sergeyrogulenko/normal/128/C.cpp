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

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

const int64 P = 1000000007;
int64 T[1001][1002];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if (n <= 2 || m <= 2) {
		if (k == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	k ++;
	seta (T, 0);
	for (int i = 1; i <= 1000; i ++)
		T[i][1] = 1;
	for (int i = 1; i <= 1000; i ++)
		forn (j, 1002) {
			int ni = i + 2;
			int nj = j + 1;
			if (ni <= 1000 && nj <= 1000)
				T[ni][nj] = (T[ni][nj] + T[i][j]) % P;
			ni = i+1;
			nj = j;
			if (ni <= 1000 && nj <= 1000)
				T[ni][nj] = (T[ni][nj] + 2 * T[i][j] - T[i-1][j] + P) % P;
		}
	cout << (T[n-2][k-1] * T[m-2][k-1]) % P << endl;		
	return 0;
}