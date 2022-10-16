#pragma GCC optimize("O3")

#define _SCL_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <cassert>
#include <ciso646>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <locale>
#include <numeric>
#include <regex>
#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define speedup cout.tie(nullptr);cin.tie(nullptr);ios_base::sync_with_stdio(false);
#define coutdouble cout<<setprecision(20);cout<<fixed;
/*------CommentInInteractive--------*/
#define endl "\n"
/*----------------------------------*/
const int INF = 1000 * 1000 * 1000;
const ll LLINF = 2LL*1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;
const int MOD = 1000 * 1000 * 1000 + 7;
const int RMOD = MOD - 2;
const int N = 2*100*1000 + 322;
const int P1M = 1336337; //Large prime number ( ~1M )
const int P1K = 1009; //Big prime ( ~1K )
const ld Pi = acos(-1);
/*--------------------------------------------------IO_FILES-----------------------------------------------*/
const char * infile =
#ifdef LOCAL
"input.txt"
#else
""
#endif
;
const char * outfile =
#ifdef LOCAL
""
#else
""
#endif
;
/*----------------------------------------------------MATHS------------------------------------------------*/
inline int gcd(int a, int b) { while (b) { int tmp = a%b; a = b; b = tmp; } return a; }
inline void gcd(vector<int> a) { while (a.size() > 1) { int tmp1 = a.back(), tmp2 = a.back(); a.pop_back(), a.pop_back(); a.push_back(gcd(tmp1, tmp2)); } }
inline ll pwm(ll x, ll pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= x; x *= x; pow >>= 1; x %= MOD; mlt %= MOD; } else { pow >>= 1; x *= x; x %= MOD; } }return mlt; }
inline ll pw(ll x, int pow) { ll mlt = 1; while (pow) { if (pow & 1) { mlt *= x; x *= x; pow >>= 1; } else { pow >>= 1; x *= x; } }return mlt; }
inline ll rev(ll r) { return pwm(r, RMOD); }
/*--------------------------------------------------------------------------------------------------------*/

unordered_set <int> kl;
int ord[N];
string txt, pat;

inline bool good(int mid) {
	kl.clear();
	for (int i = 0; i < mid; ++i) {
		kl.insert(ord[i]-1);
	}
	int ptr = 0, j = 0;
	for (; j < txt.size() && ptr < pat.size() ; ++j) {
		if (kl.count(j))
			continue;
		if (pat[ptr] == txt[j])
			++ptr;
	}
	if (ptr == pat.size())
		return true;
	return false;
}

inline void solve(ld tt) {
	cin >> txt >> pat;
	for (int i = 0; i < txt.size(); ++i) {
		cin >> ord[i];
	}
	int l = 0, r = txt.size();
	while (r - l > 1) {
		int mid = (r + l) >> 1;
		if (good(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l << endl;
}

int main() {
	ld tt = clock();
	freopen(infile, "r", stdin);
	freopen(outfile, "w", stdout);

	speedup
	coutdouble

	solve(tt);

#ifdef LOCAL
	cout << "Time: " << ((ld)clock() - tt) / CLOCKS_PER_SEC << endl;
	while (true);
#endif // LOCAL
	return 0;
}