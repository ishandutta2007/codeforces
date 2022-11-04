#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 2e5 + 1, X[4] = {-1, 1, -1, 1}, Y[4] = {-1, -1, 1, 1};

int t, n, m, *dp[N], *last[N];
char *s[N];

struct node{
    int d, x, y;
    node(int d, int x, int y) : d(d), x(x), y(y){}
    bool operator<(const node &b) const{
        return d > b.d;
    }
};

priority_queue<node> q;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++){
            if(s[i])
                delete[] s[i];
            if(dp[i])
                delete[] dp[i];
            if(last[i])
                delete[] last[i];
            dp[i] = new int[m + 1];
            dp[i][0] = 0;
            q.push(node(0, i, 0));
            memset(dp[i] + 1, 0x3f, sizeof(int) * m);
            s[i] = new char[m + 2];
            last[i] = new int[m + 1];
            scanf("%s", s[i] + 1);
        }
        while(!q.empty()){
            int x = q.top().x;
            int y = q.top().y;
            if(q.top().d > dp[x][y]){
                q.pop();
                continue;
            }
            q.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = x + X[dir];
                int ny = y + Y[dir];
                if(nx < 1 || ny < 1 || nx > n || ny > m)
                    continue;
                if(nx > 1 && s[nx - 1][ny] == '#' || nx < n && s[nx + 1][ny] == '#' || ny > 1 && s[nx][ny - 1] == '#' || ny < m && s[nx][ny + 1] == '#')
                    continue;
                if(dp[nx][ny] > dp[x][y] + (s[nx][ny] == '.')){
                    dp[nx][ny] = dp[x][y] + (s[nx][ny] == '.');
                    last[nx][ny] = dir;
                    q.push(node(dp[nx][ny], nx, ny));
                }
            }
        }
        int p = 1;
        for (int i = 2; i <= n; i++)
            if(dp[i][m] < dp[p][m])
                p = i;
        if(dp[p][m] == 0x3f3f3f3f){
            puts("NO");
            continue;
        }
        puts("YES");
        int x = p, y = m;
        while(y){
            s[x][y] = '#';
            int d = last[x][y];
            x -= X[d];
            y -= Y[d];
        }
        for (int i = 1; i <= n; i++)
            printf("%s\n", s[i] + 1);
    }
    return 0;
}