#include<bits/stdc++.h>
using namespace std;

#define N 200010

vector <int> adj[N], v;
int n, a[N], b[N];
bool vis[N];

bool cmp(int i, int j) {
    return b[i] < b[j];
}

int main() {
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[a[i]] = i;
    for(int i = 1; i <= n; i ++) sort(adj[i].begin(), adj[i].end(), cmp);
    vis[1] = 1;
    v.push_back(1);
    for(int i = 0; i < v.size(); i ++) {
        int x = v[i];
        for(int j = 0; j < adj[x].size(); j ++) {
            int y = adj[x][j];
            if(!vis[y]) v.push_back(y), vis[y] = 1;
        }
    }
    bool flag = 1;
    for(int i = 1; i <= n; i ++) if(a[i] != v[i-1]) {flag = 0; break;}
    if(flag) puts("Yes");
    else puts("No");
}