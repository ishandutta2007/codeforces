#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll N = 1e5 + 34;

ll n, m, v1, v2, t;
vector <ll> es[N], num[N];
vector <bool> pq[N];
bool u[N], b[N];
ll p[N], ans[N], len, w;

void dfs(ll v, ll pr) {
    p[v] = pr;
    for (int i = 0; i < es[v].size(); i++) {
        w = es[v][i];
        if (w == pr)
            continue;
        if (pq[v][i])
            b[w] = true;
        dfs(w, v);
    }
    if (b[v] && !u[v]) {
        ans[len++] = v + 1;
        while (v != -34) {
            if (u[v])
                break;
            u[v] = true;
            v = p[v];
        }
    }
}

int main() {
    ///freopen("a.in", "r", stdin);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        scanf("%I64d%I64d%I64d", &v1, &v2, &t);
        v1--;
        v2--;
        es[v1].push_back(v2);
        es[v2].push_back(v1);
        pq[v1].push_back(t - 1);
        pq[v2].push_back(t - 1);
    }

    dfs(0, -34);

    printf("%d\n", len);
    for (int i = 0; i < len; i++)
        printf("%d ", ans[i]);

    return 0;
}