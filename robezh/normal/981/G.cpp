#include<bits/stdc++.h>
#define lson(x) x * 2 + 1
#define rson(x) x * 2 + 2

using namespace std;

typedef long long ll;
const int N = 200500, mod = 998244353;

int n,q;
ll mul[4*N], add[4*N], sum[4*N];
map<int, int> M[N];

void push_down(int x, int l, int r) {
    int mid = (l + r) / 2;

    sum[lson(x)] = (sum[lson(x)] * mul[x] + add[x] * (mid - l + 1)) % mod;
    sum[rson(x)] = (sum[rson(x)] * mul[x] + add[x] * (r - mid)) % mod;
    mul[lson(x)] = mul[lson(x)] * mul[x] % mod;
    mul[rson(x)] = mul[rson(x)] * mul[x] % mod;
    add[lson(x)] = (add[lson(x)] * mul[x] + add[x]) % mod;
    add[rson(x)] = (add[rson(x)] * mul[x] + add[x]) % mod;

    mul[x] = 1; add[x] = 0;
}

ll query(int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    if(l < r) push_down(x, l, r);

    if(l >= a && r <= b) return sum[x];

    ll LHS = query(a, b, lson(x), l, mid);
    ll RHS = query(a, b, rson(x), mid+1, r);
    return (LHS + RHS) % mod;
}

void update(int a, int b, int x, int l, int r, int type) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;

    if(l < r) push_down(x, l, r);

    if(l >= a && r <= b) {
        if(type == 1){
            sum[x] = (sum[x] + r - l + 1) % mod;
            add[x] = (add[x] + 1) % mod;
        }
        else{
            sum[x] = (sum[x] * 2) % mod;
            mul[x] = (mul[x] * 2) % mod;
        }
        return ;
    }

    update(a, b, lson(x), l, mid, type);
    update(a, b, rson(x), mid+1, r, type);

    sum[x] = (sum[lson(x)] + sum[rson(x)]) % mod;
}

void update(int l, int r, int type){
    update(l, r, 0, 0, n-1, type);
}

void upd(int x, int l, int r){
    auto &mp = M[x];
    auto it = mp.lower_bound(l);

    int las = l - 1;
    for(; it != mp.end();){
        int nl = it -> second, nr = it -> first;
        if(nl > r) break;
        it = mp.erase(it);
        if(nl <= l - 1) mp[l - 1] = nl; if(nr >= r + 1) mp[nr] = r + 1;

        if(las+1 <= nl-1) update(las + 1, nl-1, 1);
        nr = min(r, nr), nl = max(l, nl);
        update(nl, nr, 2);
        las = nr;
    }
    if(las+1 <= r)  update(las+1, r, 1);
    mp[r] = l;
}

int main() {
    fill(mul, mul+4*N, 1);
    scanf("%d%d", &n, &q);
    while(q--){
        int t, l, r, x;
        scanf("%d%d%d", &t, &l, &r);
        l--, r--;
        if(t == 1){
            scanf("%d", &x);
            upd(x, l, r);
        }
        else{
            printf("%I64d\n", query(l, r, 0, 0, n-1));
        }
    }
}