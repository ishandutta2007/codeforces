#include<bits/stdc++.h>
using namespace std;

#define N 400010

char s[N];
int nxt[N], prv[N], tot;
vector <int> adj[N];
bool ans[N];

int calc(int l, int r) {
    if(l == r) return 1;
    if(nxt[l+1] == r-1) {
        adj[l].push_back(l+1);
        return calc(l+1, r-1);
    }
    if(s[nxt[l+1]+1] == 'P') {
        int ret = 0;
        for(int i = l+1; i<=r; i = nxt[i]+2) {
            ret += calc(i, nxt[i]);
            adj[l].push_back(i);
        }
        return ret;
    }
    else {
        int ret = 1e9, who;
        for(int i = l+1; i <= r; i = nxt[i]+2) {
            int cur = calc(i, nxt[i]);
            if(ret > cur) ret = cur, who = i;
        }
        adj[l].push_back(who);
        return ret;
    }
}

void dfs(int x) {
    if(s[x] == '*') ans[x] = 1;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        dfs(y);
    }
}

char p[1000010];

void solve() {
    int r;
    scanf("%d", &r);
    gets(p);
    int n = 0;
    for(int i = 0; p[i]; i ++) if(p[i] != ' ') s[++ n] = p[i];
    s[0] = '(', s[n+1] = ')', s[n+2] = 0;
    vector <int> a;
    for(int i = 0; i <= n+1; i ++) {
        if(s[i] == '*') nxt[i] = i, prv[i] = i;
        if(s[i] == '(') a.push_back(i);
        if(s[i] == ')') nxt[a.back()] = i, prv[i] = a.back(), a.pop_back();
    }
    for(int i = 0; i <= n+1; i ++) ans[i] = 0, adj[i].clear();
    int x = calc(0, n+1);
    dfs(0);
    printf("REVOLTING");
    for(int i = 0; i <= n+1; i ++) if(s[i] == '*') {
        if(ans[i]) printf(" %I64d", 1ll * r * x);
        else printf(" 0");
    }
    puts("");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}