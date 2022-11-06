#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

vector <int> g[sz];
int d[sz];
int lca, cnt=0;

void dfs(int u, int f = 1)
{
    cnt++;
    d[u]=f;
    for(int v : g[u]) if(!d[v]) dfs(v,f+1);
}

void go(int u, int p = -1)
{
    for(int v : g[u]) {
        if(v==p) continue;
        if(v==lca) {
            bool fnd=0;
            for(int i=0; i+1<g[lca].size(); i++) {
                if(g[lca][i]==u) fnd=1;
                if(fnd) g[lca][i]=g[lca][i+1];
            }
            g[lca].pop_back();
            g[u].clear();
            return;
        }
        go(v, u);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    lca=1;
    while(1) {
        memset(d, 0, sizeof d);
        cnt=0;
        dfs(lca);

        if(cnt==1) {
            cout << "! " << lca << endl;
            exit(0);
        }

        int who, smol=-1;
        for(int i=1; i<=n; i++) {
            if(d[i]>smol) {
                smol=d[i];
                who=i;
            }
        }

        memset(d, 0, sizeof d);
        dfs(who);

        int who2, smol2=-1;
        for(int i=1; i<=n; i++) {
            if(d[i]>smol2) {
                smol2=d[i];
                who2=i;
            }
        }

        cout << "? " << who << " " << who2 << endl;
        cin >> lca;

        if(who!=lca) go(who);
        if(who2!=lca) go(who2);
    }
}