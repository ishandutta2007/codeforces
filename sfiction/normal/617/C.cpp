#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<ll, int> PLI;

const int MAXN = 2E3 + 10;

int n, x1, y1, x2, y2;
int x[MAXN], y[MAXN];
PLI a[MAXN];

ll sqr(ll x){
	return x * x;
}

int main(){
	scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
	a[0] = PLI(0ll, 0);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", &x[i], &y[i]);
		a[i] = PLI(sqr(x1 - x[i]) + sqr(y1 - y[i]), i);
	}
	sort(a, a + n + 1);
	ll dis = 0, ans = a[n].st;
	for (int i = n - 1; i >= 0; --i){
		dis = max(dis, sqr(x2 - x[a[i + 1].nd]) + sqr(y2 - y[a[i + 1].nd]));
		ans = min(ans, a[i].st + dis);
	}
	printf("%I64d\n", ans);
	return 0;
}