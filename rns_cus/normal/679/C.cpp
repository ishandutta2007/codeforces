#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define N 505

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, cn, col[N];
char c[N][N];

int cl[N * N];
int g[N][N];
int cnt[N * N];
int chk[N * N];


void dfs(int x, int y, int C){
    ++cl[C];
    g[x][y] = C;
    rep(i, 4){
        int xx = x + dx[i], yy = y + dy[i];
        if(xx >= 0 && xx < n && yy >= 0 && yy < n && !g[xx][yy] && c[xx][yy] == '.') dfs(xx, yy, C);
    }
}


int sum, T;

void check_color(int t){
    if(!t || chk[t] == T) return;
   // printf("check %d %d %d\n", t, cl[t], cnt[t]);
    chk[t] = T;
    sum += cl[t] - cnt[t];
}


int main(){
    int i, j;
    scanf("%d %d", &n, &m);
    rep(i, n) scanf("%s", c[i]);
    int C = 0;
    rep(i, n) rep(j, n) if(c[i][j] == '.' && !g[i][j]){
        dfs(i, j, ++C);
    }

    //rep(i, n) rep(j, n) printf("%d%c", g[i][j], " \n"[j == n - 1]);

    int ans = 0;
    T = 0;

    rep(i, n - m + 1) rep(j, n - m + 1){
        sum = m * m;
        if(!j){
            memset(cnt, 0, sizeof cnt);
            rep(p, m) rep(q, m) cnt[g[i + p][j + q]]++;
        }else{
            rep(p, m) cnt[g[i + p][j - 1]]--, cnt[g[i + p][j + m - 1]]++;
        }
        ++T;
        if(i) rep(p, m) check_color(g[i - 1][j + p]);
        if(i + m < n) rep(p, m) check_color(g[i + m][j + p]);
        if(j) rep(p, m) check_color(g[i + p][j - 1]);
        if(j + m < n) rep(p, m) check_color(g[i + p][j + m]);
        ans = max(ans, sum);
        //printf("%d\n", sum);
    }
    printf("%d\n", ans);


}