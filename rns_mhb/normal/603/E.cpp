#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 100010
#define M 300010

int p[N], s[N], top, odd;
pii st[M];

void link(int x, int y) {
    while(x != p[x]) x = p[x];
    while(y != p[y]) y = p[y];
    if(x == y) return;
    if(s[x] > s[y]) swap(x, y);
    st[++ top] = pii(x, y);
    if((s[x]&1) && (s[y]&1)) odd -= 2;
    p[x] = y;
    s[y] += s[x];
}

void go(int k) {
    while(top > k) {
        pii z = st[top --];
        int x = z.first, y = z.second;
        p[x] = x;
        s[y] -= s[x];
        if((s[x]&1) && (s[y]&1)) odd += 2;
    }
}

int n, m, x[M], y[M], z[M], c[M], rnk[M];

void solve(int l, int r, int L, int R) {
    if(L > R) return;
    if(l == r) {
        for(int i = L; i <= R; i ++) printf("%d\n", z[c[r]]);
        return;
    }
    int mid = l + r >> 1, k = top, T = R + 1;
    for(int i = l; i <= mid; i ++) if(c[i] < L) link(x[c[i]], y[c[i]]);
    for(int i = L; i <= R; i ++) if(rnk[i] <= mid) {
        link(x[i], y[i]);
        if(odd == 0) {
            T = i;
            break;
        }
    }
    go(k);
    for(int i = l; i <= mid; i ++) if(c[i] < L) link(x[c[i]], y[c[i]]);
    solve(mid+1, r, L, T-1);
    go(k);
    for(int i = L; i < T; i ++) if(rnk[i] < l) link(x[i], y[i]);
    solve(l, mid, T, R);
}

bool cmp(int i, int j) {
    return z[i] < z[j];
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) p[i] = i, s[i] = 1;
    odd = n;
    for(int i = 1; i <= m; i ++) scanf("%d%d%d", x + i, y + i, z + i);
    for(int i = 1; i <= m; i ++) c[i] = i;
    sort(c + 1, c + m + 1, cmp);
    for(int i = 1; i <= m; i ++) rnk[c[i]] = i;
    z[m+1] = -1, c[m+1] = rnk[m+1] = m + 1;
    solve(1, m+1, 1, m);
}