// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5e5 + 5;

int n, m, p[N];

vector<int> a[N];
 
multiset<int> B[N], R[N];

char ans[N];

bool pr[N], sf[N];

void inline clear() {
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i <= m; i++) B[i].clear(), R[i].clear();
}

bool inline cmp(int x, int y) {
    return a[x][1] < a[y][1];
}

void rev(int i) {
    for (int j = 1; j <= m; j++) {
        R[j].erase(R[j].find(a[i][j]));
        B[j].insert(a[i][j]);
    }
}

int inline chk() {
    for (int i = 1; i <= m; i++) sf[i] = pr[i] = 0;
    int mx = -2e9, mn = 2e9;
    for (int i = 1; i <= m; i++) {
        chkMin(mn, *R[i].begin());
        chkMax(mx, *--B[i].end());
        if (mx < mn) pr[i] = 1;
    }
    mx = -2e9, mn = 2e9;
    for (int i = m; i; i--) {
        chkMin(mn, *B[i].begin());
        chkMax(mx, *--R[i].end());
        if (mx < mn) sf[i] = 1;
    }
    for (int i = 1; i < m; i++)
        if (pr[i] && sf[i + 1]) return i;
    return 0;
}

void inline work() {
    for (int i = 1; i <= n; i++) p[i] = i, ans[i] = 'R';
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i < n; i++) {
        int u = p[i];
        rev(u); ans[u] = 'B';
        int res = chk();
        if (res) {
            puts("YES");
            for (int j = 1; j <= n; j++) putchar(ans[j]);
            printf(" %d\n", res);
            return;
        }
    }
    puts("NO");
}

int main() {
    int T; read(T);
    while (T--) {
        read(n), read(m);
        for (int i = 1; i <= n; i++) {
            a[i].pb(0);
            for (int j = 1, x; j <= m; j++) {
                read(x), a[i].pb(x);
                R[j].insert(x);
            }
        }
        work();
        clear();
    }
    return 0;
}