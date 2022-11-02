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

int n, k;
vector <int> a;

bool check (int x) {
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7)
			return 0;
		x /= 10;
	}
	return 1;
}

vector <int> b;
int64 t[2000][2000];
const int64 P = 1000000007;
int64 F[200000];

int64 power (int64 a, int64 b) {
	int64 res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % P;
		a = (a * a) % P;
		b >>= 1;
	}
	return res;
}

int64 calcC (int n, int k) {
	return F[n] * power (F[k], P-2) % P * power (F[n-k], P-2) % P;
}

int it = 0;

void go (int64 cur) {
	if (cur > 1000000000LL)
		return;
	it ++;
	go (cur * 10LL + 4);
	go (cur * 10LL + 7);
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d%d", &n, &k);
	a.resize (n);
	forn (i, n)
		scanf ("%d", &a[i]);
	sort (all (a));
	int k1 = 0;
	int l = 0;
	forn (i, a.size()) {
		if (i == 0)
			l = 1;
		else {
			if (a[i] == a[i-1] && check (a[i]))
				l ++;
			else {
				if (l == 1)
					k1 ++;
				else
					b.pb (l);
				l = 1;
			}
		}
	}
	if (l == 1)
		k1 ++;
	else
		b.pb (l);
	seta (t, 0);
	t[0][0] = 1;
	forn (i, 2000)
		t[i][0] = 1;
	for (int i = 1; i <= I b.size(); i ++)
		for (int j = 1; j <= i; j ++)
			t[i][j] = (t[i-1][j] + t[i-1][j-1] * (int64)b[i-1]) % P;
	int64 res = 0;
	F[0] = 1;
	for (int i = 1; i <= n; i ++)
		F[i] = (F[i-1] * i) % P;
	forn (i, min (k, I b.size())+1)
		if (k - i <= k1)
			res = (res + t[b.size()][i] * calcC (k1, k-i)) % P;
	cout << res << endl;
	return 0;
}