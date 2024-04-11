#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10, MAXM = 1E7 + 10;

int m, n;
int a[MAXN], b[MAXN];

ll modExp(ll e, ll n, ll m){
	ll ret = 1;
	for (; n; n >>= 1, e = e * e % m)
		if (n & 1)
			ret = ret * e % m;
	return ret;
}

int main(){
	scanf("%d%d", &m, &n);
	if (m == n){
		puts("0 1");
		return 0;
	}

	ll s = 0;
	unordered_set<int> lst;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	bool rev = false;
	if (m < 2 * n){
		rev = true;
		sort(a, a + n);
		for (int i = 0, j = 0, k = 0; i < m; ++i){
			if (j < n && i == a[j])
				++j;
			else
				b[k++] = i;
		}
		n = m - n;
		copy_n(b, n, a);
	}
	sort(a, a + n);
	
	if (n == 1){
		printf("%d 1\n", !rev ? a[0] : (a[0] + 1) % m);
		return 0;
	}
	for (int i = 0; i < n; ++i){
		lst.insert(a[i]);
		s = (s + a[i]) % m;
		b[i] = i;
	}
	random_shuffle(a, a + n);
	random_shuffle(b, b + n);

	ll inv = modExp(n * (n - 1ll) / 2 % m, m - 2, m);
	for (int i = 0; i < n; ++i){
		ll x = a[i];
		ll d = (s + n * (m - x)) % m * inv % m;
		if (d == 0)
			continue;

		bool flag = true;
		for (int j = 0; flag && j < n; ++j)
			flag &= lst.count((x + d * b[j]) % m);
		if (flag){
			if (!rev)
				printf("%lld %lld\n", x, d);
			else
				printf("%lld %lld\n", (x + d * n) % m, d);
			return 0;
		}
	}
	puts("-1");
	return 0;
}