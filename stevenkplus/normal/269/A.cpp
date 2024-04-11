#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define div divv
#define fi first
#define se second
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

typedef pair<int, int> pii;
map<int, int> mp;

int div(int a, int b) {
	if (a == 0) return 0;
	if (b > 15) return 1;
	int k = 1 << (2 * b);
	return (a + k - 1) / k;
}

int cmp(int p, int c, int num) {
	int k = div(num, (c - p));
	return k;
}

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		int tmp, a;
		scanf("%d %d", &tmp, &a);
		mp[tmp] += a;
	}
	pii prv;
	repi(p, mp) {
		int need = cmp(prv.fi, p->fi, prv.se);
		if (p->se < need) {
			p->se = need;
		}
		prv = *p;
	}
	int ans = prv.fi;
	int num = prv.se;
	do {
		num = div(num, 1);
		++ans;
	} while (num != 1);
	printf("%d\n", ans);
	return 0;
}