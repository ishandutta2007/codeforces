#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int cnt[303030][30];
int st[303030];
bool visit[303030];
bool cycle[303030];
char ch[303030];

struct edge{
    int s, e;
    bool operator<(const edge &r)const{
        return s < r.s;
    }
} adj[303030];

bool dfs(int k){
    cycle[k] = true;
    visit[k] = true;

    if (st[k] == -1) {
        cnt[k][ch[k]-'a']++;
        cycle[k] = false;
        return false;
    }
    for (int i=st[k]; k==adj[i].s; i++){
        if (cycle[adj[i].e]) return true;
        if (!visit[adj[i].e]) if (dfs(adj[i].e)) return true;
        for (int j=0; j<=26; j++) cnt[k][j] = max(cnt[adj[i].e][j], cnt[k][j]);
    }
    cnt[k][ch[k]-'a']++;
    cycle[k] = false;
    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    scanf("%s", ch+1);
    memset(st, -1, sizeof st);
    for (int i=0; i<M; i++) scanf("%d %d", &adj[i].s, &adj[i].e);
    sort(adj, adj+M);
    st[adj[0].s] = 0;
    for (int i=1; i<M; i++) if (adj[i].s != adj[i-1].s) st[adj[i].s] = i;

    for (int i=1; i<=N; i++){
        if (!visit[i]){
            if (dfs(i)){
                puts("-1");
                return 0;
            }
        }
    }
    for (int i=1; i<=N; i++) for (int j=0; j<=26; j++) ans = max(cnt[i][j], ans);
    printf("%d", ans);
    return 0;
}