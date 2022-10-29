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
#include <set>
#include <map>
#include <deque>

#ifdef WIN32
	#define LLD "%I64d"
	#define LLU "%I64u"
#else
	#define LLD "%lld"
	#define LLU "%llu"
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define fill(a,x) memset(a,x,sizeof(a))
#define forn(i,a,b) for(int i = (a); i < (b); ++i)

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

#define maxn 100500

int par[maxn];
bool used[maxn];
ll ans1[maxn], ans[maxn];
ll w[maxn];
int n;
vector < int > sm[maxn];

ll lmax(const ll &a, const ll &b) {
	return (a < b) ? b : a;
}

int DFS(int x) {
	used[x] = true;
	ans1[x] = ans[x] = 0LL;
	for (int i = 0; i < sz(sm[x]); ++i) 
		if (!used[sm[x][i]]) {
			DFS(sm[x][i]);
			ans1[x] = lmax(ans1[x], ans1[sm[x][i]]);
			ans[x] = lmax(ans[sm[x][i]], ans[x]);
		}
	w[x] += ans[x] - ans1[x];
	if (w[x] > 0)
		ans1[x] += w[x];
	else
		ans[x] += (-w[x]);
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		sm[a].pb(b);
		sm[b].pb(a);
	}
	for (int i = 0; i < n; ++i)
		scanf(LLD, w + i + 1);
	DFS(1);
	printf(LLD"\n", ans[1] + ans1[1]);
	return 0;
}