#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
#define mk make_pair
#define pii pair<int, int>

using namespace std;

const int N = 5e5 + 7;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

int n, m, k, tot, d[N], head[N], ans[N];
LL cnt;
struct node {
    int u, v, nx;
} edge[N];

void add(int u, int v) {
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].nx = head[u];
    head[u] = tot++;
}

vector<int> vec[N];

void bfs() {
    queue<int> que;
    d[1] = 0;
    que.push(1);

    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int i = head[u]; ~i; i = edge[i].nx) {
            int v = edge[i].v;
            if(d[v] != -1) continue;
            d[v] = d[u] + 1;
            que.push(v);
        }
    }
}

void dfs(int pos) {
    if(cnt <= 0) return;
    if(pos == n + 1) {
        cnt--;
        for(int i = 1; i <= m; i++)
            printf("%d", ans[i]);
        puts("");
        return;
    }
    for(int i = 0; i < vec[pos].size(); i++) {
        ans[vec[pos][i]] = 1;
        dfs(pos + 1);
        ans[vec[pos][i]] = 0;
    }
}
int main(){
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }

    memset(d, -1, sizeof(d));

    bfs();
    for(int i = 0; i < tot; i++) {
        int u = edge[i].u, v = edge[i].v;
        if(d[u] + 1 == d[v]) {
            vec[v].push_back(i / 2 + 1);
        }
    }


    cnt = 1;
    for(int i = 2; i <= n; i++) {
        cnt *= (int) vec[i].size();
        if(cnt >= k) break;
    }

    cnt = min(cnt, 1ll * k);
    printf("%d\n", cnt);
    dfs(2);
    return 0;
}

/*
*/