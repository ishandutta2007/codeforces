#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const int INF = (ll)1e9 + 34;
const ll md = (ll)1e9 + 7;

int c[N], d[N];
vector <pair<int, int> > es[N];
ll clen, slen;

ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2) return (a * step(a, st - 1)) % md;
    ll q = step(a, st / 2);
    return (q * q) % md;
}

void dfs(int v, int cd, int lst) {
    if (c[v] == 1) {
        clen = cd - d[v];
    }
    if (c[v]) return;
    c[v] = 1;
    d[v] = cd;

    for (auto w: es[v])
        if (w.second != lst)
            dfs(w.first, cd + 1, w.second);

    c[v] = 2;
}

int main() {
    init();
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x); x--;
        es[i].push_back({x, i});
        es[x].push_back({i, i});
    }

    ll ans = 1;

    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            clen = 0;
            dfs(i, 0, -1);
            slen += clen;
            ans = (ans * (step(2, clen) + md - 2)) % md;
        }
    }

    ans = (ans * step(2, n - slen)) % md;
    cout << ans;

    return 0;
}