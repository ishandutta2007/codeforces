#include <bits/stdc++.h>
using namespace std;

#define N 5050

int n;
int g[N], h[N];

int a[N], b[N];
int ans;

bool check() {
	b[0] = g[0] ^ a[0];
	for (int i = 1; i < n; i ++) b[i] = g[i] ^ a[0];
	for (int i = 1; i < n; i ++) a[i] = h[i] ^ b[0];
    for (int i = 0; i < n; i ++) if (a[i] >= n || b[i] >= n) return 0;
    for (int i = 0; i < n; i ++) if (a[b[i]] != i) return 0;
    sort (a, a + n);
    sort (b, b + n);
    for (int i = 0; i < n - 1; i ++) if (a[i] == a[i+1] || b[i] == b[i+1]) return 0;
    return 1;
}

int main() {
	scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
		printf("? %d %d\n", 0, i);
		fflush(stdout);
		scanf("%d", &g[i]);
    }
    h[0] = g[0];
    for (int i = 1; i < n; i ++) {
		printf("? %d %d\n", i, 0);
		fflush(stdout);
		scanf("%d", &h[i]);
    }
    int cnt = 0;
    for (int st = 0; st < n; st ++) {
    	a[0] = st;
    	if (check()) {
			cnt ++;
			if (cnt == 1) ans = st;
    	}
    }
    a[0] = ans;
    b[0] = g[0] ^ a[0];
    for (int i = 1; i < n; i ++) a[i] = h[i] ^ b[0];
    puts("!");
    printf("%d\n", cnt);
    for (int i = 0; i < n; i ++) printf("%d ", a[i]);
    fflush(stdout);

	return 0;
}