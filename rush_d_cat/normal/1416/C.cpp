#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
int ch[N * 30][2], tot, sz[N * 30];
LL ans[32][2];
int n, a[N];

void insert(int x) {
	int rt = 0;
	for (int i = 29; i >= 0; i --) {
		int bit = x >> i & 1;
		if (ch[rt][bit] == 0) {
			ch[rt][bit] = ++ tot;
		}
		if (bit == 1) {
			if (ch[rt][0])
				ans[i][0] += sz[ ch[rt][0] ];
		} else {
			if (ch[rt][1])
				ans[i][1] += sz[ ch[rt][1] ];
		}
		rt = ch[rt][bit];
		sz[rt] ++;

	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		insert(a[i]);
	}	
	LL res = 0, X = 0;
	for (int i = 29; i >= 0; i --) {
		if (ans[i][0] >= ans[i][1]) {
			res += ans[i][1];  
		} else {
			res += ans[i][0]; X |= 1<<i;
		}
	}
	printf("%lld %lld\n", res, X);
}