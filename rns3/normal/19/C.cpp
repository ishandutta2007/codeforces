//19_C
#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 100011
#define inf 1000000000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef pair <int, int> pii;
pii p[N];

int n, m;
int a[N], b[N], c[N];
int cnt[N];
int pos[N][11], rpos[N];
int f[N][11][11];

int calc(int x, int i, int j){
    if(f[x][i][j]) return f[x][i][j];

    int ii = pos[x][i], jj = pos[x][j];
    if(jj == n - 1) return f[x][i][j] = 1;
    if(a[ii + 1] != a[jj + 1]) return f[x][i][j] = 1;
    return f[x][i][j] = calc(a[ii + 1], rpos[ii + 1], rpos[jj + 1]) + 1;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]), b[i] = c[i] = a[i];
    sort(b, b + n);
    int m = unique(b, b + n) - b;
    for(int i = 0; i < n; i ++) a[i] = lower_bound(b, b + m, a[i]) - b;

    for(int i = 0; i < n; i ++) {
        pos[a[i]][cnt[a[i]] ++] = i;
        rpos[i] = cnt[a[i]] - 1;
    }

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < cnt[i]; j ++){
            int jj = pos[i][j];
            int rlt = inf;
            for(int k = j + 1; k < cnt[i]; k ++){
                int kk = pos[i][k];
                int r = calc(i, j, k);
                if(r >= kk - jj) rlt = min(rlt, kk - jj);
            }
            p[jj] = pii(rlt, jj);
        }
    }

    sort(p, p + n);

    int st = 0;
    for(int i = 0; i < n; i ++){
        int j = p[i].first, k = p[i].second;
        if(k < st) continue;
        if(j == inf) continue;
        st = k + j;
    }

    printf("%d\n", n - st);
    for(int i = st; i < n; i ++) printf("%d ", c[i]); puts("");
}