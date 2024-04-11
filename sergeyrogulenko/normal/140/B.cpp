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

int n;
int a[300][300];
int b[300];
int ans[300];

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	scanf ("%d", &n);
	forn (i, n) {
		forn (j, n)
			scanf ("%d", &a[i][j]);
		forn (j, n)
			a[i][j] --;
		forn (j, n)
			ans[a[i][j]] = j;
		forn (j, n)
			a[i][j] = ans[j];
	}
	forn (i, n)
		a[i][i] = inf;
	forn (i, n)
		scanf ("%d", &b[i]);
	forn (i, n)
		b[i] --;
	forn (j, n)
		ans[b[j]] = j;
	forn (j, n)
		b[j] = ans[j];
	forn (i, n)
		ans[i] = -1;
	int pcur = -1;
	int cur = 0;
	forn (i, n) {
		forn (j, n)
			if (cur != j) {
				if (ans[j] == -1 || a[j][ans[j]] > a[j][cur])
					ans[j] = cur;
			} else
			if (pcur != j && pcur != -1 && (ans[j] == -1 || a[j][ans[j]] > a[j][pcur]))
				ans[j] = pcur;
		if (i == n-1)
			break;
		if (b[cur] > b[i+1]) {
			pcur = cur;
			cur = i+1;
		} else
		if (pcur == -1 || b[pcur] > b[i+1])
			pcur = i+1;
	}
	forn (i, n)
		printf ("%d ",ans[i]+1);
	cout << endl;
	return 0;
}