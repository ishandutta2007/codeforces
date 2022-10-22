#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];

int dep[N] , f[17][N] , Lev , s[N];

void dfs(int x , int fa) {
    dep[x] = dep[fa] + 1;
    f[0][x] = fa , s[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x; 
        if (y != fa) {
            dfs(y , x);
            s[x] += s[y];
        }
    }
}
int LCA(int x , int y) {
    if (dep[x] > dep[y]) swap(x , y);
    for (int i = Lev ; i >= 0 ; -- i)
        if (dep[y] - dep[x] >> i & 1)
            y = f[i][y];
    if (x == y) return y;
    for (int i = Lev ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y])
            x = f[i][x] , y = f[i][y];
    return f[0][x];
}
int get(int x , int k) {
    for (int i = 0 ; i <= Lev ; ++ i)
        if (k >> i & 1)
            x = f[i][x];
    return x;
}

void work() {
    int i , j , x , y , z;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d",&x,&y);
        e[mcnt] = (edge) {y , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;        
    }
    dfs(1 , 0);
    for (j = 1 ; 1 << j < n ; ++ j)
        for (i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    Lev = j - 1;
    scanf("%d",&m);
    while (m --) {
        scanf("%d%d",&x,&y);
        if (x == y) {
            printf("%d\n" , n);
        } else {
            if (dep[x] < dep[y])
                swap(x , y);            
            z = LCA(x , y);
            int dis = dep[x] + dep[y] - dep[z] - dep[z];
            if (dis & 1) {
                printf("%d\n" , 0);
            } else {
                dis >>= 1;
                z = get(x , dis);
                //printf("*%d\n" , z);
                if (dep[x] == dep[y]) {
                    x = get(x , dis - 1);
                    y = get(y , dis - 1);
                    printf("%d\n" , n - s[x] - s[y]);
                } else {
                    x = get(x , dis - 1);
                    printf("%d\n" , s[z] - s[x]);                
                }
            }
        }
    }
}

int main() {
    work();
    return 0;
}