#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 2005;
int n , m;
char g[N][N];
int cnt[2] , deg[N][N];
bool f[N][N];

int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1};
char L[] = "^<v>" , R[] = "v>^<";
bool in(int x , int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}


void work() {
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , g[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            if (g[i][j] != '*') {
                ++ cnt[(i + j) & 1];
                ++ deg[i - 1][j];
                ++ deg[i + 1][j];
                ++ deg[i][j - 1];
                ++ deg[i][j + 1];                                    
            }
        }
    if (cnt[0] != cnt[1]) {
        puts("Not unique");
        return;
    }
    stack< pair<int , int> > S;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j) {
            if (g[i][j] != '*' && deg[i][j] == 1)
                S.push(make_pair(i , j));
        }
    while (!S.empty()) {
        int x = S.top().first , y = S.top().second;S.pop();
        //printf("%d %d\n" , x , y);
        if (f[x][y]) continue;
        -- cnt[0];
        for (i = 0 ; i < 4 ; ++ i) {
            int X = x + dx[i] , Y = y + dy[i];
            if (!in(X , Y) || f[X][Y] || g[X][Y] == '*')
                continue;
            break;
        }
        if (i >= 4) {
            puts("Not unique");
            return;
        }
        f[x][y] = 1;
        g[x][y] = L[i] , g[x + dx[i]][y + dy[i]] = R[i];
        x = x + dx[i] , y = y + dy[i];
        f[x][y] = 1;
        for (i = 0 ; i < 4 ; ++ i) {
            int X = x + dx[i] , Y = y + dy[i];
            if (!in(X , Y) || f[X][Y] || g[X][Y] == '*')
                continue;
            if (-- deg[X][Y] == 1)
                S.push(make_pair(X , Y));
        }
    }
    if (cnt[0])
        puts("Not unique");
    else {
        for (i = 1 ; i <= n ; ++ i)
            puts(g[i] + 1);
    }
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}