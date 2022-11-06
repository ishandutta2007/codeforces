#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N = 3e5+5, K = 55, W = 50;

int n, m, a[N], ans[K];

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		if(!ans[a[i]]) ans[a[i]] = i;
	}
	while(m--) {
		int qwq;
		scanf("%d", &qwq);
		printf("%d\n", ans[qwq]);
		rep(i, 1, W) if(ans[i] < ans[qwq]) ++ans[i];
		ans[qwq] = 1;
	}
	return 0;
}