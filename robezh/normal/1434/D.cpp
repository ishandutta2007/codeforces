#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = (int)1e9;

const int N = (int)1e6 + 50;

struct edge {
    int to, w, id;
};

int n, m;
vector<edge> G[N];

struct node {
    int cr;
    int mx[2];

    void flip() {
        cr ^= 1;
        swap(mx[0], mx[1]);
    }

    void merge(node &ls, node &rs) {
        rep(p, 0, 2) mx[p] = max(ls.mx[p], rs.mx[p]);
    }
};

struct Tree {
    node dat[4 * N];
    int root;
    int tin[N], tout[N], tim = 0;
    int nid[N], pr[N];
    int dep[N];

    void dfs(int v, int p, int d, int depth) {
        pr[tim] = d;
        dep[tim] = depth;
        tin[v] = tim++;
        for(auto e : G[v]) {
            if(e.to == p) continue;
            nid[e.id] = e.to;
            dfs(e.to, v, d ^ e.w, depth + 1);
        }
        tout[v] = tim - 1;
    }

    void push_down(int x, int l, int r) {
        if(dat[x].cr) {
            if(l < r) {
                dat[ls(x)].flip();
                dat[rs(x)].flip();
            }
            dat[x].cr = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x] = pr[l] ? node{0, {0, dep[l]}} :
                    node{0, {dep[l] , 0}};
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
//        cout << x << " " << l << " " << r << ": " << dat[x].abmax << endl;
    }

    void update(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].flip();
            return ;
        }

        update(a, b, ls(x), l, mid);
        update(a, b, rs(x),mid+1, r);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void update(int eid) {
        update(tin[nid[eid]], tout[nid[eid]], 0, 0, n - 1);
    }

} tree[2];



pii dfs(int v, int p) {
    pii res = {0, v};
    for(auto e : G[v]) {
        if(e.to != p) {
            pii nxt = dfs(e.to, v);
            res = max(res, {nxt.first + 1, nxt.second});
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        G[a].push_back({b, w, i});
        G[b].push_back({a, w, i});
    }
    pii p = dfs(0, -1);
    tree[0].root = p.second;
    p = dfs(p.second, -1);
    tree[1].root = p.second;

//    cout << "?" << endl;

    rep(it, 0, 2) {
        tree[it].dfs(tree[it].root, -1, 0, 0);
        tree[it].init(0, 0, n - 1);
    }
//    cout << "?" << endl;
    cin >> m;
//    cout << tree.dat[0].abmax << " " <<  tree.dat[0].abmax_pre[0] << " " <<  tree.dat[0].abmax_suf[0] << '\n';

    rep(i, 0, m) {
        int id; cin >> id; id--;
        tree[0].update(id);
        tree[1].update(id);
        cout << max(tree[0].dat[0].mx[0], tree[1].dat[0].mx[0]) << '\n';
    }

}