#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, K, a[N], b[N];

map <int, int> mp;

int tot, s;

map <int, int> lst[N];

int nxt[N][20];

void solve(int l, int r, int rem = 0) {
    if (l + K > r) {
        int sum = 0;
        for (int i = l; i <= r; i ++) sum += b[i%n] - s, b[i%n] = s;
        b[l%n] += rem, b[r%n] += sum - rem;
        printf("%d", (l - 1) % n);
        for (int i = l; i < l + K; i ++) printf(" %d", b[i%n]);
        puts(""); return;
    }
    int sum = 0;
    for (int i = l; i < l + K; i ++) sum += b[i%n] - s;
    if (sum >= rem) {
        solve(l, l + K - 1, rem);
        solve(l + K - 1, r, 0);
    }
    else {
        sum -= b[(l+K-1)%n] - s;
        solve(l + K - 1, r, rem - sum);
        solve(l, l + K - 1, rem);
    }
}

typedef pair <int, int> pii;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[n+i] = a[i], s += a[i];
    for (int i = 1; i <= n; i ++) b[i%n] = a[i];
    s /= n;
    for (int i = 1; i <= 2 * n; i ++) a[i] = a[i] - s + a[i-1];
    for (int i = 2 * n; i; i --) {
        int &k = mp[a[i]];
        if (!k) k = ++tot;
        nxt[i][0] = lst[k][(i+1)%(K-1)];
        for (int j = 0; nxt[i][j]; j ++) nxt[i][j+1] = nxt[nxt[i][j]][j];
        lst[k][i%(K-1)] = i;
    }
    pii ans = pii(1e9, 0); int r = n % (K - 1);
    for (int i = 1; i <= n; i ++) {
        int k = 0, u = i;
        for (int j = 19; ~j; j --) {
            int v = nxt[u][j];
            if (v && v <= n + i) u = v, k ^= 1 << j;
        }
        int qr = k % (K - 1);
        if (qr >= r) k -= qr - r;
        else k -= qr - r + K - 1;
        ans = min(ans, pii((n - k) / (K - 1), i));
    }
    if (ans.first >= (n - 3 + K) / (K - 1)) printf("%d\n", (n - 3 + K) / (K - 1)), solve(1, n);
    else {
        printf("%d\n", ans.first);
        int u = ans.second, k = n - (K - 1) * ans.first;
        while (-- k) {
            if (u + 1 < nxt[u][0]) solve(u + 1, nxt[u][0]);
            u = nxt[u][0]; assert(u > 0);
        }
        if (u + 1 < n + ans.second) solve(u + 1, n + ans.second);
    }

    return 0;
}