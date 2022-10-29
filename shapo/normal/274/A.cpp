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

int a[maxn];
int n, ans, k;
int res[maxn];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	set < int > used;
	for (int i = 0; i < n; ++i) {
		if (a[i] % k || !used.count(a[i] / k))
			used.insert(a[i]), ++ans;
	}
	printf("%d\n", ans);
	return 0;
}