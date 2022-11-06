#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=4e5+5, inf=1e9;

vector <int> g[sz], road;
int dis[sz], cnt[sz];

void bfs(int f)
{
    queue <int> q;
    q.push(f);
    for(int i=0; i<sz; i++) dis[i]=inf;
    dis[f]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int v : g[u]) {
            if(dis[v]!=inf) {
                if(dis[v]==dis[u]+1) cnt[v]++;
                continue;
            }
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d", &u, &v);
        g[v].push_back(u);
    }

    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
        int x;
        scanf("%d", &x);
        road.push_back(x);
    }

    int d=road.back();
    bfs(d);

    int mn=0, mx=0;
    for(int i=1; i<k; i++) {
        int u=road[i-1], v=road[i];
        if(dis[u]!=dis[v]+1) mn++, mx++;
        else if(cnt[u]) mx++;
    }

    printf("%d %d\n", mn, mx);
}