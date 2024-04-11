#include <cassert>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const int MAXN = 1e6 + 100;

int a[MAXN];
int mx[MAXN];
int val[MAXN];


int h, n;

int main() {
//	freopen("b.in", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	scanf("%d", &h);
	h++;
	n = (1 << h) - 1;
	a[0] = 0;
	FOR(i, n) {
	    scanf("%d", &a[i + 1]);
	}
	for (int i = n - 1; i >= 0; --i) {
	    mx[i] = 0;
	    if (2 * i + 2 < n)
    	    mx[i] = max(val[2 * i + 1], val[2 * i + 2]);
	    val[i] = a[i] + mx[i];
	}
	int ans = 0;
	FOR(i, n) {
	    if (2 * i + 2 >= n)
	        break;
	    ans += max(val[2 * i + 1], val[2 * i + 2]) - min(val[2 * i + 1], val[2 * i + 2]);
	}
	cout << ans << '\n';

	return 0;
}