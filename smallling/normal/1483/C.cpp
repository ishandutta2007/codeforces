#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n, h[N], v[N], q[N];
long long pre[N], f[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	int r = 0;
	for(int i = 1; i <= n; i++) {
		pre[i] = f[i - 1];
		while(r && h[i] < h[q[r]]) {
			pre[i] = max(pre[i], pre[q[r]]);
			r--;
		}
		f[i] = pre[i] + v[i];
		if(r)f[i] = max(f[i], f[q[r]]);
		q[++r] = i;
	}
	printf("%lld\n", f[n]);
}