#include<bits/stdc++.h>
using namespace std;

#define N 50

char s[N][N];
int n, f[N], sz[N];

int F(int x) {return x == f[x] ? x : f[x] = F(f[x]);}

int m, p[N], col[N];
bool con[N][N], chk[N];

int calc() {
    int r = 1e9;
    for(int i = 1; i <= m; i++) p[i] = i;
    while(clock() <= CLOCKS_PER_SEC * 4.5) {
        random_shuffle(p+1, p+m+1);
        int mx = 0;
        for(int i = 1; i <= m; i++) col[i] = 0;
        for(int i = 1; i <= m; i++) {
            int t = p[i];
            for(int j = 1; j <= m; j++) chk[j] = 0;
            for(int j = 1; j <= m; j++) if(con[t][j]) chk[col[j]] = 1;
            int j = 1;
            for(;; j++) if(!chk[j]) break;
            col[t] = j;
            mx = max(mx, j);
        }
        r = min(r, mx);
    }
    return r;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i]+1);
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 2; i <= n; i ++) for(int j = 1; j < i; j ++) if(s[i][j] == 'A') f[F(i)] = F(j);
    for(int i = 2; i <= n; i ++) for(int j = 1; j < i; j ++) if(s[i][j] == 'X' && F(i) == F(j)) return puts("-1"), 0;
    for(int i = 1; i <= n; i ++) sz[F(i)] ++;
    map <int, int> g;
    for(int i = 1; i <= n; i ++) if(sz[i] >= 2) g[i] = ++ m;
    for(int i = 2; i <= n; i ++) for(int j = 1; j < i; j ++) if(s[i][j] == 'X') {
        if(!g.count(F(i)) || !g.count(F(j))) continue;
        int x = g[F(i)], y = g[F(j)];
        con[x][y] = con[y][x] = 1;
    }
    printf("%d\n", n-1+calc());
}