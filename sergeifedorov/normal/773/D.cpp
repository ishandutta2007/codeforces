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

const int nmax = 2020;

long long g[nmax][nmax];
long long res[nmax];
long long cheap[nmax], small[nmax];
bool solved[nmax];
int n;

void update(int v, long long now, long long chp) {
	if (res[v] > now) {
		res[v] = now;
		cheap[v] = chp;
	}
}

int main ()
{
	//  freopen("input.txt", "rt", stdin);
	//  freopen("output.txt", "wt", stdout);
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = i + 1; j < n; j ++) {
			int q;
			scanf("%d", &q);
			g[j][i] = g[i][j] = q;
		}
	for (int i = 0; i < n; i ++) {
		res[i] = 1e18;
		solved[i] = false;
		small[i] = 1e18;
	}
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < i; j ++) {
			long long now = g[i][j] * (n - 1);
			update(i, now, g[i][j]);
			update(j, now, g[i][j]);
			small[i] = min(small[i], g[i][j]);
			small[j] = min(small[j], g[i][j]);
		}
	while (1) {
		int v = -1;
		for (int i = 0; i < n; i ++)
			if (!solved[i] && (v == -1 || res[v] > res[i]))
				v = i;
		if (v == -1) break;
		// cout << v << " " << res[v] << " " << cheap[v] << " " << endl;
		solved[v] = true;
		for (int i = 0; i < n; i ++)
			if (!solved[i]) {
				long long val = min(res[v] - cheap[v] + g[v][i], res[v] - cheap[v] * 2 + small[i] * 2);
				update(i, val, cheap[v]);
			}
	}
	for (int i = 0; i < n; i ++)
		cout << res[i] << endl;

	return 0;
}