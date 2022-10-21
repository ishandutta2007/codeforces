#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define lson(x) 2*x+1
#define rson(x) 2*x+2
const int N = 11, M = (int)1e5 + 50;

int n, m, q;
int a[N][M];

struct node {
    int L[10], R[10];
    int cnt, bc;
};

int f[4 * N];
int find(int i) {return f[i] == i ? i : f[i] = find(f[i]);}
int unite(int i, int j) {
    i = find(i), j = find(j);
    if(i == j) return 0;
    f[find(i)] = find(j);
    return 1;
}
int mp[4 * N];

node merge(node ls, node rs, int mid) {
    if(ls.cnt == 0) return rs;
    if(rs.cnt == 0) return ls;
    node res;
    res.cnt = ls.cnt + rs.cnt;
    for (int i = 0; i < n; i++) {
        rs.R[i] += ls.bc;
        rs.L[i] += ls.bc;
    }
    for (int i = 0; i < ls.bc + rs.bc; i++) f[i] = i;
    for (int i = 0; i < n; i++) {
        if(a[i][mid] == a[i][mid + 1]) res.cnt -= unite(ls.R[i], rs.L[i]);
    }
    res.bc = 0;
    memset(mp, -1, sizeof(mp));
    for (int i = 0; i < n; i++) {
        int c = find(ls.L[i]);
        if (mp[c] == -1) mp[c] = res.bc++;
        res.L[i] = mp[c];
    }
    for (int i = 0; i < n; i++) {
        int c = find(rs.R[i]);
        if (mp[c] == -1) mp[c] = res.bc++;
        res.R[i] = mp[c];
    }

    return res;
}

struct Tree {
    node dat[4 * M];
    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].bc = 0;
            for(int i = 0; i < n; i++) {
                if(i == 0 || a[i - 1][l] != a[i][l]) dat[x].R[i] = dat[x].L[i] = dat[x].bc++;
                else dat[x].R[i] = dat[x].L[i] = dat[x].L[i - 1];
            }
            dat[x].cnt = dat[x].bc;
            return ;
        }
        int mid = (l + r) / 2;
        init(lson(x), l, mid);
        init(rson(x), mid + 1, r);
        dat[x] = merge(dat[lson(x)], dat[rson(x)], mid);
    }

    node query(int a, int b, int x, int l, int r) {
        if(r < a || b < l) return node{{}, {}, 0, 0};
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        else return merge(query(a, b, lson(x), l, mid),
                          query(a, b, rson(x), mid + 1, r), mid);
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

//    memset(mp, -1, sizeof(mp));
//    cout << node{{}, {}, 0, 0}.cnt << endl;
    cin >> n >> m >> q;
    rep(i, 0, n) {
        rep(j, 0, m) cin >> a[i][j];
    }
    tree.init(0, 0, m - 1);
    rep(i, 0, q) {
        int l, r; cin >> l >> r; l--, r--;
        cout << tree.query(l, r, 0, 0, m - 1).cnt << '\n';
    }

}