#include<bits/stdc++.h>
#define lson(x) x * 2 + 1
#define rson(x) x * 2 + 2

using namespace std;
const int N = 200500;

typedef long long ll;

struct P{
    int lb, color;
    P(){};
    P(int _lb, int _color){lb = _lb, color = _color;}
    bool operator < (const P &o) const{
        return lb == o.lb ? color < o.color : lb < o.lb;
    }
//    bool operator > (const P &o) const{
//        return lb == o.lb ? color > o.color : lb > o.lb;
//    }
};

int n,m;
map<int, P> mp;

ll add[4*N], sum[4*N];

void push_down(int x, int l, int r) {
    int mid = (l + r) / 2;

    sum[lson(x)] += add[x] * (mid - l + 1);
    sum[rson(x)] += add[x] * (r - mid);

    add[lson(x)] += add[x];
    add[rson(x)] += add[x];

    add[x] = 0;
}

ll query(int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    if(l < r && add[x]) push_down(x, l, r);

    if(l >= a && r <= b) return sum[x];

    ll LHS = query(a, b, lson(x), l, mid);
    ll RHS = query(a, b, rson(x), mid+1, r);
    return (LHS + RHS);
}

void update(int a, int b, int x, int l, int r, int val) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;

    if(l < r && add[x]) push_down(x, l, r);

    if(l >= a && r <= b) {
        sum[x] += 1LL * (r - l + 1) * val;
        add[x] += val;
        return ;
    }

    update(a, b, lson(x), l, mid, val);
    update(a, b, rson(x), mid+1, r, val);

    sum[x] = (sum[lson(x)] + sum[rson(x)]);
}

void update(int l, int r, int val){
    update(l, r, 0, 0, n-1, val);
}

ll query(int l, int r){
    return query(l, r, 0, 0, n-1);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) mp[i] = {i, i+1};
    while(m--){
        int type;
        scanf("%d", &type);
        if(type == 1){
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            l--, r--;
            for(auto it = mp.lower_bound(l); it != mp.end();){
                int lb = it->second.lb, rb = it->first, color = it->second.color;
                if(lb > r) break;
                it = mp.erase(it);
                if(lb <= l - 1) mp[l - 1] = {lb, color};
                if(rb >= r + 1) mp[rb] = {r + 1, color};
                lb = max(l, lb), rb = min(r, rb);
                update(lb, rb, abs(x - color));
            }
            mp[r] = {l, x};
        }
        else{
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            printf("%I64d\n", query(l, r));
        }
    }
}