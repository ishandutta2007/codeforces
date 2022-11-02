#include <bits/stdc++.h>
using namespace std;

#define N 1000005

typedef long long ll;
int n, k;
int fwk[N];
int a[N], b[N];
int vis[N];

void mark(int x) {
    for (int i = x; i <= n; i += i & -i) {
        fwk[i] ++;
    }
}

int sum(int x) {
    if (!x) return 0;
    int rtn = 0;
    for (int i = x; i; i -= i & -i) rtn += fwk[i];
    return rtn;
}

int ta(int x) {
    x %= n;
    if (!x) x = n;
    return x;
}

int query(int x, int y) {
    x += n, y += n;
    x = ta(x), y = ta(y);
    int rtn;
    if (x <= y) {
        rtn = (sum(y) - sum(x-1));
    }
    else rtn = (sum(n) - sum(x-1)) + (sum(y) - sum(0));
    return rtn;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1, j = 1; j <= n; j ++) {
        if (k <= n / 2) {
            b[j] = query(i, i + k - 1) + query(i - k + 1, i);
        }
        else {
            b[j] = query(i, i + n - k - 1) + query(i - n + k + 1, i);
        }
        b[j] ++;
        mark(i);
        i += k; i %= n;
        if (!i) i = n;
    }
    ll now = 1;
    for (int i = 1; i <= n; i ++) {
        now += b[i];
        printf("%I64d ", now);
    }
}