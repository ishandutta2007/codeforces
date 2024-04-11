#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];
pair<int,int> pre[N], suf[N];

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		pre[1] = make_pair(a[1], 1);
		suf[n] = make_pair(a[n], n);
		for (int i = 2; i <= n; i ++) 
			pre[i] = min(pre[i-1], make_pair(a[i], i));
		for (int i = n - 1; i >= 1; i --) 
			suf[i] = min(suf[i+1], make_pair(a[i], i));

		bool ok = 0;
		for (int i = 2; i < n; i ++) {
			if (pre[i-1].first < a[i] && suf[i+1].first < a[i]) {
				ok = true; 
				printf("YES\n");
				printf("%d %d %d\n", pre[i-1].second, i, suf[i+1].second);
				break;
			}
		}
		if (!ok) {
			printf("NO\n");
		}
	}
}