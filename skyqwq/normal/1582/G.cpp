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

const int N = 1e6 + 5;

int n, a[N], p0[N];
 
void inline prework() {
    int n = 1e6;
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i)
            if (!p0[j]) p0[j] = i;
    }
}

vector<PII> e[N];

char g[N];

int s[N], top, sum[N];

vector<PII> q[N];
vector<PII> G;

void inline work(vector<PII> &t) {
    int m = t.size();
    if (!m) return;
    G.clear(); G.pb(mp(0, 0));
    for (int i = 0; i < m; i++) G.pb(t[i]); 
    for (int i = 1; i <= m; i++) {
        sum[i] = G[i].fi + sum[i - 1];
    }
    top = 0;
    for (int i = m; i >= 0; i--) {
        while (top && sum[s[top]] >= sum[i]) top--;
        if (s[top]) {
            q[G[i].se + 1].pb(mp(G[s[top]].se, 1));
            if (i != m) q[G[i + 1].se + 1].pb(mp(G[s[top]].se, -1));
        }
        s[++top] = i;
    }
}

multiset<int> S;

int main() {
    prework();
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]); 
    scanf("%s", g + 1);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int w = g[i] == '*' ? 1 : -1;
        while (x > 1) {
            int v = p0[x], c = 0;
            while (x % v == 0) x /= v, c++;
            e[v].pb(mp(w * c, i));
        }
    }
    LL ans = 0;
    for (int i = 1; i <= 1000000; i++) work(e[i]);
    for (int i = 1; i <= n; i++) {
        for (PII u: q[i]) {
            if (u.se == 1) S.insert(u.fi);
            else S.erase(S.find(u.fi));
        }
        int lim = n;
        if (S.size()) lim = *S.begin() - 1;
        if (i <= lim) ans += lim - i + 1;
    }
    printf("%lld\n", ans);
    return 0;
}