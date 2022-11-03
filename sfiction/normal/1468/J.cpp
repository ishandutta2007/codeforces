#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int N, M, K;

int fa[200010];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
struct edge {
    int u, v, w;
    friend bool operator < (edge e1, edge e2) {
        return e1.w < e2.w;
    }
};
bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    fa[u] = v;
    return true;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&M,&K);
        vector<edge>e1, e2;
        for (int i=1;i<=M;i++) {
            edge tmp;
            scanf("%d%d%d",&tmp.u,&tmp.v,&tmp.w);
            if (tmp.w < K) {
                tmp.w = K - tmp.w;
                e1.push_back(tmp);
            } else {
                tmp.w = tmp.w - K;
                e2.push_back(tmp);
            }
        }
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        for (int i=1;i<=N;i++) fa[i] = i;
        int com = N;
        for (auto t:e1) {
            com -= merge(t.u, t.v);
        }
        LL ans = 1e18;
        if (com == 1) {
            ans = e1[0].w;
        }
        if (e2.size() > 0) {
            LL tmp = 0;
            for (auto t:e2) {
                if (merge(t.u, t.v)) tmp += t.w;
            }
            tmp = max(tmp, LL(e2[0].w));
            ans = min(ans, tmp);
        }
        printf("%lld\n",ans);
    }
}