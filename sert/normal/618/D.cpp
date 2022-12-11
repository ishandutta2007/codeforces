#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;

ll n, x, y;
ll v1, v2;
vector <ll> es[N];
ll d0[N], d1[N];

void dfs(ll v, ll pr) {
    ll w;
    vector <ll> dif;
    for (int i = 0; i < es[v].size(); i++) {
        w = es[v][i];
        if (w == pr) continue;
        dfs(w, v);
        d0[v] += d0[w];
        d1[v] += d0[w];
        dif.push_back(d1[w] - d0[w] + 1);
    }
    dif.push_back(0);
    dif.push_back(0);

    for (int i = 1; i < dif.size(); i++)
        if (dif[i - 1] > dif[i])
            swap(dif[i - 1], dif[i]);
    for (int i = 2; i < dif.size(); i++)
        if (dif[i - 2] > dif[i - 1])
            swap(dif[i - 2], dif[i - 1]);
    d0[v] += dif.back();
    d1[v] += dif.back();
    dif.pop_back();
    d0[v] += dif.back();
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d%I64d", &n, &x, &y);

    int q = 0;

    for (int i = 0; i < n - 1; i++) {
        scanf("%I64d%I64d", &v1, &v2);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++)
        if (es[i].size() + 1 == n)
            q = x - y;

    if (x > y) {
        cout << (n - 1) * y + q;
        return 0;
    }

    dfs(0, -1);

    cerr << d0[0] << "\n";

    cout << d0[0] * x + (n - 1 - d0[0]) * y;

    return 0;
}