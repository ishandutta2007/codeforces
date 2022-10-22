#include <bits/stdc++.h>
using namespace std;
const int N = 405;

int n , m , s , t;
struct arc {
    int x , f , next;
}e[N * N * 4];
int pre[N] , mcnt;
void addarc(int x ,int y ,int z) {
    e[mcnt] = (arc) {y , z , pre[x]} , pre[x] = mcnt ++;
    e[mcnt] = (arc) {x , 0 , pre[y]} , pre[y] = mcnt ++;
}
int d[N] , cur[N] , q[N];
bool BFS() {
    memset(d , -1 , sizeof(d));
    int top = 0 , bot = -1;
    q[++ bot] = s , d[s] = 1;
    while (top != bot + 1) {
        int x = q[top ++];
        for (int i = pre[x] ; ~i ;i = e[i].next) {
            int y = e[i].x;
            if (!~d[y] && e[i].f) {
                d[y] = d[x] + 1 , q[++ bot] = y;
                if (y == t) return 1;
            }
        }
    }
    return 0;
}
int DFS(int x , int flow = 1 << 30) {
    if (x == t || !flow) return flow;
    int sum = 0 , u;
    for (int& i = cur[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (d[y] == d[x] + 1 && (u = DFS(y , min(flow , e[i].f)))) {
            e[i].f -= u , e[i ^ 1].f += u;
            sum += u , flow -= u;
            if (!flow) break;
        }
    }
    if (!sum) d[x] = -1;
    return sum;
}
int dinic() {
    int ans = 0;
    while (BFS()) {
        memcpy(cur , pre , sizeof(cur));
        ans += DFS(s);
    }
    return ans;
}
int res[N][N];
int main() {
    int i , j , x , y;
    cin >> n >> m;
    s = n + n , t = s + 1;
    int suma = 0 , sumb = 0;
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &x);
        addarc(s , i , x);
        suma += x;
    }
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &x);
        addarc(i + n , t , x);
        sumb += x;
    }
    if (suma != sumb) {
        puts("NO");
        return 0;
    }

    for (i = 0 ; i < n ; ++ i)
        addarc(i , i + n , 1 << 30);
    for (i = 0 ; i < m ; ++ i) {
        cin >> x >> y;
        -- x , -- y;
        addarc(x , y + n , 1 << 30);
        addarc(y , x + n , 1 << 30);        
    }
    if (dinic() != suma)
        puts("NO");
    else {
        puts("YES");
        i = n << 2;
        for (j = 0 ; j < n ; ++ j) {
            res[j][j] = e[i ^ 1].f;
            i += 2;
        }
        for (j = 0 ; j < m ; ++ j) {
            res[e[i ^ 1].x][e[i].x - n] = e[i ^ 1].f;
            i += 2;
            res[e[i ^ 1].x][e[i].x - n] = e[i ^ 1].f;
            i += 2;            
        }
        for (i = 0 ; i < n ; ++ i)
            for (j = 0 ; j < n ; ++ j)
                printf("%d%c" , res[i][j] , " \n"[j + 1 == n]);
    }
        
    
    
    return 0;
}