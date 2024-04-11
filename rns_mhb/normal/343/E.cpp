#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
#define flow(src, dst) (f[src][dst]-f[dst][src])
#define residue(src, dst) (c[src][dst]-flow(src,dst))
#define min(a,b)(a<b?a:b)
#define inf 1000000000
#define N 1111

int n, c[N][N], pa[N], pre[N], w[N], f[N][N];

void gomory_hu() {
    memset (pa, 0, sizeof(pa));
    memset (w, 0, sizeof(w));
    for (int s=1; s<n; s++) {
        int t=pa[s], total=0;
        memset (f, 0, sizeof(f));
        while (1) {
            queue<int> q; q.push(s);
            memset (pre, -1, sizeof(pre));
            pre[s]=-2;
            while (!q.empty() && pre[t]==-1) {
                int u=q.front(); q.pop();
                for (int v=0; v<n; v++) if (pre[v]==-1 && residue(u,v)>0) pre[v]=u, q.push(v);
            }
            if (pre[t]==-1) break;
            int inc = inf;
            for (int v=t, u=pre[v]; u>=0; v=u, u=pre[v]) inc=min(inc, residue(u,v));
            for (int v=t, u=pre[v]; u>=0; v=u, u=pre[v]) f[u][v]+=inc;
            total+=inc;
        }
        w[s]=total;
        for (int i=0; i<n; i++) if (i!=s && pre[i] != -1 && pa[i]==t) pa[i]=s;
        if (pre[pa[t]]!=-1) pa[s]=pa[t], pa[t]=s, w[s]=w[t], w[t]=total;
    }
}

struct star {
    int x, y;
    star (int x, int y):x(x), y(y){}
    star(){}
};

struct cmp{
    bool operator () (star a, star b) {
        return a.y < b.y;
    }
};

int deg[N], con[N][N];

int main() {
//  freopen ("e.in", "r", stdin);
    int m, i, j, k;
    scanf ("%d %d", &n, &m);
    memset (c, 0, sizeof(c));
    while (m--) {
        scanf ("%d %d %d", &i, &j, &k); i--; j--;
        c[i][j]=k; c[j][i]=k;
    } gomory_hu();

    priority_queue<star, vector<star> , cmp> q;

    int ans = 0;
    for (i=1; i<n; i++) ans+=w[i];
    printf ("%d\n", ans);
    printf ("1");

    memset (deg, 0, sizeof(deg));
    for (i=1; i<n; i++) con[pa[i]][deg[pa[i]]++]=i;

    for (i=0; i<deg[0]; i++) q.push(star(con[0][i], w[con[0][i]]));

    while (!q.empty()) {
        star u=q.top(); q.pop();
        printf (" %d", u.x+1);
        for (i=0; i<deg[u.x]; i++) {
            j=con[u.x][i];
            q.push(star(j,w[j]));
        }
    }
}