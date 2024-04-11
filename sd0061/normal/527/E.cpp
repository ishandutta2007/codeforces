#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , pre[N] , mcnt;
int deg[N];
struct edge {
    int x , next;
}e[N << 4];
vector<int> res;
bool f[N << 4];

void dfs(int x) {
    for (int& i = pre[x] ; ~i ;) {
        if (f[i >> 1]) {
            i = e[i].next;
        } else {
            f[i >> 1] = 1;
            int tmp = i;
            int y = e[i].x;
            i = e[i].next;
            dfs(y);
            res.push_back(tmp);
        }
    }
}


void work () {
    int i , x , y;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;        
        ++ deg[x] , ++ deg[y];
    }
    x = -1;
    for (i = 1 ; i <= n ; ++ i) {
        if (deg[i] & 1) {
            if (!~x) {
                x = i;
            } else {
                y = i , ++ m;
                e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
                e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;        
                ++ deg[x] , ++ deg[y];
                x = -1;
            }
        }
    }
    if (m & 1) {
        x = y = 1 , ++ m;
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;        
        ++ deg[x] , ++ deg[y];
    }
    printf("%d\n" , m);
    dfs(1);
    for (i = 0 ; i < m ; ++ i) {
        x = res[i] ^ (i & 1);
        printf("%d %d\n" , e[x].x , e[x ^ 1].x);
    }
}

int main () {
    work();
    return 0;
}