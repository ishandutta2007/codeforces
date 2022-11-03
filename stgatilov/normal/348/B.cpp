#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int64 INF = 1000000000000000LL;
const int MAXN = 1<<20;

int n;
int64 wgt[MAXN];
int cnt[MAXN];
vector<int> nbr[MAXN];
int64 res[MAXN][2];

int64 divup(int64 a, int64 b) {
	if (b < 0) { a = -a;  b = -b; }
	int64 t = a / b;
	while (b*t > a) t--;
	while (b*t < a) t++;
	return t;
}

int64 Euclid(int64 a, int64 b, int64 &x, int64 &y) {
	if (b == 0) {
		x = (a<0 ? -1 : 1);
		y = 0;
		return a * x;
	}
	int64 q = a / b;
	int64 g = Euclid(b, a - q*b, y, x);
	y -= q*x;
	return g;
}

void Intersect(const int64 *r1, const int64 *r2, int64 *rs) {
	int64 a = r1[1];
	int64 b = -r2[1];
	int64 c = r1[0] - r2[0];
	int64 u, v;
	int64 g = Euclid(a, b, u, v);
	assert(c % g == 0);
	a /= g;
	b /= g;
	c /= g;
	u *= c;
	v *= c;
	int64 par = max(divup(-v, a), divup(u, b));
	u -= b*par;
	v += a*par;
	int64 rr0 = r1[0] - r1[1] * u;
	int64 rr1 = r2[1] * a;
	Ef("%I64d %I64d x %I64d %I64d -> %I64d %I64d\n", r1[0], r1[1], r2[0], r2[1], rr0, rr1);
	rs[0] = rr0;
	rs[1] = rr1;
}

bool vis[MAXN];
void DFS(int u) {
	vis[u] = true;

	int64 sumWgt = 0;
	int sumCnt = 0;
	int64 tres[2] = {INF, 1};
	int sonsK = 0;
	for (int i = 0; i<nbr[u].size(); i++) {
		int s = nbr[u][i];
		if (vis[s]) continue;
		DFS(s);
		sonsK++;
		sumWgt += wgt[s];
		sumCnt += cnt[s];
		if (tres[0] == INF) {
			tres[0] = res[s][0];
			tres[1] = res[s][1];
		}
		else
			Intersect(tres, res[s], tres);
	}
	tres[0] *= sonsK;
	tres[1] *= sonsK;
	if (tres[0] == 0)
		tres[1] = 1;

	if (sonsK == 0) {
		cnt[u] = 1;
		res[u][0] = wgt[u];
		res[u][1] = 1;
	}
	else {
		wgt[u] = sumWgt;
		cnt[u] = sumCnt;
		res[u][0] = tres[0];
		res[u][1] = tres[1];
	}
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%I64d", &wgt[i]);
	for (int i = 0; i<n-1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		nbr[a].push_back(b);
		nbr[b].push_back(a);
	}

	DFS(0);

	printf("%I64d\n", wgt[0] - res[0][0]);

	return 0;
}