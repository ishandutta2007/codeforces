#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define NN 5050

VI adj[NN], vec[NN];
int fi[NN], se[NN], low[NN], vst[NN];
int id, st[NN], top, ins[NN], cnt;
int bel[NN], dst[NN], out[NN];
#define inf 0x3f3f3f3f

void dfs(int u) {
    low[u]=vst[u]=++id;
    st[++top]=u; ins[u]=1;
    for (int v : adj[u]) {
        if (!vst[v]) dfs(v), low[u]=min(low[u], low[v]);
        else if (ins[v]) low[u]=min(low[u], vst[v]);
    }
    if (low[u]==vst[u]) {
        ++cnt;
        while (true) {
            bel[st[top]]=cnt; ins[st[top]]=0;
            if (st[top--]==u) break;
        }
    }
}

int calc(int s, int k) {
    static int qf, qb, q[NN];
    for (int u : vec[k]) dst[u]=inf;
    qf=qb=0;
    q[qb++]=s; dst[s]=0;
    while (qf<qb) {
        int u=q[qf++];
        for (int v : adj[u]) {
            if (bel[v]!=k) continue;
            if (v==s) return dst[u]+1;
            if (dst[v]<inf) continue;
            dst[v]=dst[u]+1;
            q[qb++]=v;
        }
    }
}

int calc(int k) {
    int ans=vec[k].size();
    for (int u : vec[k]) ans=min(ans, calc(u, k));
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    int n, m;
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        scanf("%d%d", fi+i, se+i);
        adj[fi[i]].push_back(se[i]);
    }
    for (int i=1; i<=n; i++) if (!vst[i]) dfs(i);

    for (int i=0; i<m; i++) {
        int u=bel[fi[i]], v=bel[se[i]];
        if (u==v) continue;
        out[u]++;
    }

    for (int i=1; i<=n; i++) vec[bel[i]].push_back(i);

    int ans=n;
    for (int i=1; i<=cnt; i++) {
        if (out[i] || vec[i].size()<2) continue;
        ans+=calc(i)*998+1;
    }

    cout << ans << endl;

    return 0;
}