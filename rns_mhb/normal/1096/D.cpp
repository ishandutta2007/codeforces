#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1ll<<60;

#define N 100010

ll val[N<<2][4][4];
int n, a[N];
char s[N], p[10] = "hard";

ll calc(int v, int l, int r, int L, int R) {
    if(val[v][L][R] < INF) return val[v][L][R];
    if(l == r) {
        val[v][L][R] = 0;
        if(L < R) return 0;
        if(s[l] == p[L]) val[v][L][R] = a[l];
        return val[v][L][R];
    }
    int mid = l + r >> 1;
    ll ret = INF;
    for(int k = L; k <= R; k ++) {
        ll cur = calc(v<<1, l, mid, L, k) + calc(v<<1|1, mid+1, r, k, R);
        if(cur < ret) ret = cur;
    }
    val[v][L][R] = ret;
    return ret;
}

int main() {
    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n * 4; i ++)
        for(int j = 0; j < 4; j ++)
            for(int k = 0; k < 4; k ++) val[i][j][k] = INF;
    printf("%I64d\n", calc(1, 1, n, 0, 3));
}