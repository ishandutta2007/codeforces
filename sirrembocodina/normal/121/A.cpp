#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

typedef long long int64;       
typedef long double ld;

vector<int64> lu;

void gen(int64 cur, int len) {
	lu.pb(cur);
	if (len == 10) {
		return;
	}
	gen(cur * 10 + 4, len + 1);
	gen(cur * 10 + 7, len + 1);
}

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	gen(0, 0);
	sort(lu.begin(), lu.end());
	int l, r;
	int64 L, R;
	cin >> L >> R;
	int64 ans = 0;
	forn (i, lu.size()) {
		if (lu[i] < L && L <= lu[i + 1]) {
			ans += (lu[i + 1] - L + 1) * lu[i + 1];
			l = i + 1;
		}
	}
	forn (i, lu.size()) {
		if (lu[i] < R && R <= lu[i + 1]) {
			ans -= (lu[i + 1] - R) * lu[i + 1];
			r = i + 1;
		}
	}
	forab (i, l, r) {
		ans += (lu[i + 1] - lu[i]) * lu[i + 1];
	}
	cout << ans;
}