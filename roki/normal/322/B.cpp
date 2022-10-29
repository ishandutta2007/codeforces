#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define xrange(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long li;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int a, b, c;

bool read() {
	if (!(cin >> a >> b >> c))
		return false;
	return true;
}

void solve() {
	int ans = 0;
	forn (i, 3)
	{
		if (a < i || b < i || c < i)
			break;
		ans = max(ans, i + (a - i) / 3 + (b - i) / 3 + (c - i) / 3);
	}
	cout << ans << endl;
}

int main() {
#ifdef SU6
    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
#endif
    while (read())
        solve();
    return 0;
}