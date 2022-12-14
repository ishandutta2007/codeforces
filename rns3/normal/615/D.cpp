#include <bits/stdc++.h>
using namespace std;

const int M = 300001;
const int mod = 1e9 + 7;
int p[M];
int a[M];

int pw(int x, int y) {
    if(!y) return 1;
    int z = pw(x, y / 2);
    z = 1ll * z * z % mod;
    if(y & 1) return 1ll * x * z % mod;
    return z;
}


int sto[M], md[M], cnt;

int main() {
    //freopen("d.in", "r", stdin);
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d", &p[i]), sto[cnt ++] = p[i];
    sort(sto, sto + cnt);
    cnt = unique(sto, sto + cnt) - sto;
    for(int i = 1; i <= m; i ++) {
        int x = lower_bound(sto, sto + cnt, p[i]) - sto;
        a[x] ++;
    }
    int res = 1, tot = 0;
    for(int i = 0; i < cnt; i ++) {
        int x = a[i] + 1;
        while(x % 2 == 0) x /= 2, tot ++;
        res = 1ll * res * x % (mod - 1);
    }
    md[0] = 1;
    for(int i = 1; i < M; i ++) md[i] = md[i-1] * 2 % (mod - 1);
    int ans = 1;
    for(int i = 0; i < cnt; i ++) {
        int x = res;
        if(a[i] % 2 == 0) x = 1ll * (1ll * x * (a[i] / 2) ) % (mod - 1) * md[tot] % (mod - 1);
        else x  = 1ll * (1ll * x *  a[i] % (mod - 1)) * md[tot-1] % (mod - 1);
        ans = 1ll * ans * pw(sto[i], x) % mod;
    }
    cout << ans << endl;
}