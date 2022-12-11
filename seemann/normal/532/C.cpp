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
const int MAXN = 1e5;

int main() {
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;
    if (xp <= xv && yp <= yv) {
        cout << "Polycarp\n";
        return 0;
    }
    if (xp + yp <= max(xv, yv)) {
        cout << "Polycarp\n";
        return 0;
    }
    cout << "Vasiliy\n";
	return 0;
}