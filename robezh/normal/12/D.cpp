#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int N = (int)5e5 + 500, INF = (int)1e9 + 50;

struct P {
    int b, i, r;
} p[N];

int n;
int a[N], loc[N];

struct Tree {
    int dat[N * 4];

    void init_dat(){
        fill(dat, dat + N * 4, -1);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = max(dat[x], val);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = max(dat[lson(x)], dat[rson(x)]);
    }

    ll query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return -1;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        ll LHS = query(a, b, lson(x), l, mid);
        ll RHS = query(a, b, rson(x), mid+1, r);

        return max(LHS, RHS);
    }
} tree;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i].b;
    for(int i = 0; i < n; i++) cin >> p[i].i, a[i] = p[i].i;
    for(int i = 0; i < n; i++) cin >> p[i].r;
    tree.init_dat();
    sort(a, a + n);
    sort(p, p + n, [](const P &p1, const P &p2) {
        return p1.b > p2.b;
    });
    int r = 0;
    int res = 0;
    for(int i = 0; i < n; i = r) {
        while(r < n && p[i].b == p[r].b) r++;
        for(int j = i; j < r; j++) {
            loc[j] = (int)(upper_bound(a, a + n, p[j].i) - a);
            if(tree.query(loc[j], n - 1, 0, 0, n - 1) > p[j].r) res++;
        }
        for(int j = i; j < r; j++) {
            tree.update(loc[j] - 1, 0, 0, n - 1, p[j].r);
        }
    }
    cout << res << endl;
}