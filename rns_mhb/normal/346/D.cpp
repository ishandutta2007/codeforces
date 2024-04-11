#include <stdio.h>
#include <memory.h>
#define N 1000100

int to[N], next[N], head[N];
int q[N*2], f[N], in[N];
bool bf[N];

int main() {
    int n, m, i, j, k, l, r, u, v, s, t;
//  freopen ("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (i=1; i<=m; i++) {
        scanf("%d %d", &k, &j);
        to[i]=k, next[i]=head[j], head[j]=i;
        in[k]++;
    }
    scanf("%d %d", &s, &t);
    memset(f, 63, sizeof(f));
    f[t]=0, q[n]=t;
    for (l=r=n; l<=r; l++) {
        u=q[l];
        if (bf[u]) continue;
        bf[u]=1;
        for (i=head[u]; i; i=next[i]) {
            v=to[i];
            if (!--in[v]) {
                if (f[v]>f[u]) f[v]=f[u], q[l--]=v;
            } else if (f[v]>f[u]+1) f[v]=f[u]+1, q[++r]=v;
        }
    }
    if (f[s]<1e9) printf("%d\n", f[s]);
    else puts("-1");
}