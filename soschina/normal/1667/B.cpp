#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#define le (i << 1)
#define ri (i << 1 | 1)
using namespace std;
const int N = 5e5 + 2, INF = 0x3f3f3f3f;

int t, n, m;
long long a[N], tmp[N];

int ansa[N];

int tree[2][N << 2];
void build(int i, int l, int r){
    tree[0][i] = tree[1][i] = -INF;
    if(l == r){
        ansa[l] = -INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(le, l, mid);
    build(ri, mid + 1, r);
}

int P, Kl, Kr;
void insert(int i, int l, int r){
    if(l == r){
        tree[0][i] = max(tree[0][i], Kl);
        tree[1][i] = max(tree[0][i], Kr);
        return;
    }
    int mid = (l + r) >> 1;
    if(mid >= P)
        insert(le, l, mid);
    else
        insert(ri, mid + 1, r);
    tree[0][i] = max(tree[0][le], tree[0][ri]);
    tree[1][i] = max(tree[1][le], tree[1][ri]);
}

int L, R;
int query(int *tree, int i, int l, int r){
    if(l >= L && r <= R)
        return tree[i];
    int mid = (l + r) >> 1, ret = -INF;
    if(mid >= L)
        ret = max(ret, query(tree, le, l, mid));
    if(mid < R)
        ret = max(ret, query(tree, ri, mid + 1, r));
    return ret;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        a[0] = tmp[0] = 0;
        for (int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            a[i] += a[i - 1];
            tmp[i] = a[i];
        }
        sort(tmp, tmp + 1 + n);
        int m = unique(tmp, tmp + 1 + n) - tmp;
        for (int i = 0; i <= n; i++)
            a[i] = lower_bound(tmp, tmp + m, a[i]) - tmp + 1;
        build(1, 1, m);
        P = a[0], Kl = 0, Kr = 0;
        insert(1, 1, m);
        ansa[a[0]] = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++){
            ans = ansa[a[i]];
            L = 1, R = a[i] - 1;
            if(L <= R){
                ans = max(ans, query(tree[0], 1, 1, m) + i);
            }
            L = a[i] + 1, R = m;
            if(L <= R){
                ans = max(ans, query(tree[1], 1, 1, m) - i);
            }
            P = a[i];
            Kl = ans - i;
            Kr = ans + i;
            insert(1, 1, m);
            ansa[a[i]] = max(ansa[a[i]], ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}