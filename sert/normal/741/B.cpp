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
const int N = 63e5 + 34;
const ll INF = 2e9 + 34;
int MD = 30;

int p[N], sb[N], b[N], w[N], W, sw[N];
int a[1111][1111];
int ng[N], num = 0;

vector <int> gr[N];

int fnd(int v) {
    return (v == p[v] ? v : p[v] = fnd(p[v]));
}

void uniq(int v1, int v2) {
    v1 = fnd(v1);
    v2 = fnd(v2);
    if (v1 == v2) return;
    p[v1] = v2;
    sb[v2] += sb[v1];
    sw[v2] += sw[v1];
}

int main() {
    init();
    int n, m;
    scanf("%d%d%d", &n, &m, &W);
    for (int i = 0; i < n; i++) scanf("%d", w + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        sb[i] = b[i];
        sw[i] = w[i];
    }
    int v1, v2;
    while (m--) {
        scanf("%d%d", &v1, &v2);
        uniq(v1 - 1, v2 - 1);
    }

    vector <pair<int, int> > v;
    for (int i = 0; i < n; i++) {
        if (p[i] == i) {
            ng[i] = num++;
            v.push_back({sw[i], sb[i]});
        }
    }

    for (int i = 0; i < n; i++)
        gr[ng[fnd(i)]].push_back(i);

    for (int iq = 0; iq < (int)v.size(); iq++) {
        for (int i = 0; i <= W; i++) a[iq + 1][i] = a[iq][i];
        auto q = v[iq];
        cerr << q.first << " " << q.second << "\n";
        for (int i = W - q.first; i >= 0; i--) {
            a[iq + 1][i + q.first] = max(a[iq + 1][i + q.first], a[iq][i] + q.second);
        }
        for (auto d: gr[iq]) {
            for (int i = W - w[d]; i >= 0; i--)
                a[iq + 1][i + w[d]] = max(a[iq + 1][i + w[d]], a[iq][i] + b[d]);
        }
    }
    int ans = -1;
    for (int i = 0; i <= W; i++)
        ans = max(ans, a[v.size()][i]);
    printf("%d\n", ans);

    return 0;
}