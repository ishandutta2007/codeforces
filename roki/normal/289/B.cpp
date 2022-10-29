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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int n, m, d;
int a[100][100];

bool read() {
	if (!(cin >> n >> m))
		return false;
	cin >> d;
	forn (i, n)
		forn (j, m)
		cin >> a[i][j];
    return true;
}

void solve(){
	int ans = 1e9;
	vector<bool> ok (20001, false);
	forn (i, 20001)
		if (i % d == 0)
			ok[i] = true;
	forn (P, 10001)
	{
		int cur = 0;
		forn (i, n)
			forn (j, m)
		{
			if (!ok[abs(a[i][j] - P)])
				cur = -1e9;
			else
				cur += abs(a[i][j] - P) / d;
		}
		if (cur >= 0)
			ans = min(ans, cur);
	}
	if (ans == 1e9)
		ans = -1;
	cout << ans << endl;
}

int main() {
#ifdef SU6
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    while (read())
        solve();
    return 0;
}