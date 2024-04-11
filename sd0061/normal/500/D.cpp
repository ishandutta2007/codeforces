#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N << 1];
LL f[N];
int s[N];
void dfs(int x , int fa) {
    s[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (y != fa) {
            dfs(y , x);
            f[i >> 1] += (LL) s[y] * (s[y] - 1) * (n - s[y]);
            f[i >> 1] += (LL) s[y] * (n - s[y] - 1) * (n - s[y]);
            s[x] += s[y];
        }
    }
}

int main() {
    int i , x , y , z;
    scanf("%d",&n);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i < n ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    dfs(1 , 0);
    double res = 0 ;
    LL sum = (LL) n * (n - 1) * (n - 2) / 6;
    for (i = 0 ; i + 1 < n ; ++ i)
        res += f[i] * e[i << 1].w;
    scanf("%d",&m);
    while (m --) {
        scanf("%d%d",&x,&y);
        -- x;
        y -= e[x << 1].w;
        e[x << 1].w += y;
        e[x << 1 | 1].w += y;
        res += y * f[x];
        printf("%.10f\n" , res / sum);
    }
    return 0;
}