#include<bits/stdc++.h>
using namespace std;

#define N 1000010

int u[N], v[N], b[N], d[N];
char c[N];
bool vis[N];

void dfs(int x) {
    vis[x] = 1;
    if(c[x] == 'I') return;
    if(c[x] == 'A') {
        if(!vis[u[x]]) dfs(u[x]);
        if(!vis[v[x]]) dfs(v[x]);
        b[x] = b[u[x]] & b[v[x]];
    }
    if(c[x] == 'X') {
        if(!vis[u[x]]) dfs(u[x]);
        if(!vis[v[x]]) dfs(v[x]);
        b[x] = b[u[x]] ^ b[v[x]];
    }
    if(c[x] == 'O') {
        if(!vis[u[x]]) dfs(u[x]);
        if(!vis[v[x]]) dfs(v[x]);
        b[x] = b[u[x]] | b[v[x]];
    }
    if(c[x] == 'N') {
        if(!vis[u[x]]) dfs(u[x]);
        b[x] = !b[u[x]];
    }
}

void DFS(int x) {
    if(!d[x]) return;
    vis[x] = 1;
    if(c[x] == 'A') {
        if(!vis[u[x]]) DFS(u[x]);
        if(!vis[v[x]]) DFS(v[x]);
        b[x] = b[u[x]] & b[v[x]];
    }
    if(c[x] == 'X') {
        if(!vis[u[x]]) DFS(u[x]);
        if(!vis[v[x]]) DFS(v[x]);
        b[x] = b[u[x]] ^ b[v[x]];
    }
    if(c[x] == 'O') {
        if(!vis[u[x]]) DFS(u[x]);
        if(!vis[v[x]]) DFS(v[x]);
        b[x] = b[u[x]] | b[v[x]];
    }
    if(c[x] == 'N') {
        if(!vis[u[x]]) DFS(u[x]);
        b[x] = !b[u[x]];
    }
}

int main() {
    int n;
    char s[20];
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%s", s);
        if(s[0] != 'I' && s[0] != 'N') {
            c[i] = s[0];
            scanf("%d%d", &u[i], &v[i]);
        }
        if(s[0] == 'I') {
            c[i] = s[0];
            scanf("%d", &b[i]);
        }
        if(s[0] == 'N') {
            c[i] = s[0];
            scanf("%d", &u[i]);
        }
    }
    dfs(1);
    for(int i = 1; i <= n; i ++) if(c[i] != 'I') {
        if(c[i] == 'A') {
            b[u[i]] ^= 1;
            if((b[u[i]] & b[v[i]]) != b[i]) d[u[i]] = 1;
            b[u[i]] ^= 1;
            b[v[i]] ^= 1;
            if((b[u[i]] & b[v[i]]) != b[i]) d[v[i]] = 1;
            b[v[i]] ^= 1;
        }
        if(c[i] == 'X') {
            b[u[i]] ^= 1;
            if((b[u[i]] ^ b[v[i]]) != b[i]) d[u[i]] = 1;
            b[u[i]] ^= 1;
            b[v[i]] ^= 1;
            if((b[u[i]] ^ b[v[i]]) != b[i]) d[v[i]] = 1;
            b[v[i]] ^= 1;
        }
        if(c[i] == 'O') {
            b[u[i]] ^= 1;
            if((b[u[i]] | b[v[i]]) != b[i]) d[u[i]] = 1;
            b[u[i]] ^= 1;
            b[v[i]] ^= 1;
            if((b[u[i]] | b[v[i]]) != b[i]) d[v[i]] = 1;
            b[v[i]] ^= 1;
        }
        if(c[i] == 'N') d[u[i]] = 1;
    }
    memset(vis, 0, sizeof vis);
    d[1] = 1;
    DFS(1);
    for(int i = 1; i <= n; i ++)
        if(vis[i] && c[i] == 'I') putchar('0' + (!b[1]));
        else if(c[i] == 'I') putchar('0' + b[1]);
}