#include <bits/stdc++.h>
using namespace std;

const int M =  2501;

char s[M], t[M];
int f[M][M], g[M][M];
int from[M], to[M], par[M], ans[M];
pair<int, int> res[M];

int main() {
    //freopen("c.in", "r", stdin);
    scanf("%s %s", s + 1, t + 1);
    int n = strlen(s + 1);
    int m = strlen(t + 1);
    for(int i = m; i ; i --) {
        for(int j = n; j; j --) {
            if(t[i] == s[j]) f[i][j]= f[i+1][j+1] + 1;
            else f[i][j] = 0;
        }
    }
    for(int i = m; i; i --){
        for(int j = 1; j <= n; j ++) {
            if(s[j] == t[i]) g[i][j] = g[i+1][j-1] + 1;
            else g[i][j] = 0;
        }
    }
    ans[0] = 0;
    for(int i  =1; i <= m; i ++) ans[i] = 1e9;
    for(int i = 0; i < m; i ++) {
        for(int j = 1; j <= n; j ++) {
            int x = f[i+1][j];
            if(x) {
                if(ans[i+x] > ans[i] + 1) {
                    ans[i+x] = ans[i] + 1;
                    par[i+x] = i;
                    from[i+x] = j;
                    to[i+x] = j + x - 1;
                }
            }
        }
        for(int j = 1; j <= n; j ++){
            int x = g[i+1][j];
            if(x) {
                if(ans[i+x] > ans[i] + 1) {
                    ans[i+x] = ans[i] + 1;
                    par[i+x] = i;
                    from[i+x] = j;
                    to[i+x] = j - x + 1;
                }
            }
        }
    }
    if(ans[m] > m) return puts("-1");
    int x = m;
    int cnt = 0;
    while(x) {
        res[cnt ++] = make_pair(from[x], to[x]);
        x = par[x];
    }
    printf("%d\n", cnt);
    for(int i = cnt - 1; i >= 0;  i --) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
}