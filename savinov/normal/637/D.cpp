#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    vi a(n + 1, -1); for1 (i, n) cin >> a[i];
    sort(all(a));
    vi dp(n + 1, -1);
    int r = 1;
    dp[0] = 0;
	forn (i, n)
		if (dp[i] != -1) {
			if (a[i + 1] - a[i] - 2 >= s) {
				int p = a[i + 1] - 1 + d;
				while (r <= n && a[r] + 1 <= p) {
					dp[r] = i;
					r++;
				} 
				//cerr << i << " " << r << endl;
			}
		}
	if (dp[n] == -1) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	vector<pii> ans;
	if (a.back() != m - 1) {
		ans.pb(mp(1, m - a.back() - 1));
	}
	int cur = n;
	while (cur > 0) {
		int pr = dp[cur];
		ans.pb(mp(2, (a[cur] + 1) - (a[pr + 1] - 1)));
		ans.pb(mp(1, a[pr + 1] - a[pr] - 2));
		cur = pr;
	}
	reverse(all(ans));
	for (auto w: ans)
		if (w.fi == 1)
			cout << "RUN " << w.se << "\n";
		else
			cout << "JUMP " << w.se << "\n";
    return 0;
}