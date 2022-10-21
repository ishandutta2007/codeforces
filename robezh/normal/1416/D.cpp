#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define lson(x) 2*x+1
#define rson(x) 2*x+2
const int N = (int)8e5 + 50;

struct qr {
    int tp, x, qv;
} qrs[N];

int n, m, q;
int val[N];
int del[N];
pii es[N];
int f[N];
vi G[N];
int tin[N], tout[N], ord[N], tim = 0;
int in[N];

int find(int i) {
    return f[i] == i ? i : f[i] = find(f[i]);
}

void dfs(int v) {
    ord[tim] = v;
    tin[v] = tim++;
    for(int nxt : G[v]) {
//        cout << v << " " << nxt << endl;
        dfs(nxt);
    }
    tout[v] = tim - 1;
}

struct Tree {
    pii dat[4 * N];
    void init(int x, int l, int r) {
        if(l == r) {
            int v = ord[l];
            dat[x] = (v < n ? pii{val[v], l} : pii{0, l});
            return ;
        }
        int mid = (l + r) / 2;
        init(lson(x), l, mid);
        init(rson(x), mid + 1, r);
        dat[x] = max(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r) {
        if(l == r) {dat[x] = {0, l}; return ;}
        int mid = (l + r) / 2;
        if(pos <= mid) update(pos, lson(x), l, mid);
        else update(pos, rson(x), mid + 1, r);
        dat[x] = max(dat[lson(x)], dat[rson(x)]);
    }

    pii query(int a, int b, int x, int l, int r) {
        if(r < a || b < l) return {-1, -1};
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        else return max(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid + 1, r));
    }
} tree;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    rep(i, 0, n) cin >> val[i];
    rep(i, 0, m) {
        cin >> es[i].first >> es[i].second;
        es[i].first--, es[i].second--;
    }
    for(int i = 0; i < N; i++) f[i] = i;
    rep(i, 0, q) {
        cin >> qrs[i].tp >> qrs[i].x;
        qrs[i].x--;
        if(qrs[i].tp == 2) {
            del[qrs[i].x] = 1;
        }
    }

//    cout << "good" << endl;

    int cn = n;
    rep(i, 0, m) {
        if(!del[i]) {
            int a  = es[i].first, b = es[i].second;
            a = find(a), b = find(b);
            if(a == b) continue;
            G[cn].push_back(a);
            G[cn].push_back(b);
            f[a] = f[b] = cn;
            cn++;
        }
    }
    for(int i = q - 1; i >= 0; i--) {
        if(qrs[i].tp == 1) {
            qrs[i].qv = find(qrs[i].x);
        } else {
            int a  = es[qrs[i].x].first, b = es[qrs[i].x].second;
            a = find(a), b = find(b);
            if(a == b) continue;
            G[cn].push_back(a);
            G[cn].push_back(b);
            f[a] = f[b] = cn;
            cn++;
        }
    }

//    cout << "good" << endl;
    for(int i = 0; i < cn; i++) {
        for(int nxt : G[i]) in[nxt]++;
    }
    for(int i = 0; i < cn; i++) {
        if(!in[i]) dfs(i);
    }
    tree.init(0, 0, cn - 1);
    for(int i = 0; i < q; i++) {
        if(qrs[i].tp == 1) {
            int v = qrs[i].qv;
            pii res = tree.query(tin[v], tout[v], 0, 0, cn - 1);
            tree.update(res.second, 0, 0, cn - 1);
            cout << res.first << '\n';
        }
    }


}