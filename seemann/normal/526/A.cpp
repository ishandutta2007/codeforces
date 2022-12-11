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
const int MAXN = 1110;

char s[MAXN];


int main() {
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	bool ans = false;
	for (int l = 1; l <= n; ++l) {
	    FOR(st, n) {
	        bool flag = true;
	        for (int i = st, it = 0; it < 5; ++it, i += l) {
	            if (i >= n) {
	                flag = false;
	                break;
	            }

	            if (s[i] == '.') {
	                flag = false;
	                break;
	            }
	        }
	        if (flag) {
	            ans = true;
	        }
	    }
	}
	if (ans) {
	    cout << "yes\n";
	} else {
	    cout << "no\n";
	}

	return 0;
}