#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e6 + 11;
using ll = long long;

ll cnt[N];
ll pre[N];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		int x; scanf("%d", &x);
		cnt[x] ++;
	}
	for(int i = 1; i < N; i ++)
		for(int j = 1; i * j < N; j ++) {
			if(i == j) pre[i * j] += cnt[i] * (cnt[i] - 1);
			else pre[i * j] += cnt[i] * cnt[j];
		}
	for(int i = 1; i < N; i ++)
		pre[i] += pre[i - 1];
	int q; scanf("%d", &q);
	ll all = ll(n) * (n - 1);
	while(q --) {
		ll x; scanf("%d", &x);
		printf("%lld\n", all - pre[x - 1]);
	}
	return 0;
}