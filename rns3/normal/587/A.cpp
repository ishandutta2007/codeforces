#include <cstdio>

#define N 2000005

int cnt[N];

main() {
    int n, x;
    for (scanf("%d", &n); n --; ) {
    	scanf("%d", &x);
		cnt[x] ++;
    }
    int rlt = 0;
    for (int i = 0; i < N; i ++) {
		rlt += cnt[i] & 1;
		if (i + 1 < N) cnt[i + 1] += cnt[i] / 2;
    }
    printf("%d\n", rlt);
}