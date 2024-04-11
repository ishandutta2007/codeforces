#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
//#include <set>
//#include <>
#include <map>

#define ll long long int
#define FOR(a, b) for (int a = 0; a < b; a++)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
const int INF = 1000000000;
const double EPS = 0.000000001;

struct tr {
    bool u;
    int l,r;
    int a1, a2;
    int diff;
};


tr tree[2*100000*10];
char sex[2*100000*10];
int level[2*100000*10];

int n, N;

void relax(int v) {
    tr & pv = tree[v];
    tr & pl = tree[2*v];
    tr & pr = tree[2*v+1];

    if (pl.u) {pv = pr; return;}
    if (pr.u) {pv = pl; return;}

    pv.l = pl.l; pv.r = pr.r;
    int d = INF, a1, a2;

    if (pl.diff<d) {d = pl.diff; a1=pl.a1; a2=pl.a2;}

    int tl = pl.r, tr = pr.l; //left and right in pair
    if (sex[tl]!=sex[tr]) {
        int tmp = abs(level[tl]-level[tr]);
        if (tmp<d) {d = tmp; a1=tl; a2=tr;}
    }

    if (pr.diff<d) {d = pr.diff; a1=pr.a1; a2=pr.a2;}

    pv.diff = d; pv.a1 = a1; pv.a2 = a2;
}

void build() {
    N=1; while (N<n) N*=2; N-=1;
    for (int i=N+1; i<2*100000*10; ++i) {tree[i].u = 1; tree[i].diff=INF;}
    for (int i=N; i>n; --i) tree[N+i].u = 1;
    for (int i=n; i>0; --i) {
        tree[N+i].u = 0;
        tree[N+i].l = i; tree[N+i].r = i;
        tree[N+i].diff = INF;
    }
    for (int i=N; i>0; --i) relax(i);
}

void set(int v) {
    v += N;
    tree[v].u = 1;
    v /= 2;
    while (v>0) {
        relax(v);
        v /= 2;
    }
}

int ans[2][1000000];
int ak=0;

int main()
{
    cin >> n;
    for( int i =1; i<=n; ++i) cin >> sex[i];
    for( int i =1; i<=n; ++i) cin >> level[i];
    build();

/*    for (int i=1; i<=N+N+n; ++i) {
        cerr << i<< " : ";
        fprintf(stderr, "u=%d; l=%d; r=%d; diff=%d\n", tree[i].u, tree[i].l, tree[i].r, tree[i].diff);
    }*/

    while (tree[1].diff<INF) {
        int a1 = tree[1].a1, a2 = tree[1].a2;
        ans[0][ak] = a1;
        ans[1][ak] = a2;
        ++ ak;
        set(a1); set(a2);
    }

    cout << ak << "\n";
    FOR(i, ak) printf("%d %d\n", ans[0][i], ans[1][i]);
    return 0;
}