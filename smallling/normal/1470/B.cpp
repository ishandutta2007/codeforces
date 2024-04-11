#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 30;

int n, m;
int a[N], prime[1000010], vis[1000010], c[1000010], ans[2], cnt[1000010];

void sieve(int n) {
	for(int i = 2; i <= n; i++) {
		if(!vis[i])prime[++*prime] = i;
		for(int j = 1; j <= *prime && 1ll * i * prime[j] <= n; j++) {
			int x = i * prime[j];
			vis[x] = 1;
			if(i % prime[j] == 0)break;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	sieve(1000000);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			c[i] = 1;
			int x = a[i];
			for(int j = 2; 1ll * j * j <= x; j++)
				if(x % j == 0) {
					int cnt = 0;
					while(x % j == 0) {
						x /= j;
						cnt ^= 1;
					}
					if(cnt)c[i] *= j;
				}
			c[i] *= x;
		}
		ans[0] = ans[1] = 0;
		sort(c + 1, c + 1 + n);
		for(int i = 1; i <= n; i++)
			cnt[c[i]]++;
		for(int i = 1; i <= n; i++)
			ans[0] = max(ans[0], cnt[c[i]]);
		ans[1] = cnt[1];
		for(int i = 1; i <= n; i++)
			if(c[i] != c[i - 1] && c[i] != 1 && cnt[c[i]] % 2 == 0)ans[1] += cnt[c[i]];
		for(int i = 1; i <= n; i++)
			if(c[i] != 1 && cnt[c[i]] % 2 == 1)ans[1] = max(ans[1], cnt[c[i]]);
		scanf("%d", &m);
		while(m--) {
			long long x;
			scanf("%lld", &x);
			x = min(x, 1ll);
			printf("%d\n", ans[x]);
		}
		for(int i = 1; i <= n; i++)
			cnt[c[i]]--;
	}
}