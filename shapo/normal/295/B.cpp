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

#define maxn 501

int d[maxn][maxn];
int a[maxn][maxn];
int c[maxn][maxn];
int ord[maxn];
int n;
ll ok[maxn];

int main() {
	scanf("%d", &n);
	forn(i, 0, n) {
		forn(j, 0, n) {
			scanf("%d", &a[i + 1][j + 1]);
		}
	}
	forn(i, 0, n)
		scanf("%d", ord + n - i);
	forn(i, 0, n) {
		forn(j, 0, n) {
			c[i + 1][j + 1] = d[i + 1][j + 1] = a[ord[i + 1]][ord[j + 1]];
		}
	}
	forn(k, 1, n + 1) {
		ok[n - k + 1] = 0LL;
		forn(i, 1, n + 1) {
			forn(j, 1, n + 1) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
		forn(i, 1, k + 1)
			forn(j, 1, k + 1)
				ok[n - k + 1] += ll(d[i][j]);
	}
	forn(i, 1, n + 1)
		printf(LLD" ", ok[i]);
	printf("\n");
	return 0;
}