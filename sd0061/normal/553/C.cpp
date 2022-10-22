#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n , m , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N << 1];
bool vis[N];
int val[N];

bool dfs(int x , int fa) {
    vis[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            if (!vis[y]) {
                val[y] = !(val[x] ^ e[i].w);
                if (!dfs(y , x))
                    return 0;
            } else {
                if (!(val[x] ^ val[y]) != e[i].w)
                    return 0;
            }
        }
    }
    return 1;
}

void work() {
    scanf("%d%d" , &n , &m);
    memset(pre , -1 , sizeof(pre));
    for (int i = 0 ; i < m ; ++ i) {
        int x , y , z;
        scanf("%d%d%d" , &x , &y , &z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    int cnt = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) {
            ++ cnt;
            val[i] = 1;
            if (!dfs(i , 0)) {
                puts("0");
                return;
            }
        }
    }
    int res = 1;
    -- cnt;
    while (cnt --) {        
        res <<= 1;
        res %= Q;
    }
    cout << res << endl;
}

int main() {
    work();    
    return 0;
}