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
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <string>

using namespace std;

#ifdef WIN32
	#define LLD "%I64d"
	#define LLU "%I64u"
#else
	#define LLD "%lld"
	#define LLU "%llu"
#endif

#define pb push_back
#define mp make_pair
#define fill(a,x) memset(a,x,sizeof(a))
#define sz(a) (int)(a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < pii > vpii;

#define maxn 100500

int n;
ll ans = 1LL;
ll m;
vpii a, b;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int cur;
		scanf("%d", &cur);
		a.pb(mp(cur, i + 1));
	}
	for (int i = 0; i < n; ++i) {
		int cur;
		scanf("%d", &cur);
		a.pb(mp(cur, i + 1));
	}
	scanf(LLD, &m);
	sort(a.begin(), a.end());
	int l = 0, r = 0;
	while (l < sz(a)) {
		int p = 0;
		r = l;
		while (r != sz(a) && a[l].first == a[r].first) {
			if (r != l && a[r].second == a[r - 1].second)
				++p;
			++r;
		}
		int x = r - l;
		for (int i = x; i > 2 * p; --i) 
			ans = (ans * ll(i)) % ll(m);
		for (int i = p; i >= 1; --i) {
			ans = (ans * ll(i)) % ll(m);
			ans = (ans * ll(2 * i - 1)) % ll(m);
		}
		l = r;
	}
	printf(LLD "\n", ans);
	return 0;
}