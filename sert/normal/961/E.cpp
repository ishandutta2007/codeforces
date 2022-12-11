#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)3e5 + 34;

int t[N * 8];
void add(int v, int l, int r, int p, int x) {
    if (l + 1 == r) {
        t[v] += x;
        return;
    }
    int m = (l + r) / 2;
    if (p < m) add(v * 2 + 1, l, m, p, x);
    else add(v * 2 + 2, m, r, p, x);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}
int getSum(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l + r) / 2;
    return getSum(v * 2 + 1, l, m, L, R) + getSum(v * 2 + 2, m, r, L, R);
}

void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    vector<vector<pair<int, int>>> es(N);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= N) a[i] = N - 1;
        if (a[i] > i) {
            es[i].emplace_back(1, i);
            es[a[i]].emplace_back(-1, i);
        }
    }

    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        for (auto p: es[i]) {
            ans += p.first * getSum(0, 0, N, p.second, N);
        }
        add(0, 0, N, a[i], 1);
    }
    cout << ans << "\n";
}

int main() {
    init();
	solve();
	//solve();
	//solve();
    return 0;
}