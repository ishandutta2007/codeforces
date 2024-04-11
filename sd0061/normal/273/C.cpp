#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
int deg[N] , f[N] , tmp[N];
bool g[N];
void work() {
    int i , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;        
        ++ deg[x] , ++ deg[y];
    }
    queue<int> Q;
    for (i = 1 ; i <= n ; ++ i)
        if (deg[i] > 1)
            Q.push(i) , g[i] = 1;
    while (!Q.empty()) {
        x = Q.front() , Q.pop() , g[x] = 0;
        if (deg[x] <= 1)
            continue;
        f[x] ^= 1 , deg[x] = -deg[x];
        for (i = pre[x] ; ~i ; i = e[i].next) {
            int y = e[i].x;
            ++ deg[x];
            if (f[x] != f[y]) {
                -- deg[y];
            } else {
                ++ deg[y];
                if (deg[y] > 1)
                    Q.push(y) , g[y] = 1;
            }
        }
    }
    for (i = 1 ; i <= n ; ++ i)
        printf("%d" , f[i]);
}

int main() {
    work();
    return 0;
}