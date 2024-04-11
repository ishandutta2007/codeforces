#include <bits/stdc++.h>
using namespace std;

#define M 1001

char s[M][M];
int con[M][M];
int p[M];
int vis[M];

int main() {
   ////freopen("b.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i]);
    for(int i = 1; i <= n; i ++) for(int j = 0; j < n; j ++) con[i][j + 1] = (s[i][j] - '0');
    for(int i = 1; i <= n; i ++) con[i][i] = 1;
    for(int k = 1; k <= n; k ++) for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) if(con[i][k] && con[k][j]) con[i][j] = 1;
    for(int i = 1; i <= n; i ++) {
        int mx = n + 1, id = -1;
        for(int j = 1; j <= n; j ++) if(!vis[j] && con[j][i]) {
            if(mx > p[j]) mx = p[j], id = j;
        }
        ///printf("mx = %d id = %d\n", mx, id);
        printf("%d ", mx);
        vis[id] = 1;
    }
}