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
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>

#ifdef WIN32
#define LLD "%I64d"
#define LLU "%I64u"
#else
#define LLD "%lld"
#define LLU "%llu"
#endif

using namespace std;

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;

#define fill(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a.size())
#define forn(i,a,b) for(int i = (a); i < (b); ++i)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

#define maxn 100500

int ans;
int ok[maxn];
int n;
int curbit;

inline int chb(int x, int bit) {
	return (x & (1 << bit));
}

int find_l(int l, int r) {
	int cmax = 0;
	forn(i, l + 1, r) {
		cmax = max(cmax, ok[i]);
		ans = max(ans, ok[l] ^ cmax);
	}
	return 0;
}

int find_r(int l, int r) {
	int cmax = 0;
	for (int i = r - 2; i >= l; --i) {
		cmax = max(cmax, ok[i]);
		ans = max(ans, cmax ^ ok[r - 1]);
	}
	return 0;
}

int find_ans(int pos_bit, int l, int r) {
	if (l == r - 1) return 0;
	bool res = false;
	forn(i, l + 1, r)
		if (chb(ok[i], pos_bit) != chb(ok[i - 1], pos_bit)) {
			res = true;
			break;
		}
	if (!res) {
		find_ans(pos_bit - 1, l, r);
		return 0;
	}
	forn(i, l, r) {
		if (chb(ok[i], pos_bit)) {
			if (i != l) {
				int cur = i - 1;
				while (cur >= l && chb(ok[cur], pos_bit) == 0) --cur;
				find_r(cur + 1, i + 1);
			}
			if (i != r - 1) {
				int cur = i + 1;
				while (cur < r && chb(ok[cur], pos_bit) == 0) ++cur;
				find_l(i, cur);
			}
		}
	}
	return 0;	
}

int main() {
	scanf("%d", &n);
	forn(i, 0, n)
		scanf("%d", ok + i);
	find_ans(29, 0, n);
	printf("%d\n", ans);
	return 0;
}