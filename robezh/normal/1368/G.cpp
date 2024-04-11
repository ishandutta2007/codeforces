#include <bits/stdc++.h>
using namespace std;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

const int INF = (int)1e9;

struct node {
    int mn, add, cnt;

    void add_val(int x) {
        mn += x;
        add += x;
    }
};

node merge(node ls, node rs) {
    node res;
    res.mn = min(ls.mn, rs.mn);
    res.add = 0;
    res.cnt = (ls.mn == res.mn ? ls.cnt : 0) + (rs.mn == res.mn ? rs.cnt : 0);
    return res;
}

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].add);
                dat[rs(x)].add_val(dat[x].add);
            }
            dat[x].add = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x] = {0, 0, 1};
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x] = merge(dat[ls(x)], dat[rs(x)]);
    }

    node query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return {INF, 0, 0};

        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x];
        return merge(query(a, b, ls(x), l, mid), query(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);
        if(l >= a && r <= b) {
            dat[x].add_val(delta);
            return ;
        }
        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);
        dat[x] = merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

int n, m;
int cnt = 0;
string str[N];
vector<vi> lab;
vi G[2][N];
int tin[N], tout[N], tim = 0;
int vis[2][N];
int in[2][N];
ll res = 0;

pii getnxt(int i, int j) {
    if(str[i][j] == 'U') return {i + 2, j};
    else if(str[i][j] == 'D') return {i - 2, j};
    else if(str[i][j] == 'L') return {i, j + 2};
    else return {i, j - 2};
}

bool in_bound(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void construct(int v) {
    vis[1][v] = 1;
    tin[v] = tim++;
    for(int nxt : G[1][v]) construct(nxt);
    tout[v] = tim - 1;
}

void dfs(int v) {
    vis[0][v] = 1;
    tree.update(tin[v], tout[v], 0, 0, cnt - 1, 1);
    node qr = tree.query(0, cnt - 1, 0, 0, cnt - 1);
    res += cnt - (qr.mn == 0 ? qr.cnt : 0);
//    cout << qr.cnt << endl;
    for(int nxt : G[0][v]) {
        dfs(nxt);
    }
    tree.update(tin[v], tout[v], 0, 0, cnt - 1, -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, n) cin >> str[i];

    lab = vector<vi> (n, vi(m, -1));
    rep(i, 0, n) rep(j, 0, m) {
        if(lab[i][j] == -1) {
            int ni = (str[i][j] == 'U' ? i + 1 : str[i][j] == 'D' ? i - 1 : i);
            int nj = (str[i][j] == 'L' ? j + 1 : str[i][j] == 'R' ? j - 1 : j);
            lab[i][j] = lab[ni][nj] = cnt++;
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            pii nxt = getnxt(i, j);
            if(in_bound(nxt.first, nxt.second)) {
                G[(i + j) % 2][lab[nxt.first][nxt.second]].push_back(lab[i][j]);
                in[(i + j) % 2][lab[i][j]]++;
//                cout << "adding " << endl;
            }
        }
    }
    tree.init(0, 0, cnt - 1);

    rep(i, 0, cnt) if(!in[1][i]) construct(i);
    rep(i, 0, cnt) if(!in[0][i]) dfs(i);
//    cout << cnt << " " << tim << endl;
//    for(int i = 0; i < cnt; i++) cout << i << ": " << tin[i] << ", " << tout[i] << endl;
    cout << res << '\n';
}