#include <algorithm>
#include <stdio.h>
#include <memory.h>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <string.h>
#include <string>
#include <ctype.h>

using namespace std;

typedef long long INT;
typedef pair<int, int> pii;

#define beyond(r, c) (r<0 || c<0 || r>=R || c>=C)
#define NN 510

int ii, n, m, adj[NN][NN], deg[NN], con[NN][NN], vst[NN], mL[NN], flag;

int Find(int u) {
    int i, v;
    for (i=0; i<deg[u]; i++) {
        v=adj[u][i];
        if (ii==v) continue;
        if (mL[v]==-1) return mL[v]=u, 1;
    }
    for (i=0; i<deg[u]; i++) {
        v=adj[u][i];
        if (ii==v) continue;
        if (vst[v]==flag) continue;
        vst[v]=flag;
        if (mL[v]==-1 || Find(mL[v])) return mL[v]=u, 1; 
    }
    return 0;
}

int main() {

    int i, u, v, res, tmp, j, k;
    
    scanf("%d%d", &n, &m);
    memset(deg, 0, sizeof(deg));
    memset(con, 0, sizeof(con));
    for (i=0; i<m; i++) {
        scanf("%d%d", &u, &v);
        u--; v--;
        adj[u][deg[u]++]=v;
        con[u][v]=1;
    }
    res=1000000000;
    for (i=0; i<n; i++) {
        tmp=0; ii=i;
        for (j=0; j<n; j++) {
            if (!con[i][j]) tmp++;
            if (j!=i && !con[j][i]) tmp++;
            mL[j]=-1;
        }
        for (k=j=0; j<n; j++) {
            if (j==i) continue;
            flag++;
            k+=Find(j);
        }
        res=min(res, tmp+n-1-k+(m-k-(2*n-1-tmp)));
    }
    printf("%d\n", res);

    return 0;
}