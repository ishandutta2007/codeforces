#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 500, mod = (int)1e9 + 7;

int n;
int a[N];

struct node {
    int sum, mxpre, mnpre, mxsuf, mnsuf;
};

node merge(node l, node r) {
    return {l.sum + r.sum, max(l.mxpre, l.sum + r.mxpre), min(l.mnpre, l.sum + r.mnpre),
            max(r.mxsuf, l.mxsuf + r.sum), min(r.mnsuf, l.mnsuf + r.sum)};
}



struct Tree {
    node dat[N * 4];

    void init_dat(int l, int r, int x){
        if(l == r){
            dat[x] = {1,1, 0, 1, 0};
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
//        cout << x << " " << dat[x].mxsuf << endl;
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = {val, max(0, val), min(0, val), max(0, val), min(0, val)};
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, 0, 0, 0, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        return merge(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
    }
} tree;


vi pos[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        int x; cin >> x; pos[x].push_back(i);
    }
    tree.init_dat(0, n - 1, 0);
//    cout << tree.dat[0].mxsuf << endl;
    rep(v, 1, n + 1) {
        for(int idx : pos[v]) {
            node ql = tree.query(0, idx - 1, 0, 0, n - 1);
            node qr = tree.query(idx + 1, n - 1, 0, 0, n - 1);
//            cout << idx << " " << ql.mxsuf << endl;
            res[idx] = max((-ql.mnsuf - qr.mnpre) / 2, (ql.mxsuf + qr.mxpre + 1) / 2);
        }
        for(int idx : pos[v]) {
            tree.update(idx, 0, 0, n - 1, -1);
        }
        for(int idx : pos[v]) {
            node ql = tree.query(0, idx - 1, 0, 0, n - 1);
            node qr = tree.query(idx + 1, n - 1, 0, 0, n - 1);
            res[idx] = max(res[idx], max((-ql.mnsuf - qr.mnpre) / 2, (ql.mxsuf + qr.mxpre + 1) / 2));
        }
    }
    rep(i, 0, n) cout << res[i] << " ";
    cout << '\n';




}