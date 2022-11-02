#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#define set _set

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

struct tr{
    ll val, add;
    int l, r;
};

int maxv;
tr rmq[600600];

inline void push(int v){
    rmq[v].val += rmq[v].add * (rmq[v].r - rmq[v].l + 1);
    if(v < maxv){
        rmq[v * 2].add += rmq[v].add;
        rmq[v * 2 + 1].add += rmq[v].add;
    }
    rmq[v].add = 0;
}

inline void calc(int v){
    rmq[v].val = rmq[v * 2].val + rmq[v * 2 + 1].val;
}

void update(int v, int l, int r, ll add){
    push(v);
    if(rmq[v].l > r || rmq[v].r < l){
        return;
    }
    if(rmq[v].l >= l && rmq[v].r <= r){
        rmq[v].add += add;
        push(v);
        return;
    }
    update(v * 2, l, r, add);
    update(v * 2 + 1, l, r, add);
    calc(v);
}

void set(int v, int p, ll val){
    push(v);
    if(rmq[v].l > p || rmq[v].r < p){
        return;
    }
    if(v >= maxv){
        rmq[v].val = val;
        return;
    }
    set(v * 2, p, val);
    set(v * 2 + 1, p, val);
    calc(v);
}

ll get(int v, int l, int r){
    push(v);
    if(rmq[v].l > r || rmq[v].r < l){
        return 0;
    }
    if(rmq[v].l >= l && rmq[v].r <= r){
        return rmq[v].val;
    }
    return get(v * 2, l, r) + get(v * 2 + 1, l, r);
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    maxv = 1;
    while(maxv < n + 1){
        maxv *= 2;
    }
    for(int i = 0; i < maxv; i++){
        rmq[i + maxv].l = rmq[i + maxv].r = i;
    }
    for(int i = maxv - 1; i > 0; i--){
        rmq[i].l = rmq[i * 2].l;
        rmq[i].r = rmq[i * 2 + 1].r;
    }
    int sz = 1;
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d", &t);
        if(t == 1){
            int x, a;
            scanf("%d %d", &a, &x);
            update(1, 0, a - 1, x);
        }
        if(t == 2){
            int x;
            scanf("%d", &x);
            set(1, sz++, x);
        }
        if(t == 3){
            sz = max(sz - 1, 1);
        }
        double res = double(get(1, 0, sz - 1)) / sz;
        printf("%.18lf\n", res);
    }
    return 0;
}