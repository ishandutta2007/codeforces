#include<bits/stdc++.h>
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 2e5 + 5;
int n, m, q, deg[N], cnt;

int main() {
    n = get(), m = get();
    for(int i = 1; i <= m; i++) {
        int u = get(), v = get();
        ++deg[u], ++deg[v], --deg[max(u, v)];
    }
    q = get();
    for(int i = 1; i <= n; i++) cnt += deg[i] == 0;
    for(int i = 1; i <= q; i++) {
        int op = get(), u, v;
        if(op == 3) { printf("%d\n", cnt); continue; }
        u = get(), v = get();
        if(!deg[u]) --cnt;
        if(!deg[v]) --cnt;
        if(op == 1) deg[u]++, deg[v]++, --deg[max(u, v)];
        if(op == 2) deg[u]--, deg[v]--, ++deg[max(u, v)];
        if(!deg[u]) ++cnt;
        if(!deg[v]) ++cnt;
    }
}