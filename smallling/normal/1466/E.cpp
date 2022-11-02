#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 50;
const int mo = 1e9 + 7;

int cnt[60][2];
long long a[N];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(cnt, 0, sizeof(cnt));
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		int ans = 0;
		for(int x = 0; x < 60; x++) {
			for(int i = 1; i <= n; i++)
				cnt[x][(a[i] >> x) & 1]++;
		}
		for(int i = 1; i <= n; i++) {
			int sum = 0;
			for(int x = 0; x < 60; x++)
				if((a[i] >> x) & 1) {
					sum += (1ll << x) % mo * cnt[x][1] % mo;
					sum %= mo;
				}
			for(int x = 0; x < 60; x++) {
				if((a[i] >> x) & 1) {
					ans += (1ll << x) % mo * n % mo * sum % mo;
				}
				else {
					ans += (1ll << x) % mo * cnt[x][1] % mo * sum % mo;
				}
				ans %= mo;
			}
		}
		printf("%d\n", ans);
	}
}