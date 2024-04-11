#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , w , next;
}e[N << 1];
set< pair<int , int> > R;
int d[N] , cnt;
int f[N] , p[N];

int dfs(int x) {
    if (~f[x]) return f[x];
    f[x] = 1 << 30;
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (d[y] == d[x] + 1) {
            int w = dfs(y) + (e[i].w ? -1 : 1);
            if (w < f[x]) {
                f[x] = w;
                p[x] = y;
            }
        }
    }
    return f[x];
}

void work() {
    int i , x , y , z;
    scanf("%d%d",&n,&m);
    memset(pre , -1 , sizeof(pre));
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&x,&y,&z);
        cnt += z;
        e[mcnt] = (edge) {y , z , pre[x]} , pre[x] = mcnt ++;
        e[mcnt] = (edge) {x , z , pre[y]} , pre[y] = mcnt ++;
    }
    queue<int> Q;
    memset(d , -1 , sizeof(d));
    d[1] = 0 , Q.push(1);
    while (!Q.empty()) {
        x = Q.front() , Q.pop();
        for (i = pre[x] ; ~i ; i = e[i].next) {
            y = e[i].x;
            if (!~d[y]) {
                d[y] = d[x] + 1;
                Q.push(y);
            }
        }
    }
    memset(f , -1 , sizeof(f));
    f[n] = cnt;
    printf("%d\n" , dfs(1));
    x = 1;
    while (x != n) {
        y = p[x];
        R.insert(make_pair(x , y));
        R.insert(make_pair(y , x));
        x = y;
    }
    for (i = 0 ; i < mcnt ; i += 2) {
        x = e[i ^ 1].x , y = e[i].x , z = e[i].w;
        if (z == 1 && !R.count(make_pair(x , y)))
            printf("%d %d %d\n" , x , y , !z);
        if (z == 0 && R.count(make_pair(x , y)))
            printf("%d %d %d\n" , x , y , !z);
    }
}

int main()
{
    work();
    return 0;
}