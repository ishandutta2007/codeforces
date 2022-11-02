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

const i64 inf = 1e18;

int ptr[5];
vi els[5];
i64 sum = 0;

int n;
int k; i64 b; i64 c;

i64 calc(i64 x) {
	return x * k * b + 4 * c * k - sum;
}

i64 vals[5];

i64 solve(const vi& t) {
	i64 res = inf;
	if (b >= 5 * c) {
		i64 s = 0;
		forn (i, k - 1) s += t[i];
		for (int i = k - 1; i < n; i++)
		{
			res = min(res, t[i] * (k - 1LL) - s);
			s -= t[i - (k - 1)];
			s += t[i];
		}
		return res;
	}
	forn (i, 5) els[i].clear(), ptr[i] = 0;
	forn (i, k) {
		els[t[i] % 5].pb(t[i] / 5);
	}
	sum = 0;
	forn (i, 5) {
		sum += els[i].size() * c * i;
		for (int x: els[i]) sum += b * x;
	}
	//cerr << "!";
	res = calc(t[k - 1] /5);
	//forn (i, n) cerr << t[i] <<  " "; cerr << endl;
	for (int i = k; i < n; i++) {
		els[t[i] % 5].pb(t[i] / 5);
		sum += (t[i] % 5) * c;
		sum += b * (t[i] / 5);
		
		forn (j, 5)
			if (ptr[j] >= (int)els[j].size())
				vals[j] = inf;
			else
				vals[j] = j * c + b * els[j][ptr[j]];
		int ind = min_element(vals, vals + 5) - vals;
		sum -= vals[ind];
		ptr[ind]++;
		res = min(res, calc(t[i] / 5));
		//cerr << i << " " << res << endl;
	}
	//cerr << res << endl;
	return res;
}

int main()
{
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> k >> b >> c;
    vi t(n); forn (i, n) cin >> t[i];
    sort(all(t));
    int mn = t[0];
    forn (i, n) t[i] -= mn;
    
	i64 ans = inf;
    forn(it, 5) {
		ans = min(ans, solve(t));
		forn (i, n) t[i]++;
	}
	cout << ans << endl;
    return 0;
}