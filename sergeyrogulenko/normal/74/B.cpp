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

int n, m, k;
int L;
int x[300];
const int dx[3] = {-1, 1, 0};
bool t[300][51];

bool ok (int x) {
	return 1 <= x && x <= n;
}

int main ()
{
	scanf ("%d%d%d", &n, &m, &k);
	string s1, s2;
	cin >> s1 >> s2;
	string s;
	cin >> s;
	L = s.length();
	x[0] = k;
	int cr = 0;
	if (s2 == "tail")
		cr = 1;
	forn (i, L) {
		int cx = x[i];
		if (!ok (cx + dx[cr]))
			cr ^= 1;
		x[i+1] = cx + dx[cr];
	}
	seta (t, 0);
	t[0][m] = 1;
	forn (i, L)
		for (int j = 1; j <= n; j ++)
			if (t[i][j]) {
				if (s[i] == '0') {
					forn (k, 3)
						if (ok (j+dx[k]) && x[i] != j + dx[k] && x[i+1] != j + dx[k])
							t[i+1][j+dx[k]] = 1;
				} else {
					for (int k = 1; k <= n; k ++)
						if (x[i+1] != k)
							t[i+1][k] = 1;
				}
			}
	forn (i, L) {
		bool ca = 1;
		forn (j, n+1)
			if (t[i][j])
				ca = 0;
		if (ca) {
			cout << "Controller " << i << endl;
			return 0;
		}
	}
	cout << "Stowaway" << endl;
	return 0;
}