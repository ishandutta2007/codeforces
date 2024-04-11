#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 100005;

int n, sz[MaxN];
vector <int> g[MaxN];
long long s2[MaxN];
unsigned long long ans;

void dfsSize(int v, int p) {
    sz[v] = 1;
    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfsSize(to, v);
        sz[v] += sz[to];
    }
}

void dfsPre(int v, int p) {
    vector <int> ch;
    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        dfsPre(to, v);
        ch.push_back(sz[to]);
    }
    s2[v] = 1LL * (sz[v] - 1) * (sz[v] - 1);
    long long all = 0;
    for (int i = 0; i < (int)ch.size(); ++i) {
        s2[v] -= 1LL * ch[i] * ch[i];
        all += 1LL * ch[i] * ch[i];
    }
    s2[v] = s2[v] / 2 + (sz[v] - 1);
    all += 1LL * (n - sz[v]) * (n - sz[v]);
    for (int i = 0; i < (int)g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p) {
            continue;
        }
        long long allSq = 1LL * (n - sz[to] - 1) * (n - sz[to] - 1);
        ans += 1LL * (n - sz[to] - 1) * (n - sz[to]) / 2 * s2[to];
        ans += 1LL * (sz[to] - 1) * sz[to] / 2 * ((allSq - all + 1LL * sz[to] * sz[to]) / 2 + (n - sz[to] - 1));
    }
}
int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfsSize(1, 0);
    dfsPre(1, 0);
    cout << ans << '\n';
    return 0;
}