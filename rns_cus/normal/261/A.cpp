#include <bits/stdc++.h>

using namespace std;

#define N 100100

int n, m;
int a[N], q[N], ans;

void run() {
	int t = q[1];
	for(int i = n; i > 0; i --) {
		for(int j = 0; j < t; j ++) {
			ans += a[i];
			i --;
			if(!i) return;
		}
		i --;
	}
}

int main() {
	scanf("%d", &m);
	for(int i = 1; i <= m; i ++) scanf("%d", q + i);
	sort(q + 1, q + m + 1);
    scanf("%d", &n);
    for(int i = 1 ;i <= n; i ++) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    run();
    printf("%d\n", ans);
	return 0;
}