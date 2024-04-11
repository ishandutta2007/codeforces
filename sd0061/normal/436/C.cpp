#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 1005
int n , m , K , W;
char s[N][12][12];
struct edge {
    int x , y , w;
    bool operator < (const edge& R) const {
        return w < R.w;
    }
}e[N * N * 2];
int pre[N] , mcnt , ans;
struct edge2 {
    int x , next;
}E[N << 1];
int f[N] , M;
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}
void dfs(int x , int fa) {
    if (x)
        printf("%d %d\n" , x , fa);
    for (int i = pre[x] ; ~i ; i = E[i].next)
        if (E[i].x != fa)
            dfs(E[i].x , x);
}

void work()
{
    int i , j , k , l , x , y;
    scanf("%d%d%d%d",&n,&m,&K,&W);
    for (i = 1 ; i <= K ; ++ i) {
        for (j = 0 ; j < n ; ++ j)
            scanf("%s" , s[i][j]);
    }
    for (i = 1 ; i <= K ; ++ i) {
        for (j = i + 1 ; j <= K ; ++ j) {
            x = 0;
            for (k = 0 ; k < n; ++ k)
                for (l = 0 ; l < m ; ++ l)
                    x += s[i][k][l] != s[j][k][l];
            e[M ++] = (edge) {i , j , x * W};
        }
        e[M ++] = (edge) {0 , i , n * m};
    }
    sort(e , e + M);
    memset(pre , -1 , sizeof(pre));
    for (i = 0 ; i <= K ; ++ i) f[i] = i;
    for (i = 0 ; i < M ; ++ i) {
        x = getf(e[i].x) , y = getf(e[i].y);
        if (x != y) {
            E[mcnt] = (edge2) {e[i].y , pre[e[i].x]} , pre[e[i].x] = mcnt ++;
            E[mcnt] = (edge2) {e[i].x , pre[e[i].y]} , pre[e[i].y] = mcnt ++;
            f[x] = y , ans += e[i].w;
        }
    }
    printf("%d\n" , ans);
    dfs(0 , -1);
}

int main()
{
   // freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}