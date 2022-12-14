#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 1111
#define inf 1000000009
int a[11111], b[11111], x[11111];
int q[N];
int t[N];
int pa[N];
int ans[N];
int con[N][N];
int find(int u) {
    if(pa[u] == u) return u;
    return pa[u] = find(pa[u]);
}
struct dat{
    int x,y, w;
    dat(int x = 0, int y = 0, int w = 0):x(x), y(y),w(w){}
}p[111111];
bool cmp(dat a, dat b) {
    if(a.w != b.w)return a.w < b.w;
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int main(){
    int T, n, m;
   // freopen("t.in","r",stdin);
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &q[i]);
        for(int i = 1; i <= n; i ++) pa[i] = i, ans[i] = 0, t[i] = 1;
        for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) con[i][j] = inf;
        int cnt = 0;
        scanf("%d", &m);
        for(int i = 0; i < m; i ++){
            scanf("%d%d%d", &a[i], &b[i], &x[i]);
            if(q[a[i]] > q[b[i]])con[a[i]][b[i]] = min(con[a[i]][b[i]], x[i]);
        }
        for(int i = 0; i < m; i ++){
            if(q[a[i]] > q[b[i]])p[cnt ++] = dat(a[i], b[i], con[a[i]][b[i]]);
        }
        sort(p, p + cnt, cmp);
        int ret = 0;
        int gas = 1;
        for(int i = 0; i < cnt; i ++) {
            dat A = p[i];
            int x = A.x, y = A.y;
            int xx = find(x);
            int yy = find(y);
            if(xx == yy) continue;
            if(yy != y)continue;
            pa[yy] = xx;
            ans[xx] += ans[yy] + A.w;
            t[xx] += t[yy];
            t[yy] = 0;
            ret = max(ret, ans[xx]);
            gas = max(gas, t[xx]);
        }
        if(gas == n)printf("%d\n", ret);
        else puts("-1");
}