#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 100010

vector <pii> adj[N];
int n, m, c[N], flag, cnt;
vector <int> v[2], nw;

bool dfs(int x) {
    nw.push_back(x);
    if(c[x] == 2) cnt ++;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i].first, z = flag ^ adj[x][i].second;
        if(c[y]) {if((c[y]-1)^(c[x]-1)^z) return 0;}
        else {
            c[y] = (z ^ (c[x]-1)) + 1;
            if(!dfs(y)) return 0;
        }
    }
    return 1;
}

int solve(int fl) {
    flag = fl;
    memset(c, 0, sizeof c);
    for(int i = 1; i <= n; i ++) if(!c[i]) {
        nw.clear(), cnt = 0;
        c[i] = 1;
        if(!dfs(i)) return N;
        if(2 * cnt > nw.size()) for(int j = 0; j < nw.size(); j ++) c[nw[j]] ^= 3;
    }
    for(int i = 1; i <= n; i ++) if(c[i] == 2) v[fl].push_back(i);
    return v[fl].size();
}

int main() {
    scanf("%d%d", &n, &m);
    while(m --) {
        int x, y;
        char s[3];
        scanf("%d%d%s", &x, &y, s);
        adj[x].push_back(pii(y, s[0] == 'R'));
        adj[y].push_back(pii(x, s[0] == 'R'));
    }
    int fi = solve(0), se = solve(1), x;
    if(fi == N && se == N) {
        puts("-1");
        return 0;
    }
    x = (fi > se);
    printf("%d\n", v[x].size());
    for(int i = 0; i < v[x].size(); i ++) printf("%d ", v[x][i]); puts("");
}