#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;
const int INF = 1E8 + 10;

int a[MAXN];
int pre[MAXN], nex[MAXN];
int r, sta[MAXN];

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = n - 1; i > 0; --i)
		a[i] = abs(a[i] - a[i - 1]);
	a[n] = INF;

	r = -1;
	for (int i = 1; i <= n; ++i){
		for (; r >= 0 && a[sta[r]] <= a[i]; --r)
			nex[sta[r]] = i - 1;
		pre[i] = r < 0 ? 1 : sta[r] + 1;
		sta[++r] = i;
	}

	while (q--){
		int l, r;
		scanf("%d%d", &l, &r);
		ll cnt = 0;
		--r;
		for (int i = l; i <= r; ++i)
			cnt += (min(r, nex[i]) - i + 1) * (ll)(i - max(l, pre[i]) + 1) * a[i];
		printf("%I64d\n", cnt);
	}

	return 0;
}