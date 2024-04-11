#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 111
#define M 100100

LL n, ans;
LL f[M][N];
bool can[M][N];
int m, a[N], vis[N];

LL doit(LL x, int st) {
    if(x < M && can[x][st]) {
        return f[x][st];
    }
    LL rt = x;
    for(int i = st; i <= m; i ++)  {
        rt -= doit(x / a[i], i + 1);
    }
    if(x < M) {
        can[x][st] = 1;
        f[x][st] = rt;
    }
    return rt;
}

LL run() {
    for(int i = 1; i <= m; i ++) if(a[i] == 1) return 0;
    sort(a + 1, a + m + 1);
    reverse(a + 1, a + m + 1);
    return doit(n, 1);
}

int main() {
    scanf("%I64d %d", &n, &m);
    for(int i = 1; i <= m; i ++) scanf("%d", a + i);
    printf("%I64d\n", run());
    return 0;
}