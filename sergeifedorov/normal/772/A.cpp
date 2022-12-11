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
#include <bitset>
#include <sstream>
#include <queue>

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
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int nmax = 100100;

int n, p;
int a[nmax], b[nmax];

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n >> p;
	for (int i = 0; i < n; i ++)
		scanf("%d %d", &a[i], &b[i]);

	double l = 0;
	double r = 1e10;
	bool inf = 1;
	while ((r - l) > 1e-8) {
		double m = (l + r) / 2.0;
		double need = 0;
		for (int i = 0; i < n; i ++)
			need -= min(0.0, b[i] - a[i] * m);
		if (need > p * m)
			r = m, inf = 0;
		else
			l = m;
	}
	if (inf){
		cout << -1 << endl;
	}else 
	printf("%0.6lf\n", (l + r) / 2.0);

	return 0;
}