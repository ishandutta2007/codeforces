#include <cstdio>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E5 + 10;

int d, n, m;
PII a[MAXN];

int main(){
	scanf("%d%d%d", &d, &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d", &a[i].st, &a[i].nd);
	sort(a + 1, a + m + 1);

	int l = 0, r = 0;
	ll ans = 0;
	a[0] = PII(n, 0);
	a[m + 1].st = d;
	for (int i = m; i > 0; --i)
		a[i + 1].st -= a[i].st;
	for (int i = 1; i <= m + 1; ++i){
		if (a[i].st > n){
			ans = -1;
			break;
		}
		int t = a[i].st;
		for (; a[l].st <= t; ++l){
			t -= a[l].st;
			ans += a[l].st * (ll)a[l].nd;
		}
		a[l].st -= t;
		ans += t * (ll)a[l].nd;

		for (; l <= r && a[r].nd > a[i].nd; --r)
			a[i].st += a[r].st;
		a[++r] = a[i];
	}
	printf("%I64d\n", ans);
	return 0;
}