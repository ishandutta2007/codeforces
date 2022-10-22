#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 3005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N * N];
int s[4] , t[2];
int d[N][N];

void BFS(int x , int *dis) {
    queue<int> Q;
    Q.push(x) , dis[x] = 0;
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (!~dis[y]) {
                dis[y] = dis[x] + 1;
                Q.push(y);
            }
        }
    }
}

void work() {
    int i , j , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
    }
    memset(d , -1 , sizeof(d));
    scanf("%d%d%d" , s , s + 1 , t);
    scanf("%d%d%d" , s + 2 , s + 3 , t + 1);
    for (i = 1 ; i <= n ; ++ i)
        BFS(i , d[i]);
    if (d[s[0]][s[1]] > t[0] || d[s[2]][s[3]] > t[1]) {
        puts("-1");
        return;
    }
    int res = d[s[0]][s[1]] + d[s[2]][s[3]] , L1 , L2;
    for (x = 1 ; x <= n ; ++ x)
        for (y = 1 ; y <= n ; ++ y) {
            L1 = d[s[0]][x] + d[x][y] + d[y][s[1]];
            L2 = d[s[2]][x] + d[x][y] + d[y][s[3]];
            if (L1 <= t[0] && L2 <= t[1])
                res = min(res , d[s[0]][x] + d[y][s[1]] + d[s[2]][x] + d[x][y] + d[y][s[3]]);
            L1 = d[s[0]][x] + d[x][y] + d[y][s[1]];
            L2 = d[s[2]][y] + d[x][y] + d[x][s[3]];
            if (L1 <= t[0] && L2 <= t[1])
                res = min(res , d[s[0]][x] + d[y][s[1]] + d[s[2]][y] + d[x][y] + d[x][s[3]]);            
        }
    cout << m - res << endl;
}

int main() {
    work();
    return 0;
}