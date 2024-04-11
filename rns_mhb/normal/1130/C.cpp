#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> PII;

#define N 55

bool vis[N][N];
char s[N];

void bfs(int x, int y, vector <PII> &v) {
    vis[x][y] = 1;
    v.clear();
    v.push_back(PII(x, y));
    for(int i = 0; i < v.size(); i ++) {
        x = v[i].first, y = v[i].second;
        if(!vis[x-1][y]) vis[x-1][y] = 1, v.push_back(PII(x-1, y));
        if(!vis[x+1][y]) vis[x+1][y] = 1, v.push_back(PII(x+1, y));
        if(!vis[x][y-1]) vis[x][y-1] = 1, v.push_back(PII(x, y-1));
        if(!vis[x][y+1]) vis[x][y+1] = 1, v.push_back(PII(x, y+1));
    }
}

vector <PII> v, w;

int main() {
    int n, r1, c1, r2, c2;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) vis[0][i] = vis[i][0] = vis[i][n+1] = vis[n+1][i] = 1;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    for(int i = 1; i <= n; i ++) {
        scanf("%s", s + 1);
        for(int j = 1; j <= n; j ++) vis[i][j] = (s[j] == '1');
    }
    bfs(r1, c1, v);
    if(vis[r2][c2]) {
        puts("0");
        return 0;
    }
    bfs(r2, c2, w);
    int ans = 1e9;
    for(int i = 0; i < v.size(); i ++) for(int j = 0; j < w.size(); j ++) {
        int x = v[i].first, y = v[i].second, xx = w[j].first, yy = w[j].second;
        ans = min(ans, (x-xx)*(x-xx)+(y-yy)*(y-yy));
    }
    printf("%d\n", ans);
}