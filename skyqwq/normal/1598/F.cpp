// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 20, S = 8e5 + 5, B = 4e5 + 1;

int n, mn[N], c[N][S], f[1 << N], ans, L[N][S], sum[N], cnt[S];

char g[N][S];

struct E{
    int x, v, t;
    bool operator < (const E &b) const { return x < b.x; }
};

vector<E> q[N];

int main() {
    read(n);
    for (int i = 0; i < n; i++) {
        scanf("%s", g[i] + 1);
        int v = 0, w = 0;
        int l = strlen(g[i] + 1);
        for (int j = 0; j < S; j++) L[i][j] = l + 1;
        for (int j = 1; j <= l; j++) {
            if (g[i][j] == '(') v++;
            else v--;
            chkMin(w, v);
            c[i][v + B]++;
            if (L[i][v + B] == l + 1) L[i][v + B] = j;
        }
        sum[i] = v;
        L[i][0] = l + 1;
        for (int j = 1; j < S; j++) 
            chkMin(L[i][j], L[i][j - 1]);
        mn[i] = w;
    }
    memset(f, 0xcf, sizeof f);
    f[0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        if (f[i] < 0) continue;
        chkMax(ans, f[i]);
        int t = 0;
        for (int j = 0; j < n; j++)
            if (i >> j & 1) t += sum[j];
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) continue;
            if (t + mn[j] >= 0) {
                int w = c[j][-t + B];
                chkMax(f[i | (1 << j)], f[i] + w);
            } else {
                int pos = L[j][-t - 1 + B] - 1;
                if (pos) q[j].pb((E) { pos, f[i], -t + B });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int v = 0;
        for (int j = 0; j < S; j++) cnt[j] = 0;
        int l = strlen(g[i] + 1);
        sort(q[i].begin(), q[i].end());
        for (int j = 1, k = 0; j <= l; j++) {
            if (g[i][j] == '(') v++;
            else v--;
            cnt[v + B]++;
            while (k < q[i].size() && q[i][k].x == j) {
                E u = q[i][k];
                chkMax(ans, u.v + cnt[u.t]);
                k++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}