#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];
vector <int> g[sz];

void dfs(int u = 1, int p = 0, int f = 1)
{
    a[u] = f;
    for(int v : g[u]) if(v - p) dfs(v, u, f ^ 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();

    int mx = n-1, od = 0, ev = 0;
    for(int i=1; i<=n; i++) {
        int k = 0;
        for(int j : g[i]) {
            if(g[j].size() == 1) k++;
        }
        mx -= max(0, k-1);
        if(g[i].size() == 1) {
            if(a[i]) od = 1;
            else ev = 1;
        }
    }

    if(od - ev) printf("1 ");
    else printf("3 ");
    printf("%d\n", mx);
}