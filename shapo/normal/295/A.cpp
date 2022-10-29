#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

#ifdef WIN32
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define forn(i,a,b) for(int i = (a); i < (b); ++i)

#define maxn 100500

int l[maxn], r[maxn], d[maxn];
ll a[maxn];
int x[maxn], y[maxn];
int n, m, k;
ll add[maxn];
int add_op[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	forn(i, 0, n) scanf(LLD, a + i);
	forn(i, 0, m) scanf("%d%d%d", l + i, r + i, d + i), --l[i];
	forn(i, 0, k) scanf("%d%d", x + i, y + i), --x[i];
	forn(i, 0, k) {
		++add_op[x[i]];
		--add_op[y[i]];
	}
	int cur = 0;
	forn(i, 0, m) {
		cur += add_op[i];
		ll tmp = cur * (ll)(d[i]);
		add[l[i]] += tmp;
		add[r[i]] -= tmp;
	}
	ll cur_add = 0LL;
	forn(i, 0, n) {
		cur_add += add[i];
		printf(LLD" ", a[i] + cur_add);
	}
	printf("\n");
	return 0;
}