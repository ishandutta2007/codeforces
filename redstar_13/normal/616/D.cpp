//2016-06-12 22:27:45.471000
#include <bits/stdc++.h>

using namespace std;

#define NN 1000010
#define rep(i, a, b) for (int i = (a); i < (b); i ++)
#define clr(a, b) memset(a, b, sizeof(a))

int a[NN], vst[NN];

int main() {
	
	int N, K, st, en, la, ct, ans, t;
	scanf("%d%d", &N, &K);
	ct = 0; clr(vst, 0);
	la = 0; ans = 0;
	rep(i, 0, N) {
		scanf("%d", a + i);
		if (vst[a[i]] == 0) ct ++;
		vst[a[i]] ++;
		if (ct > K) {
			while (1) {
				vst[a[la]] --;
				t = vst[a[la]];
				la ++;
				if (t == 0) break ;
			}
			ct = K;
		}
		if (ans < i - la + 1) {
			ans = i - la + 1;
			st = la + 1; en = i + 1;
		}
	}
	printf("%d %d\n", st, en);
	
	return 0;
}