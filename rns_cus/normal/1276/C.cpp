#include <bits/stdc++.h>
using namespace std;

#define N 400100

int n, a[N], b[N], x[N], g[N], t[N], m;
vector <int> v;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), x[i] = a[i];
    sort(x + 1, x + n + 1);
    m = unique(x + 1, x + n + 1) - x - 1;
    for (int i = 1; i <= n; i ++) b[i] = lower_bound(x + 1, x + m + 1, a[i]) - x;
    for (int i = 1; i <= n; i ++) {
        int u = b[i];
        if (!t[u]) v.push_back(u);
        t[u] ++, g[u] ++;
    }
    int rlt = 0, mx = -1, cnt = 0;
    for (int k = 1; k <= n; k ++) {
        int sz = v.size();
        cnt += sz;
        vector <int> w;
        for (int i = 0; i < sz; i ++) {
            g[v[i]] --;
            if (g[v[i]]) w.push_back(v[i]);
        }
        v = w;
        int l = cnt / k;
        if (l >= k) {
            int p = k * l;
            if (p > rlt) rlt = p, mx = k;
        }
        else break;
    }
    vector <int> ans; v.clear();
    for (int i = 1; i <= m; i ++) if (t[i]) v.push_back(i), g[i] = t[i];
    for (int k = 1; k <= mx; k ++) {
        int sz = v.size(); vector <int> w;
        for (int i = 0; i < sz; i ++) {
            ans.push_back(v[i]);
            g[v[i]] --;
            if (g[v[i]]) w.push_back(v[i]);
        }
        v = w;
    }
    int ht = mx, le = (int)ans.size() / ht;
    ans.resize(ht * le);
    printf("%d\n", ht * le);
    printf("%d %d\n", ht, le);
    for (int i = 1; i <= m; i ++) g[i] = 0, t[i] = i;
    for (int i = 0; i < (int)ans.size(); i ++) g[ans[i]] ++;
    sort(t + 1, t + m + 1, [&](int i, int j) {return g[i] > g[j];});
    for (int i = 1, r = 0, c = 0; i <= m; i ++) {
        int u = t[i];
        while (g[u] --) {
            ans[r*le+c] = u;
            if (r + 1 < ht) r ++;
            else r = 0, c ++;
        }
    }
    for (int i = 0; i < ht; i ++) {
        for (int j = 0; j < le; j ++) printf("%d%c", x[ans[le*i+(j-i+le)%le]], " \n"[j==le-1]);
    }

    return 0;
}