#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = (ll)1e18 + 41;
const ll MD = 998244353;

ll step(ll st) {
    if (st == 0) return 1;
    if (st % 2) return step(st - 1) * 2 % MD;
    ll q = step(st / 2);
    return q * q % MD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    //cout << n << " " << m << endl;

    vector<int> a(n), u(n, -1), pos(n);
    vector<int> nx(n, -1), pr(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        pos[a[i]] = i;
        if (i > 0) pr[i] = i - 1;
        if (i + 1 < n) nx[i] = i + 1;
    }

    int deg = 0;
    vector<int> b;
    for (int i = 0; i < m; i++) {
        int x; cin >> x; x--;
        u[pos[x]] = i + 1;
        b.push_back(x);
    }

    for (int it = 0; it < m; it++) {
        int x = b[it];

        int p = pos[x];
        auto isBad = [&](int x) { return x == -1 || u[x] != -1; };
        if (isBad(pr[p]) && isBad(nx[p])) { cout << "0\n"; return; }
        if (!isBad(pr[p]) && !isBad(nx[p])) deg++;

        if (pr[p] != -1) nx[pr[p]] = nx[p];
        if (nx[p] != -1) pr[nx[p]] = pr[p];
    }

    cout << step(deg) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 1;
#endif
    cin >> t;
    while (t--) solve();
}