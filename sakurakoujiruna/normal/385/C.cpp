#include <bits/stdc++.h>
using namespace std;

const int N = 10000011;
typedef long long ll;

int fac[N];
int cnt[N];
ll pre[N];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i ++) {
		int x; scanf("%d", &x);
		cnt[x] ++;
	}
	for(int i = 2; i < N; i ++) {
		if(fac[i] == 0)
			for(int j = i; j < N; j += i) {
				pre[i] += cnt[j];
				fac[j] ++;
			}
		pre[i] += pre[i - 1];
	}
	int m; scanf("%d", &m);
	for(int i = 0; i < m; i ++) {
		int l, r; scanf("%d%d", &l, &r);
		r = min(r, (int)1e7);
		l = min(l, r);
		printf("%d\n", pre[r] - pre[l - 1]);
	}
	return 0;
}