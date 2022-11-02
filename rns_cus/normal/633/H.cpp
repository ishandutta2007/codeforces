#include <bits/stdc++.h>
using namespace std;
#define M 30030


int F[M];
int n;
int mod;
int a[M], id[M];
int nxt[M];
bool cmp(int i, int j) {
    return a[i] < a[j];
}

int m;

int calc(int l, int r) {
    int s = 0, m = 0;
    for (int j, i = 1; i <= n; i++) {
        j = id[i];
        if (j >= l && j <= r) {
            s = (s + F[++m] * a[j]) % mod;
            i = nxt[i];
        }
    }
    return s;
}

int main() {
    scanf("%d %d", &n, &mod);
    F[1] = F[2] = 1 % mod;
    for (int i = 3; i <= n; i++) {
        F[i] = (F[i-1] + F[i-2]) % mod;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    nxt[n] = n;
    for (int j = n - 1; j >= 1; j--) {
        if (a[id[j]] == a[id[j+1]]) {
            nxt[j] = nxt[j+1];
        } else {
            nxt[j] = j;
        }
    }
    for (int j = 1; j <= n; j++) {
        a[j] %= mod;
    }
    scanf("%d", &m);
	for (int l, r, i = 1; i <= m; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", calc(l, r));
    }
    return 0;
}