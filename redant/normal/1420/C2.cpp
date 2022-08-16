#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 300005;
const LL INF = 1e18;

struct Node {
    LL r[2][2];
    Node() {
        r[0][0]=r[0][1]=r[1][0]=r[1][1]=-INF;
    }
};


const Node none;
int n, q;
int a[SZ];
Node st[2 * SZ];

Node combine(Node a, Node b) {
    Node p;
    REP(i, 2)
        REP(j, 2) {
            p.r[i][j] = max(a.r[i][j], b.r[i][j]);
            REP(k, 2)
                p.r[i][j] = max(p.r[i][j], a.r[i][k] + b.r[1-k][j]);
        }
    return p;
}

void build(int i, int l, int r) {
    if (l == r) {
        st[i] = Node();
        st[i].r[1][1]=a[l];
        st[i].r[0][0]=-a[l];
        return;
    }

    int m = (l + r) >> 1;
    int li = i + 1, ri = i + 2 * (m - l + 1);
    build(li, l, m);
    build(ri, m+1, r);

    st[i] = combine(st[li], st[ri]);
}

void update(int i, int l, int r, int from, int to) {
    if (from > to || to < l || r < from) {
        return;
    }
    if (l == from && r == to) {
        st[i].r[1][1]=a[l];
        st[i].r[0][0]=-a[l];
        return;
    }
    int m = (l + r) >> 1;
    int li = i + 1, ri = i + 2 * (m - l + 1);
    update(li, l, m, from, min(m, to));
    update(ri, m+1, r, max(from, m+1), to);
    st[i] = combine(st[li], st[ri]);
}

LL solve() {
   return max(st[1].r[1][0], st[1].r[1][1]);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>q;
        REP(i, n) {
            cin>>a[i+1];
        }
        build(1, 1, n);
        cout<<solve()<<"\n";
        while(q--) {
            int x, y;
            cin>>x>>y;
            swap(a[x], a[y]);
            update(1, 1, n, x, x);
            update(1, 1, n, y, y);
            cout<<solve()<<"\n";
        }
    }
    
    return 0;
}