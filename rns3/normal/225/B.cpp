#include <bits/stdc++.h>
using namespace std;

int a[101], v[101];

main() {
	///freopen("2.in", "r", stdin);
	int s, k;
	scanf("%d %d", &s, &k);
	int cnt = 0, num = 0;
	v[++cnt] = 1;
    for(int i = 0; ; i ++) {
		int sum = 0;
        for(int i = cnt; i > 0 && i >= cnt - k + 1; i --) {
        	sum += v[i];
			if(sum > s) break;
        }
        if(sum > s) break;
        v[++cnt] = sum;
    }
    ///for(int i = 1; i <= cnt; i ++) printf("%d ", v[i]);puts("");
    while(s) {
		int x = upper_bound(v + 1, v + cnt + 1, s) - v;
		x --;
		a[num++] = v[x];
		s -= v[x];
    }
    if(num == 1 && k > 1) a[num++] = 0;
	printf("%d\n", num);
	for(int i = 0; i < num; i ++) {
		printf("%d ", a[i]);
	}
	puts("");
}