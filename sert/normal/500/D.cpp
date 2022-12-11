#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

ll n, m, v1, v2;
ll a[N], c[N], w[N], cs[N];
ld ans;
vector <ll> es[N];
pair <ll, ll> e[N];
ld zn, ch;

void dfs(ll v, ll pr) {
    a[v] = 1;
    for (int i = 0; i < es[v].size(); i++) {
        if (es[v][i] == pr)
            continue;
        dfs(es[v][i], v);
        a[v] += a[es[v][i]];
    }
}

ld cst(ll v) {
    return (n - 2) * (n - v) * v;
}

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;

    zn = (n - 2) * (n - 1) * n / 6;

    for (int i = 1; i < n; i++) {
        cin >> v1 >> v2 >> c[i - 1];
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
        e[i - 1] = make_pair(v1, v2);
    }

    dfs(0, 0);

    for (int i = 0; i < n - 1; i++) {
        w[i] = min(a[e[i].first], a[e[i].second]);
        ans += c[i] * cst(w[i]);
    }

    cout.precision(12);

    cin >> m;
    while  (m --> 0) {
        cin >> v1 >> v2;
        v1--;
        ans -= cst(w[v1]) * (c[v1] - v2);
        c[v1] = v2;
        ch = ans;
        cout << fixed << ch / zn << "\n";
    }

    //while(true);
}