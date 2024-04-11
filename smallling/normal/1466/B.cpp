#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N], cnt[N << 1];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n + 1; i++)
			cnt[i] = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), cnt[a[i]]++;
		for(int i = 1; i <= n; i++)
			if(cnt[a[i]] > 1)cnt[a[i]]--, cnt[a[i] + 1]++;
		int ans = 0;
		for(int i = 1; i <= 2 * n + 1; i++)
			ans += cnt[i] > 0;
		printf("%d\n", ans);
	}
}