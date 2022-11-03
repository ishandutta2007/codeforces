#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int a[MAXN];
int cnt[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	int m;
	scanf("%d", &m);
	for (int t, i = 0; i < m; ++i){
		scanf("%d", &t);
		++cnt[t];
	}

	if (n == 2){
		printf("%I64d\n", (m - 1ll) * (a[2] - a[1]));
		return 0;
	}
	
	int rn = cnt[2];
	for (int i = 3; i < n; ++i)
		rn = min(rn, cnt[i]);
	rn >>= 1;
	rn = min(rn, cnt[1]);
	rn = min(rn, cnt[n]);

	ll ans = rn * 2ll * (a[n] - a[1]);
	cnt[1] -= rn;
	cnt[n] -= rn;
	for (int i = 2; i < n; ++i)
		cnt[i] -= rn << 1;

	m -= rn * (2 * n - 2);

	if (m == 0){
		bool flag = true;
		for (int i = 2; i < n; ++i)
			flag &= a[i + 1] - a[i] == a[i] - a[i - 1];
		if (flag)
			ans -= a[2] - a[1];
		else
			ans = -1;
	}
	else if (m == (2 * n - 3) && cnt[1] == 0)
		ans += 2ll * (a[n] - a[2]);
	else if (m == (2 * n - 3) && cnt[n] == 0)
		ans += 2ll * (a[n - 1] - a[1]);
	else{
		int l, r;
		for (l = 2; cnt[l] == cnt[1] * 2; ++l)
			if (cnt[1])
				ans += a[l] - a[l - 1] << 1;
		for (r = n - 1; cnt[r] == cnt[n] * 2; --r)
			if (cnt[n])
				ans += a[r + 1] - a[r] << 1;
		l -= cnt[1];
		r += cnt[n];
		ans += a[r] - a[l];
	}
	printf("%I64d\n", ans);

	return 0;
}