#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1ll << 60;

bool chtq;
struct Line {
    mutable ll a, b, p;
    bool operator<(const Line& o) const {return chtq ? p < o.p : a < o.a;}
};

struct CHT : multiset<Line> {
    ll div(ll x, ll y) {return x / y - ((x ^ y) < 0 && x % y);}
    bool isect(iterator x, iterator y) {
        if(y == end()) {x->p = INF; return 0;}
        if(x->a == y->a) x->p = x->b > y->b ? INF : -INF;
        else x->p = div(y->b - x->b, x->a - y->a);
        return x->p >= y->p;
    }
    void add(ll a, ll b) {
        auto z = insert({a, b, 0}), y = z++, x = y;
        while(isect(y, z)) z = erase(z);
        if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        chtq = 1; auto L = *lower_bound({0,0,x}); chtq = 0;
        return L.a * x + L.b;
    }
};

int n, a[100010];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    CHT H;
    ll ans = 0;
    for(int i = 1, b; i < n; i ++) {
        scanf("%d", &b);
        H.add(-b, -ans);
        ans = -H.query(a[i+1]);
    }
    printf("%I64d\n", ans);
}