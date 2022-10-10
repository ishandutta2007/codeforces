#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 2e5 + 10;
int fl[MAXN], id_r[2 * MAXN], id_l[2 * MAXN], cnt[MAXN], le[MAXN], ri[MAXN], cl[MAXN], touch[MAXN];
int col_cnt[2];

vector<ii> adj[MAXN];

struct seg {
    int l, r;
    seg(int _l, int _r) : l(_l), r(_r) {}
};

void dfs(int s, int x = 0) {
    col_cnt[x]++;
    cl[s] = x;
    for(auto &[v, y] : adj[s]) {
        if(cl[v] == -1)
            dfs(v, x ^ y);
        else {
            if(cl[v] != (x ^ y)) {
                cout << "-1\n";
                exit(0);
            }
        }
    }
}

struct node {
    int l, r, v;
    node *left, *right;

    node(int _l, int _r) : l(_l), r(_r), v(0) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, int _v) {
        if(r < p || p < l)
            return;
        if(l == r) {
            v = _v;
            return;
        }
        left->upd(p, _v);
        right->upd(p, _v);
        v = max(left->v, right->v);
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl)
            return 0;
        if(rl <= l && r <= rr)
            return v;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<seg> segs;
    int max_l = 0, min_r = 2 * n + 1;

    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if(l > r) {
            swap(l, r);
            fl[i + 1] = 1;
        }
        segs.push_back({l, r});
        max_l = max(max_l, l);
        min_r = min(min_r, r);
        id_r[r] = i + 1;
        id_l[l] = i + 1;
        le[i + 1] = l;
        ri[i + 1] = r;
    }

    if(min_r < max_l) {
        cout << "-1\n";
        return 0;
    }

    sort(segs.begin(), segs.end(), [&](seg a, seg b) { return a.r > b.r; });
    node tree(1, 2 * n);
    for(auto &[l, r] : segs) {
        //cout << "testing guy at r = " << r << endl;
        int id = id_l[l];
        //cout << "testing segment [" << l << ", " << r << "]" << endl;
        int x = tree.qry(l, r);
        while(x != 0) {
            //cout << "found guy " << 3 * n + 5 - x << endl;
            int id2 = id_l[3 * n + 5 - x];
            if(cnt[id2]) {
                cout << "-1\n";
                return 0;
            }
            int xo = fl[id] ^ fl[id2] ^ 1;
            adj[id].push_back({id2, xo});
            adj[id2].push_back({id, xo});
            if(touch[id2])
                break;
            touch[id2] = 1;
            //cout << id << " " << id2 << " " << xo << endl;
            cnt[id]++;
            x = tree.qry(le[id2] + 1, r);
        }
        tree.upd(l, 3 * n + 5 - l);
    }
    for(int i = 1; i <= 2 * n; i++)
        tree.upd(i, 0);
    memset(cnt, 0, sizeof cnt);
    memset(touch, 0, sizeof touch);
    sort(segs.begin(), segs.end(), [&](seg a, seg b) { return a.l < b.l; });
    for(auto &[l, r] : segs) {
        int id = id_l[l];
        int x = tree.qry(l, r);
        while(x != 0) {
            int id2 = id_r[x];
            if(cnt[id2]) {
                cout << "-1\n";
                return 0;
            }
            int xo = fl[id] ^ fl[id2] ^ 1;
            adj[id].push_back({id2, xo});
            adj[id2].push_back({id, xo});
            if(touch[id2])
                break;
            touch[id2] = 1;
            //cout << id << " " << id2 << " " << xo << endl;
            cnt[id]++;
            x = tree.qry(l, ri[id2] - 1);
        }
        tree.upd(r, r);
    }

    int ans = 0;
    memset(cl, -1, sizeof cl);
    for(int i = 1; i <= n; i++) {
        if(cl[i] != -1)
            continue;
        col_cnt[0] = col_cnt[1] = 0;
        dfs(i);
        ans += min(col_cnt[0], col_cnt[1]);
    }

    cout << ans << '\n';
}