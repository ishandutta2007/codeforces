#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
int n , m , s , t , L , pre[N] , mcnt;
struct edge {
    int x , w , next;
} e[N * 20];
int X[N * 10] , Y[N * 10] , W[N * 10];

LL d[N][N];
int p[N][N] , flag , cost;
int w[N][N];

void gao(int x , int y) {
    if (x == s && y == 0){
        return;
    }
    int q = p[x][y];
    gao(q / n , q % n);
    int z = q / n;
    if (w[x][z] < 0) {
        if (!flag) {
            w[x][z] = w[z][x] = cost;
            flag = 1;
        } else {
            w[x][z] = w[z][x] = 1;
        }
    }
}

int main() {
    scanf("%d%d%d%d%d" , &n , &m , &L , &s , &t);
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
        X[i] = x , Y[i] = y , W[i] = z;
        if (z == 0) {
            w[x][y] = w[y][x] = -1;
        }
    }

    memset(d , 0x3f , sizeof(d));
    memset(p , -1 , sizeof(p));
    priority_queue< pair<LL , int> > Q;
    d[s][0] = 0 , Q.push({-d[s][0] , s * n + 0});

    while (!Q.empty()) {
        int z = Q.top().second;
        int x = z / n , j = z % n;
        LL w = -Q.top().first; Q.pop();
        if (w > d[x][j]) continue;
        for (int i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            if (e[i].w) {
                if (d[y][j] > d[x][j] + e[i].w) {
                    d[y][j] = d[x][j] + e[i].w;
                    Q.push({-d[y][j] , y * n + j});
                    p[y][j] = z;
                }
            } else {
                if (j + 1 < n) {
                    if (d[y][j + 1] > d[x][j]) {
                        d[y][j + 1] = d[x][j];
                        p[y][j + 1] = z;
                        Q.push({-d[y][j + 1] , y * n + j + 1});
                    }
                }
            }
        }
    }

    if (d[t][0] < L) {
        puts("NO");
        return 0;
    }
    if (d[t][0] == L) {
        puts("YES");
        for (int i = 0 ; i < m ; ++ i) {
            printf("%d %d %d\n" , X[i] , Y[i] , W[i] ? W[i] : L + 1);
        }
        return 0;
    }
    flag = 0;
    for (int k = 1 ; k < n ; ++ k) {
        if (d[t][k] >= d[n][0]) {
            continue;
        }
        if (d[t][k] + k <= L) {
            cost = L - d[t][k] - k + 1;
            gao(t , k);
            break;
        }
    }
    if (flag) {
        puts("YES");
        for (int i = 0 ; i < m ; ++ i) {
            int ww = W[i];
            if (w[X[i]][Y[i]] == -1) {
                ww = L + 1;
            } else if (w[X[i]][Y[i]]) {
                ww = w[X[i]][Y[i]];
            }
            printf("%d %d %d\n" , X[i] , Y[i] , ww);
        }
    } else {
        puts("NO");
    }
}