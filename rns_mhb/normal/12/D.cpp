#include<bits/stdc++.h>
using namespace std;

#define N 500010
#define INF 1e9

template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}

struct lady{
    int b, i, r;
    bool operator < (const lady &f) const {return b < f.b;}
} f[N];

int tree[N];
int n, ans;

void update(int x, int y) {
    for(; x <= n + 2; x += x & -x) chkmin(tree[x], y);
}

bool query(int x, int y) {
    for(; x; x -= x & -x) if(tree[x] <= y) return 1;
    return 0;
}

map<int, int> prs;
int a[N];

void press() {
    a[0] = -1;
    for(int i = 1; i <= n; i ++) a[i] = f[i].b;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) if(a[i] != a[i - 1]) prs[a[i]] = i;
    for(int i = 1; i <= n; i ++) f[i].b = n + 2 - prs[f[i].b];
    prs.clear();
    for(int i = 1; i <= n; i ++) a[i] = f[i].i;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) if(a[i] != a[i - 1]) prs[a[i]] = i;
    for(int i = 1; i <= n; i ++) f[i].i = n + 2 - prs[f[i].i];
    prs.clear();
    for(int i = 1; i <= n; i ++) a[i] = f[i].r;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) if(a[i] != a[i - 1]) prs[a[i]] = i;
    for(int i = 1; i <= n; i ++) f[i].r = n + 2 - prs[f[i].r];
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &f[i].b);
    for(int i = 1; i <= n; i ++) scanf("%d", &f[i].i);
    for(int i = 1; i <= n; i ++) scanf("%d", &f[i].r);
    press();
    sort(f + 1, f + n + 1);
    fill(tree, tree + n + 4, INF);
    for(int i = 1, j, k; i <= n; i = j) {
        j = i;
        while(f[i].b == f[j].b && j <= n) j ++;
        for(k = i; k < j; k ++) if(query(f[k].i - 1, f[k].r - 1)) ans ++;
        for(k = i; k < j; k ++) update(f[k].i, f[k].r);
    }
    printf("%d\n", ans);
}