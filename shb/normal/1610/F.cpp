#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    //vector<vector<pii>>e(2 * n + 1);
    vector<set<pii>>e(2 * n + 1);
    vector<int> c1(n), c2(n);
    vector<int> U(m), V(m), W(m);
    int cnt = 1;
    auto addedge = [&](int u, int v) {
        //e[u].emplace_back(v, cnt);
        //e[v].emplace_back(u, -cnt);
        e[u].emplace(v, cnt);
        e[v].emplace(u, -cnt);
        //printf("add edge %d %d %d\n",u,v,cnt);
        cnt++;
    };
    int S = 2 * n;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        --u;--v;
        U[i] = u;
        V[i] = v;
        W[i] = w;
        if (w == 1) {
            addedge(u, v);
            c1[u] ^= 1;
            c1[v] ^= 1;
        } else {
            addedge(u + n, v + n);
            c2[u] ^= 1;
            c2[v] ^= 1;
        }
    } 
    for (int i = 0; i < n; i++) {
        if (c1[i] && !c2[i]) addedge(S, i);
        if (c2[i] && !c1[i]) addedge(S, i + n);
        if (c1[i] && c2[i]) addedge(i, i + n);
    }
    vector<int> fucked(cnt + 1);
    vector<int> ans(cnt + 1);
    function<void(int)> dfs;
    dfs = [&](int x) {
        while(!e[x].empty()) {
            auto t = (*e[x].begin());
            int IDX = abs(t.second);
            e[x].erase(t);
            if (fucked[IDX]) {
                continue;
            }
            fucked[IDX] = true;
            if (t.second < 0) {
                ans[IDX - 1] = 2;
            } else {
                ans[IDX - 1] = 1;
            }
            dfs(t.first);
        }
    };
    vector<int> ind(n), outd(n);
    for (int i = 0; i <= S; i++) {
        dfs(i);
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == 1) {
            outd[U[i]] += W[i];
            ind[V[i]] += W[i];
        } else {
            ind[U[i]] += W[i];
            outd[V[i]] += W[i];
        }
    }
    int ANS = 0;
    for (int i = 0; i < n; i++) {
        //printf("%d : %d %d\n",i,ind[i],outd[i]);
        ANS += (abs(ind[i] - outd[i]) == 1);
    }
    printf("%d\n",ANS);
    for (int i = 0; i < m; i++) {
        printf("%d",ans[i]);
    }
    puts("");
}