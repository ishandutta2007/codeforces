// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 505, M = N;

int n, m, w[N], p[N];

bool vis[M];

int inline ask() {
    printf("? ");
    for (int i = 1; i <= m; i++)
        putchar(vis[i] ? '1' : '0');
    puts("");
    fflush(stdout);
    int x; read(x);
    return x;
}

bool inline cmp(int x, int y) {
    return w[x] < w[y];
}

int main() {
    read(n), read(m);
    for (int i = 1; i <= m; i++) {
        vis[i] = 1;
        w[i] = ask();
        vis[i] = 0;
        p[i] = i;
    }
    sort(p + 1, p + 1 + m, cmp);
    LL now = 0;
    for (int i = 1; i <= m; i++) {
        int u = p[i];
        vis[u] = 1;
        LL t = ask();
        if (now + w[u] == t) {
            now += w[u];
        } else {
            vis[u] = 0;
        }
    }
    printf("! %lld\n", now);
    fflush(stdout);
    return 0;
}