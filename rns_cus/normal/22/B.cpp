//B
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 30

int n, m, ans;
char s[N][N];
bool a[N][N][N][N];

int main(){
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i ++) gets(s[i]);
    for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++){
        for(int u = 0; u < n; u ++) for(int v = 0; v < m; v ++){
            if(s[u][v] == '1') continue;
            if(u == i and v == j) a[i][j][u][v] = 1;
            else if(u == i) a[i][j][u][v] = a[i][j][u][v-1];
            else if(v == j) a[i][j][u][v] = a[i][j][u-1][v];
            else a[i][j][u][v] = (a[i][j][u][v-1] and a[i][j][u-1][v]);
            if(a[i][j][u][v]) ans = max(4 + 2 * (u+v-i-j), ans);
        }
    }
    printf("%d", ans);
}