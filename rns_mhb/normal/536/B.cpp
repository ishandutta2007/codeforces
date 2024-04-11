#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
#define N 1000005

char s[N];
int x[N], p[N], tree[N], ls, n;

void prepare() {
    for(int i = 2, k = 0; i <= ls; i ++) {
        while(k && s[i] != s[k + 1]) k = p[k];
        if(s[i] == s[k + 1]) k ++;
        p[i] = k;
    }
}

void update(int i, int val) {for(;i <= n; i += i & -i) tree[i] += val;}

bool query(int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += tree[i];
    return ret;
}

int main() {
    int m, i, k, ans = 1;
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    ls = strlen(s + 1);
    prepare();
    for(i = 1; i <= m; i ++) scanf("%d", x + i);
    sort(x + 1, x + m + 1);
    for(i = m - 1; i; i --) {
        if(x[i] + ls <= x[i + 1]) continue;
        k = ls;
        while(k > x[i] - x[i + 1] + ls) k = p[k];
        if(k != x[i] - x[i + 1] + ls) break;
    }
    if(i > 0) {puts("0"); return 0;}
    for(i = 1; i <= m; i ++) update(x[i], 1), update(x[i] + ls, -1);
    for(i = 1; i <= n; i ++) if(!query(i)) ans = 26ll * ans % mod;
    printf("%d", ans);
}