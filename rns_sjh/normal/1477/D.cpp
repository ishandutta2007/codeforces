#include<bits/stdc++.h>
using namespace std;

#define N 500010
#define pii pair<int, int>

int t, n, m, l[N], r[N], p[N], q[N], k, centre[N];
set<int> good, leaf[N];
set<int> nei[N];
set<pii> alv;
int use[N];

void assign() {
    for(int u : good) if(!use[u]) {
        set<int> x = good;
        set<int> y;
        for(int v : nei[u]) x.erase(v);
        x.erase(u);
        for(int v : x) if(!use[v]) y.insert(v);
        if(!y.empty()) {
            use[u] = 1;
            for(int v : y) use[v] = 2, leaf[u].insert(v), centre[v] = u;
        }
        else {
            int v = *x.begin();
            int w = centre[v];
            if(leaf[w].size() >= 2) {
                leaf[w].erase(v);
                leaf[u].insert(v);
                use[u] = 1;
                centre[v] = u;
            }
            else {
                leaf[w].clear();
                use[v] = 1, use[w] = use[u] = 2;
                leaf[v].insert(w), leaf[v].insert(u);
                centre[u] = centre[w] = v;
            }
        }
    }
    int l = 1;
    for(int u : good) if(use[u] == 1) {
        p[u] = l ++;
        for(int v : leaf[u]) p[v] = l ++, q[v] = p[v] - 1;
        q[u] = l - 1;
    }
}

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%d", &n, &m);
        k = n;
        good.clear();
        alv.clear();
        for(int i = 1; i <= n; i ++) nei[i].clear(), good.insert(i), use[i] = 0, leaf[i].clear(), centre[i] = 0;
        while(m --) {
            int u, v;
            scanf("%d%d", &u, &v);
            nei[u].insert(v);
            nei[v].insert(u);
        }
        for(int i = 1; i <= n; i ++) alv.emplace(nei[i].size(), i);
        while(k) {
            pii x = *alv.rbegin();
            if(x.first < k - 1) break;
            alv.erase(x);
            int u = x.second;
            p[u] = q[u] = k --;
            good.erase(u);
            for(int v : nei[u]) alv.erase(pii(nei[v].size(), v)), nei[v].erase(u), alv.emplace(nei[v].size(), v);
        }
        assign();
        for(int i = 1; i <= n; i ++) printf("%d%c", p[i], " \n"[i == n]);
        for(int i = 1; i <= n; i ++) printf("%d%c", q[i], " \n"[i == n]);
    }
}