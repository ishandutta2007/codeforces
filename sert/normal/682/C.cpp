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
const ll INF = 1e12;

int n, p, c, a[N], ans;
bool u[N];
vector <pair <int, int> > es[N];

void go(int v, ll c) {
    if (a[v] < c || u[v])
        return;
    u[v] = true;
    ans++;
    for (auto q: es[v]) {
        go(q.first, max(c, 0ll) + q.second);
    }
}

int main() {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &p, &c);
        p--;
        es[i].push_back({p, c});
        es[p].push_back({i, c});
    }

    go(0, 0);

    printf("%d\n", n - ans);

    return 0;
}