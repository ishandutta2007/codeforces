#include<bits/stdc++.h>
using namespace std;
#define N 5555
int a[N], b[N], f[N], ans[N];
int n, w, h;
int cnt, sto[N];
bool chk(int i, int j) {
    if(a[i] < a[j] && b[i] < b[j]) return 1;
    return 0;
}
int get(int x) {
    if(f[x]) return f[x];
    f[x] = 1;
    for(int i = 0; i < n; i ++) if(chk(i, x)){
        if(a[i] <= w || b[i] <= h)continue;
        get(i);
        f[x] = max(f[x], f[i] + 1);
        if(f[x] == f[i] + 1) ans[x + 1] = i + 1;
    }
    return f[x];
}
int main() {
    //freopen("D.in","r", stdin);
    scanf("%d%d%d", &n, &w, &h);
    for(int i = 0; i < n; i ++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for(int i = 0; i < n; i ++) {
        if(a[i] > w && b[i] > h ) get(i);
    }
    int po = 0, mx = -1;
    for(int i = 0; i < n; i ++) {
        mx = max(mx, f[i]);
        if(mx == f[i]) po = i + 1;
    }
    printf("%d\n", mx);
    while(po) {
        sto[cnt ++] = po;
        po = ans[po];
    }
    if(mx)for(int i = cnt - 1; i >= 0; i --) printf("%d ", sto[i]);
    puts("");
    return 0;
}