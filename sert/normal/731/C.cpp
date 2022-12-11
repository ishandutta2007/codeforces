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
const int N = 1e6 + 34;
bool u[N];
vector <int> cl;
int kk[N];
int ans;
int mx;
int v1, v2, n, m, k;
int c[N];
int sz;
vector <int> es[N];

void go(int v) {
    if (u[v]) return;
    u[v] = true;
    sz++;
    if (!kk[c[v]]) {
        cl.push_back(c[v]);
    }
    kk[c[v]]++;
    for (int w: es[v])
        go(w);
}

int main() {
    init();

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", c + i);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++) {
        if (u[i]) continue;
        sz = 0;
        go(i);
        mx = 0;
        for (int col: cl) {
            mx = max(mx, kk[col]);
            kk[col] = 0;
        }
        cl.clear();
        ans += sz - mx;
    }

    printf("%d\n", ans);

    return 0;
}