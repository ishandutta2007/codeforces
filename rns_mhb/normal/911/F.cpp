#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 200010

vector <int> adj[N];

int d[N], f[N];
bool col[N];

void dfs(int x, int p) {
    d[x] = d[p] + 1;
    f[x] = p;
    for(auto y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
    }
}

long long ans;
vector <pii> op;
int X, L, ed;

void DFS(int x, int p) {
    d[x] = d[p] + 1;
    for(auto y : adj[x]) {
        if(y == p) continue;
        if(col[y]) continue;
        DFS(y, x);
    }
    if(x != X) {
        ans += L + d[p];
        op.push_back(pii(x, ed));
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    int A = 0;
    for(int i = 1; i <= n; i ++) if(d[i] > d[A]) A = i;
    dfs(A, 0);
    int B = 0;
    for(int i = 1; i <= n; i ++) if(d[i] > d[B]) B = i;
    vector <int> diam;
    for(int x = B; x != A; x = f[x]) diam.push_back(x);
    diam.push_back(A);
    reverse(diam.begin(), diam.end());
    for(auto x : diam) col[x] = 1;
    for(int i = 0; i < diam.size(); i ++) {
        if(i > diam.size()-1-i) L = i, ed = A;
        else L = diam.size()-1-i, ed = B;
        X = diam[i];
        DFS(diam[i], 0);
    }
    for(int i = diam.size()-1; i > 0; i --) {
        ans += i;
        op.push_back(pii(diam[i], A));
    }
    printf("%I64d\n", ans);
    for(auto p : op) printf("%d %d %d\n", p.first, p.second, p.first);
}